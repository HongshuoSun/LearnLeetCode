//
// Created by sun51 on 2019/10/24.
//

#ifndef LEETCODE_64_H
#define LEETCODE_64_H
#include "Common.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m<1){
            return 0;
        }
        int n = grid[0].size();
        if(n<1){
            return 0;
        }
        int up;
        int left;
        int tmp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                up=i-1;
                left=j-1;
                if(up>=0&&left>=0){
                    grid[i][j] = min(grid[up][j],grid[i][left])+grid[i][j];
                }else if(up>=0){
                    grid[i][j] = grid[up][j]+grid[i][j];
                }else if(left>=0){
                    grid[i][j] = grid[i][left]+grid[i][j];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
#endif //LEETCODE_64_H
