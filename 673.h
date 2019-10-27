//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_673_H
#define LEETCODE_673_H
#include "Common.h"
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int count = nums.size();
        if(count<=1){
            return count;
        }

        vector<int> dp(count,1);
        vector<int> dpCount(count,1);
        for(int i=0;i<count;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1 == dp[i]){
                        dpCount[i]+=dpCount[j];
                    }else if(dp[j]+1 > dp[i]){
                        dpCount[i]=dpCount[j];
                    }
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=0,maxDp=-1;
        for(int i=0;i<count;i++)
        {
            if(dp[i]>maxDp){
                ans = dpCount[i];
            }else if(dp[i]==maxDp){
                ans +=dpCount[i];
            }
            maxDp=max(dp[i],maxDp);
        }
        return ans;
    }
};
#endif //LEETCODE_673_H
