//
// Created by Administrator on 2019/10/23.
//

#ifndef LEETCODE_63_H
#define LEETCODE_63_H
#include "Common.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n=0;
        if(m<1){
            return 0;
        }
        n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        vector<long long> ans(n,0);
        ans[0]=1;
        int r1=0,r2=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long current =0;
                if(obstacleGrid[i][j]!=1) {
                    if (i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) {
                        current+=ans[j];
                    }
                    if (j - 1 >= 0&&obstacleGrid[i][j-1] != 1) {
                        current+=ans[j-1];
                    }
                    if(i==0&&j==0){
                        current = 1;
                    }
                }else{
                    current = 0;
                }
                ans[j] = current;
            }
        }
        return ans[n-1];
    }
};
#endif //LEETCODE_63_H
