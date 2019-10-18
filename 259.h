//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_259_H
#define LEETCODE_259_H
#include "Common.h"
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int result = 0;
        sort(nums.begin(),nums.end());
        int length = nums.size();
        for(int i=0;i<length-2;i++){
            int j = i+1,k=length-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<target){
                    result+= (k-j) ;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return result;
    }
};
#endif //LEETCODE_259_H
