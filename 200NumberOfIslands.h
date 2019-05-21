//
// Created by sun51 on 2019/5/17.
//

#ifndef LEETCODE_200NUMBEROFISLANDS_H
#define LEETCODE_200NUMBEROFISLANDS_H
#include "Common.h"
#include <functional>
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int vLength = grid.size();
        if (vLength < 1) {
            return 0;
        }
        int result = 0;

        int hLength = grid[0].size();
        std::function<void(vector<vector<char>>& grid,int i,int j)> f = [&](vector<vector<char>>& grid,int i,int j)->void{
            if(i<0||j<0||i>=vLength||j>=hLength|| grid[i][j]=='0')
            {
                return;
            }
            grid[i][j] = '0';
            f(grid,i-1,j);
            f(grid,i,j-1);
            f(grid,i,j+1);
            f(grid,i+1,j);

        };
        for (int i = 0; i < vLength; i++) {
            for (int j = 0; j < hLength; j++) {
                if(grid[i][j]=='0')
                {
                    continue;
                }
                else
                {
                    result++;
                    f(grid,i,j);
                }
            }
        }
        return result;
    }
};
#endif //LEETCODE_200NUMBEROFISLANDS_H
