//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_152_H
#define LEETCODE_152_H
#include "Common.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int minimum = 0;
        int maximum = 0;
        int numCount = nums.size();
        if(numCount<=1){
            return numCount==0?0:nums[0];
        }
        ans = minimum = maximum=nums[0];

        for(int i=1;i<numCount;i++){
            if(nums[i]<0){
                swap(maximum,minimum);
            }
            maximum = max(maximum*nums[i],nums[i]);
            minimum = min(minimum*nums[i],nums[i]);
            ans = max(ans,maximum);
        }
        return ans;
    }
};
#endif //LEETCODE_152_H
