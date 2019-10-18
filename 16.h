//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_16_H
#define LEETCODE_16_H
#include "Common.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = nums[0]+nums[1]+nums[2];

        int length = nums.size();
        for(int i=0;i<length-2;i++)
        {
            int j = i+1;
            int k = length-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if( abs(sum-target)<abs(result-target)){
                    result = sum;
                }
                sum<target?j++:k--;
            }
        }
        return result;
    }
};
#endif //LEETCODE_16_H
