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
            double values=0;
            if(GetValues(queries[i][0],queries[i][1],values))
            {
                ans[i] = values;
            }else {
                ans[i] = -1;
            }
        }
        return ans;
    }
    bool GetValues(const string& a,const string& b,double& value){
        if(dp.count(a)<1 || dp.count(b)<1){
            return false;
        }
        if(a==b){
            value = 1.0;
            return true;
        }
        if(visited.count(a)>0) {
            return false;
        }
        visited.insert(a);
        if(dp[a].count(b)>0){
            value =  dp[a][b];
            return true;
        }

        for(const auto& i:dp[a]){
            if( visited.count(i.first)<1 && i.second>=0) {
                double subValue;
                if(GetValues(i.first, b,subValue))
                {
                    value = dp[a][b]=dp[a][i.first]*subValue;
                    dp[b][a]=1/dp[a][b];
                    return true;
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE_399_H
