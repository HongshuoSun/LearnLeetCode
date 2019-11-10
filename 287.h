//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_287_H
#define LEETCODE_287_H
#include "Common.h"
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(slow!=fast);
        int begin = nums[0];
        while(begin!=slow){
            slow = nums[slow];
            begin = nums[begin];
        }
        return begin;
    }
};
#endif //LEETCODE_287_H
