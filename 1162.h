//
// Created by Administrator on 2020/5/20.
//

#ifndef LEETCODE_1162_H
#define LEETCODE_1162_H
#include "Common.h"
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        queue<Point> q;
        int maxDist = 0xffffff;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    q.push(Point{i,j,0});
                }else{
                    grid[i][j]=maxDist;
                }
            }
        }
        int x;
        int y;
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            x = current.x;
            y = current.y;
            auto dis = current.dis+1;
            if(x-1>=0){
                if(grid[x-1][y]>=dis) {
                    grid[x - 1][y] = dis;
                    q.push(Point{x-1,y,dis});
                }
            }
            if(x+1<m){
                if(grid[x+1][y]>=dis) {
                    grid[x +1][y] = dis;
                    q.push(Point{x+1,y,dis});
                }
            }
            if(y-1>=0){
                if(  grid[x][y-1]>=dis) {
                    grid[x][y-1] = dis;
                    q.push(Point{x,y-1,dis});
                }
            }
            if(y+1<n){
                if(grid[x][y+1]>=dis) {
                    grid[x][y+1] = dis;
                    q.push(Point{x,y+1,dis});
                }
            }
        }
        int ans = -1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) {
                    ans = max(ans, grid[i][j]);
                }
            }
        }
        return ans<maxDist?ans:-1;
    }
    struct Point{
        int x;
        int y;
        int dis;
    };
};
#endif //LEETCODE_1162_H
