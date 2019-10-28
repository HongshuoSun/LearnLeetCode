//
// Created by sun51 on 2019/10/28.
//

#ifndef LEETCODE_209_H
#define LEETCODE_209_H
#include "Common.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int numCount = nums.size();
        int ans = numCount+1;
        if(numCount<1){
            return 0;
        }

        vector<int> dp(numCount+1,0);
        for(int i=1;i<=numCount;i++){
            dp[i] = dp[i-1]+nums[i-1];
        }
        for(int i=1;i<=numCount;i++){
            int current = s+ dp[i-1];
            auto it = lower_bound(dp.begin(),dp.end(),current);
            if(it<dp.end()){
                ans = min(ans, int(it-dp.begin()) -i+1);
            }
        }
        return ans<=numCount?ans:0;
    }
};
#endif //LEETCODE_209_H
