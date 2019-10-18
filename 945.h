//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_945_H
#define LEETCODE_945_H
#include "Common.h"
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int result = 0;
        int length = A.size();
        if (length < 1) {
            return 0;
        }
        int last = A[0];
        int sameCount = 1;
        for (int i = 1; i < length; i++) {
            if (A[i] == last) {
                sameCount++;
            } else {
                if (sameCount > 1) {
                    int subNum = A[i]-last;
                    if (subNum> 1) {
                        int fillNum = min(sameCount-1,subNum-1);

                        result+= (1+fillNum)*fillNum/2;
                        result+= (sameCount-fillNum-1)*(subNum);
                        sameCount-=fillNum;
                        last= A[i];
                    } else {
                        result += (subNum) * (sameCount - 1);
                        last = A[i];

                    }
                }else{
                    last = A[i];
                }
            }
        }
        if(sameCount>1){
            result+=(sameCount)*(sameCount-1)/2;
        }
        return result;
    }
};
#endif //LEETCODE_945_H
