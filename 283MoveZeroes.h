//
// Created by 孙宏硕 on 2019-05-27.
//

#ifndef LEETCODE_283MOVEZEROES_H
#define LEETCODE_283MOVEZEROES_H
#include "Common.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int size = nums.size();
        for(;i<size&&j<size;) {
            if(nums[i]==0){
                while(j<size&&nums[j]==0){
                    j++;
                }
                if(j<size){
                    swap(nums[i++],nums[j]);
                }
            }
        }
    }
};
#endif //LEETCODE_283MOVEZEROES_H
