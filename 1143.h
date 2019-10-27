//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_1143_H
#define LEETCODE_1143_H
#include "Common.h"
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n<1 || m<1){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[n][m];
    }
};
#endif //LEETCODE_1143_H
