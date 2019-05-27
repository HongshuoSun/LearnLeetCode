//
// Created by 孙宏硕 on 2019-05-27.
//

#ifndef LEETCODE_27REMOVEELEMENT_H
#define LEETCODE_27REMOVEELEMENT_H
#include "Common.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int n = nums.size();
        int length = 0;
        for(;i<n&&j<n;){
           if(nums[i]==val){
               if(j<i){
                   j = i;
               }
               while(j<n&&nums[j]==val){
                   j++;
               }
               if(j<n){
                   swap(nums[i++],nums[j]);
                   length++;
               }
           }else{
               i++;
               length++;
           }
        }
        return length;
    }
};
#endif //LEETCODE_27REMOVEELEMENT_H
