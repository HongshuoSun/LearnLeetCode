//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_1099_H
#define LEETCODE_1099_H
#include "Common.h"
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int result = K+1;
        int length = A.size();
        if(length<=1){
            return -1;
        }
        int i=0,j=length-1;
        while(i<j)
        {
            int sum = A[i]+A[j];
            if(sum<K){
                result = sum;
                i++;
            }else{
                j--;
            }
        }
        return result<K?result:-1;
    }
};
#endif //LEETCODE_1099_H
