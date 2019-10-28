//
// Created by sun51 on 2019/10/28.
//

#ifndef LEETCODE_221_H
#define LEETCODE_221_H
#include "Common.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m<1){
            return 0;
        }
        int n = matrix[0].size();
        if(n<1){
            return 0;
        }
        int ans = 0;
        int prev = 0;
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp = dp[j+1];
                if(matrix[i][j]=='0'){
                    dp[j+1] = 0;
                }else{
                    dp[j+1] = min( dp[j],min(dp[j+1],prev))+1;
                }
                ans = max(ans,dp[j+1]);
                prev = tmp;
            }
        }
        return ans*ans;
    }
};
#endif //LEETCODE_221_H
