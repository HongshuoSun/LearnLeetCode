//
// Created by Administrator on 2020/5/20.
//

#ifndef LEETCODE_959_H
#define LEETCODE_959_H
#include "Common.h"
class Solution {
    const char left='\\';
    const char right = '/';
    int m;
    int n;
    int ans;
    vector<vector<bool>> graph;
public:
    int regionsBySlashes(vector<string>& grid) {
        ans = 0;
        m=grid.size();
        n=grid[0].size();
        graph = vector<vector<bool>>(m*3,vector<bool>(n*3,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==left){
                    for(int x=0;x<3;x++){
                        graph[i*3+x][j*3+x] = true;
                    }
                }else if(grid[i][j]==right){
                    for(int x=0;x<3;x++){
                        graph[i*3+x][j*3+ 2-x] = true;
                    }
                }
            }
        }
        for(int i=0;i<m*3;i++){
            for(int j=0;j<n*3;j++){
                if(!graph[i][j]){
                    DFS(i,j,graph);
                    ans++;
                }
            }
        }
        return ans;
    }
    void DFS(int x,int y,vector<vector<bool>>& graph){
        if(x<0||x>=3*m||y<0||y>=3*n|| graph[x][y]){
            return;
        }
        graph[x][y]=true;
        DFS(x-1,y,graph);
        DFS(x+1,y,graph);
        DFS(x,y-1,graph);
        DFS(x,y+1,graph);
    }
};
#endif //LEETCODE_959_H
