//
// Created by sun on 2019/11/9.
//

#ifndef LEETCODE_75_H
#define LEETCODE_75_H
#include "Common.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int zeroRight = 0;
        int twoLeft = length-1;
        int cur = zeroRight;
        while(cur<=twoLeft){
            if(nums[cur]==0){
                swap(nums[zeroRight],nums[cur]);
                zeroRight++;
                cur++;
            }else if(nums[cur]==2){
                swap(nums[twoLeft],nums[cur]);
                twoLeft--;
            }else{
                cur++;
            }
        }
    }
};
#endif //LEETCODE_75_H
