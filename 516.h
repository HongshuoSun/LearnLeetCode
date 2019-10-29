//
// Created by sun51 on 2019/10/29.
//

#ifndef LEETCODE_516_H
#define LEETCODE_516_H
#include "Common.h"
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.length();
        if(length<=1){
            return length;
        }
        vector<vector<int>> dp(length+1,vector<int>(length+1,0));
        for(int i=1;i<=length;i++){
            dp[i][i] = 1;
        }
        int ans = 1;
        for(int i=length-1;i>=1;i--){
            for(int j=i;j<=length;j++){
                if(s[i-1]==s[j-1]){
                    dp[i][j] = dp[i+1][j-1]+2;
                    ans = max(ans,dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_516_H
