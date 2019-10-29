//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_717_H
#define LEETCODE_717_H
#include "Common.h"
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int length = bits.size();
        int i = 0;
        int currentIs0 = false;
        while(i<length){
            if(bits[i]==1){
                i=i+2;
                currentIs0 = false;
            }else{
                i = i+1;
                currentIs0 = true;
            }
        }
        return i == length && currentIs0;
    }
};
#endif //LEETCODE_717_H
