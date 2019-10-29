//
// Created by sun51 on 2019/10/29.
//

#ifndef LEETCODE_5_H
#define LEETCODE_5_H
#include "Common.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if(length<=1){
            return s;
        }
        vector<vector<bool>> dp(length+1,vector<bool>(length+1,false));
        int ans=1,i1=1,j1=1;

        for(int i=1;i<=length;i++){
            dp[i][i] = true;
        }
        for(int i=1;i<length;i++){
            if(s[i-1]==s[i]){
                dp[i][i+1] = true;
                ans = 2;
                i1 = i;
                j1 = i+1;
            }
        }

        for(int i=length-1;i>=1;i--){
            for(int j=i;j<=length;j++){
                if(s[j-1]==s[i]){
                    if(dp[i-1][j+1]){
                        dp[i][j] = true;
                        if(j-i+1 > ans){
                            ans = j-i+1;
                            i1 = i;
                            j1 = j;
                        }
                    }
                }
                else{
                    dp[i][j] = false;
                }

            }
        }
        return s.substr(i1-1,ans);
    }
};
#endif //LEETCODE_5_H
