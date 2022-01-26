//
// Created by bugma on 2021/12/13.
//

#ifndef LEETCODE_807_H
#define LEETCODE_807_H
#include "Common.h"
#include <vector>
using namespace  std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                int oV = grid[r][c];
                int mV = GetMinMaxVal(grid,row,col,r,c);
                ans += (mV-oV);
            }
        }
        return ans;
    }
    inline int GetMinMaxVal(const vector<vector<int>>& grid,int row,int col,  int r,int c){
        int val = grid[r][c];
        int rVal = val;
        int cVal = val;
        for(int _r=0;_r<row;_r++){
            rVal = std::max(grid[_r][c],rVal);
        }
        for(int _c=0;_c<col;_c++){
            cVal = std::max(grid[r][_c],cVal);
        }
        return std::min(rVal,cVal);
    }
};
#endif //LEETCODE_807_H
