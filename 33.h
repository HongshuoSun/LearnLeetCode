//
// Created by sun51 on 2019/10/30.
//

#ifndef LEETCODE_33_H
#define LEETCODE_33_H
#include "Common.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if(length<1){
            return -1;
        }
        int begin = 0;
        int end = length-1;
        int mid = 0,current = 0;
        while(begin<end){
            mid = (begin+end)/2;
            if(nums[mid]>nums[end]){
                begin = mid+1;
            }else{
                end = mid;
            }
        }
        mid = begin;
        vector<int>::iterator l,r;
        if(mid>0){
            l = lower_bound(nums.begin(),nums.begin()+mid,target);
            if(l!=nums.begin()+mid&& *l == target){
                return l-nums.begin();
            }
        }
        r = lower_bound(nums.begin()+mid,nums.end(),target);
        if(r!=nums.end()&& *r == target){
            return r-nums.begin();
        }
        return -1;
    }
};
#endif //LEETCODE_33_H
