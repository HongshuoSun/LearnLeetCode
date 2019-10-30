//
// Created by sun51 on 2019/10/30.
//

#ifndef LEETCODE_169_H
#define LEETCODE_169_H
#include "Common.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
#endif //LEETCODE_169_H
