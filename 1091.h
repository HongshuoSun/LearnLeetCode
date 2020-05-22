//
// Created by Administrator on 2020/5/22.
//

#ifndef LEETCODE_1091_H
#define LEETCODE_1091_H
#include "Common.h"
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<Point> q;
        queue<Point> next;
        if(grid[0][0]==0) {
            next.push({0, 0});
        }
        int ans=0;
        while(!next.empty()) {
            swap(next,q);
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                if (visited[current.x][current.y]) {
                    continue;
                }
                if(current.x==m-1&&current.y==n-1){
                    return ans+1;
                }
                visited[current.x][current.y] = true;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int nexX = current.x + i;
                        int nexY = current.y + j;
                        if (nexX >= 0 && nexY >= 0 && nexX < m && nexY < n && !visited[nexX][nexY] &&grid[nexX][nexY]==0 ) {
                            next.push({nexX, nexY});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
private:
    struct Point{
        int x;
        int y;
    };
};
#endif //LEETCODE_1091_H
