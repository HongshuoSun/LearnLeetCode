//
// Created by sun51 on 2019/10/27.
//

#ifndef LEARNLEETCODE_300_H
#define LEARNLEETCODE_300_H

#include "Common.h"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int count = nums.size();
        if(count<=1){
            return count;
        }
        int ans = -1;
        vector<int> dp(count,1);
        for(int i=0;i<count;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return  ans;
    }
};
#endif //LEARNLEETCODE_300_H
