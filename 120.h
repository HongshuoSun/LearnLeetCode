//
// Created by Administrator on 2019/10/23.
//

#ifndef LEETCODE_120_H
#define LEETCODE_120_H
#include "Common.h"
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = 0;
        int stageCount = triangle.size();
        if(stageCount<1){
            return ans;
        }
        for(int i=1;i<stageCount;i++){
            int currentCount = triangle[i].size();
            int lastCount = currentCount-1;
            for(int j=0;j<currentCount;j++){
                int r1 = j-1;
                int r2 = j;
                int current = triangle[i][j];
                if(r1>=0&&r2<lastCount){
                    triangle[i][j] = min( triangle[i-1][r1],triangle[i-1][r2])+current;
                }
                else if(r1>=0){
                    triangle[i][j] = triangle[i-1][r1]+current;
                }
                else if(r2<lastCount){
                    triangle[i][j] = triangle[i-1][r2]+current;
                }
            }
        }
        ans = triangle[stageCount-1][0];
        for(int j=1;j<triangle[stageCount-1].size();j++){
            ans = min(ans,triangle[stageCount-1][j]);
        }
        return ans;
    }
};
#endif //LEETCODE_120_H
