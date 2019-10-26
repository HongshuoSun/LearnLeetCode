//
// Created by sun51 on 2019/10/26.
//

#ifndef LEETCODE_983_H
#define LEETCODE_983_H
#include "Common.h"
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dayCount = days.size();
        if(dayCount<1){
            return 0;
        }
        vector<vector<int>> dp(2,vector<int>(31,costs[0]*365));
        fill(dp[0].begin()+1,dp[0].end(),costs[2]);
        fill(dp[0].begin()+1,dp[0].begin()+8,min(costs[2],costs[1]));
        fill(dp[0].begin()+1,dp[0].begin()+2,min(costs[0],min(costs[2],costs[1])));

        for(int i=1;i<dayCount;i++){
            int sub = days[i]-days[i-1];
            int preCost = *min(dp[(i-1)%2].begin()+1,dp[(i-1)%2].end());
            fill(dp[i%2].begin(),dp[i%2].end(),costs[2]+preCost);
            fill(dp[i%2].begin(),dp[i%2].begin()+8,min(costs[2],costs[1])+preCost);
            fill(dp[i%2].begin(),dp[i%2].begin()+2,min(costs[0],min(costs[2],costs[1]))+preCost);
            for(int j=30;j>=1;j--){
                if(j+sub<=30){
                    dp[i%2][j] = min(dp[i%2][j],dp[(i-1)%2][j+sub]);
                }
            }
        }
        return *min(dp[(dayCount-1)%2].begin()+1,dp[(dayCount-1)%2].end());
    }
};
#endif //LEETCODE_983_H
