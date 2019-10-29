//
// Created by sun51 on 2019/10/29.
//

#ifndef LEETCODE_35_H
#define LEETCODE_35_H
#include "Common.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        if(length<1){
            return length;
        }
        int begin = 0,end = length-1,mid = 0,current=0;
        while(begin<=end){
            mid = (begin+end)/2;
            current = nums[mid];
            if(current>target){
                end = mid-1;
            }else if(current < target){
                begin = mid+1;
            }else{
                break;
            }
        }
        return current==target?mid:( current<target)?mid+1:mid;
    }
};
#endif //LEETCODE_35_H
