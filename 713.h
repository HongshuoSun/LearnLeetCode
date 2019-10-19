//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_713_H
#define LEETCODE_713_H
#include "Common.h"
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int result = 0;
        int length = nums.size();
        int left = 0,right = 0;
        int mul =1;
        for(int right=0;right<length &&mul<k;right++){
            mul *=nums[right];
            while(mul>=k){ mul = mul/nums[left]; left++;}
            result += right - left + 1;
        }
        return result;
    }
};
#endif //LEETCODE_713_H
