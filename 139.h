//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_139_H
#define LEETCODE_139_H
#include "Common.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int,set<string>> dict;
        for(const auto &str:wordDict){
            dict[str.length()].insert(str);
        }
        int strLength = s.size();
        vector<bool> dp(strLength+1,false);
        dp[0] = true;
        for(int i=1;i<=strLength;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==1 && dict[i-j].count(s.substr(j,i-j))>0){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[strLength];
    }
};
#endif //LEETCODE_139_H
