//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_303_H
#define LEETCODE_303_H
#include "Common.h"
class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefixSum.clear();
        int sum = 0;
        length = nums.size();
        prefixSum.resize(length+1,0);
        for(int i=0;i<length;i++){
            sum +=nums[i];
            prefixSum[i+1]=sum;
        }
    }

    int sumRange(int i, int j) {
        return prefixSum[j+1]-prefixSum[i];
    }
    vector<int> prefixSum;
    int length;
};
#endif //LEETCODE_303_H
