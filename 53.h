//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_53_H
#define LEETCODE_53_H
#include "Common.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int result=nums[0];
        int length = nums.size();
        for(int i=0;i<length;i++){
            sum+=nums[i];
            if(sum>result){
                result = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return result;
    }
};
#endif //LEETCODE_53_H
