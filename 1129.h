//
// Created by Administrator on 2020/5/19.
//

#ifndef LEETCODE_1129_H
#define LEETCODE_1129_H
#include "Common.h"
#include <tuple>
class Solution {
private:
    vector<vector<int>> dis;
    vector<list<int>> redGraph;
    vector<list<int>> blueGraph;
    //const int INT_MAX1 = 999999;
    const int BLUE = 0;
    const int RED  = 1;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        dis=vector<vector<int>>(n,vector<int>(2,INT_MAX));
        redGraph = vector<list<int>>(n);
        blueGraph= vector<list<int>>(n);
        for(const auto& edge:red_edges){
            redGraph[edge[0]].push_back(edge[1]);
        }
        for(const auto& edge:blue_edges){
            blueGraph[edge[0]].push_back(edge[1]);
        }
        dis[0]={0,0};
        DFS(0,BLUE);
        DFS(0,RED);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i] = min(dis[i][RED],dis[i][BLUE]);
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
    void DFS(int current,int lastColor){
        if(lastColor==RED){
            for(const auto & child :blueGraph[current]){
                if(dis[child][BLUE]> 1+dis[current][RED]){
                    dis[child][BLUE] = 1+dis[current][RED];
                    DFS(child,BLUE);
                }
            }
        }else{
            for(const auto & child :redGraph[current]){
                if(dis[child][RED]> 1+dis[current][BLUE]){
                    dis[child][RED] = 1+dis[current][BLUE];
                    DFS(child,RED);
                }
            }
        }
    }
};
#endif //LEETCODE_1129_H
