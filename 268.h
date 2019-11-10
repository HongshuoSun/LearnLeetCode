//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_268_H
#define LEETCODE_268_H
#include "Common.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for(int i=0;i<nums.size();i++){
            missing ^=i;
            missing ^=nums[i];
        }
        return missing;
    }
};
#endif //LEETCODE_268_H
