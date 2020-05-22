//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_399_H
#define LEETCODE_399_H
#include "Common.h"
class Solution {

    set<string> visited;
    map<string,map<string,double>> dp;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        dp.clear();
        for(int i=0;i<equations.size();i++){
            dp[equations[i][0]][equations[i][0]]=1.0;
            dp[equations[i][1]][equations[i][1]]=1.0;
            dp[equations[i][0]][equations[i][1]]=values[i];
            dp[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        vector<double> ans(queries.size(),-1.0f);
        for(int i=0;i<queries.size();i++){
            visited.clear();
            ans[i] = GetValues(queries[i][0],queries[i][1]);
        }
        return ans;
    }
    double GetValues(const string& a,const string& b){
        if(dp.count(a)<1 || dp.count(b)<1){
            return -1.0;
        }
        if(a==b){
            return 1.0f;
        }
        if(visited.count(a)>0) {
            return -1.0;
        }
        visited.insert(a);
        if(dp[a].count(b)>0){
            return dp[a][b];
        }

        for(const auto& i:dp[a]){
            if( visited.count(i.first)<1) {
                auto ans = GetValues(i.first, b);
                dp[a][b]=ans*i.second;
                dp[b][a] = 1/dp[a][b];
                if(ans>-0.001){
                    return ans;
                }
            }
        }
        return -1.0f;
    }

};
#endif //LEETCODE_399_H
