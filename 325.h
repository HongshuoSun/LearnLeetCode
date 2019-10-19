//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_325_H
#define LEETCODE_325_H
#include "Common.h"
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int,int> numMap={{0,-1}};
        int sum = 0;
        int ans = -1;
        int length = nums.size();
        for(int i=0;i<length;i++){
            sum+=nums[i];
            if(numMap.count(sum-k)){
                ans = max(ans,i-numMap[sum-k]);
            }
            if(numMap.count(sum)==0){
                numMap[sum]=i;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_325_H
