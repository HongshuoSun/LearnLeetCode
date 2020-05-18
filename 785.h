//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_785_H
#define LEETCODE_785_H
#include "Common.h"
class Solution {
    const int RED = 1;
    const int BLACK = 2;
    int N;
    vector<int> colors;
    vector<bool> visited;
    bool ans;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        ans = true;
        N = graph.size();
        if(N<=2){
            return true;
        }
        colors = vector<int>(N,0);
        visited = vector<bool>(N,false);

        for(int i=0;i<N;i++){
            if(!visited[i]){
                DFS(i,-1,graph);
            }
        }
        return ans;
    }
    void DFS(int node ,int preNode,const vector<vector<int>>& graph){
        if(visited[node]){
            if(preNode>=0){
                if(colors[node]==colors[preNode]){
                    ans = false;
                }
            }
        }
        else{
            visited[node] = true;
            int color = RED;
            if(preNode>=0&& colors[preNode]==RED){
                color = BLACK;
            }
            colors[node] = color;
            for(int i=0;i<graph[node].size();i++){
                DFS(graph[node][i],node,graph);
            }
        }
    }
};
#endif //LEETCODE_785_H
