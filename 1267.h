//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_1267_H
#define LEETCODE_1267_H
#include "Common.h"
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> mCount(m,0);
        vector<int> nCount(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    mCount[i]++;
                    nCount[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    if(mCount[i]>1||nCount[j]>1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_1267_H
