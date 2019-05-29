//
// Created by 孙宏硕 on 2019-05-27.
//

#ifndef LEETCODE_26REMOVEDUPLICATESFROMSORTEDARRAY_H
#define LEETCODE_26REMOVEDUPLICATESFROMSORTEDARRAY_H
#include "Common.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<=1){
            return n;
        }
        int i=1,j=1;
        for(;i<n&&j<n;) {
            if(nums[j] == nums[i-1]){
                j++;
            } else{
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};
#endif //LEETCODE_26REMOVEDUPLICATESFROMSORTEDARRAY_H
