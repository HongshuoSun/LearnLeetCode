//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_287_H
#define LEETCODE_287_H
#include "Common.h"
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,j=0;
        int length =nums.size();
        while(true){
            i = nums[i];
            i = nums[i];
            j = nums[j];
            if(i==j){
                return j;
            }
        }
        return -1;
    }
};
#endif //LEETCODE_287_H
