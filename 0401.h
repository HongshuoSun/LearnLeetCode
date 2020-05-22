//
// Created by Administrator on 2020/5/21.
//

#ifndef LEETCODE_0401_H
#define LEETCODE_0401_H
#include "Common.h"
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        adjoint=vector<set<int>>(n);
        visited = vector<bool>(n,false);
        N = n;
        for(const auto& edge :graph){
            if( adjoint[edge[0]].count(edge[1])<1)
            adjoint[edge[0]].insert(edge[1]);
        }
        DFS(start,target);
        return visited[target];
    }
private:
    void DFS(int node,int target){
        if(visited[node]){
            return;
        }
        visited[node] = true;
        if(node==target){
            return;
        }
        for(const auto& adj:adjoint[node]){
            if(!visited[adj]){
                DFS(adj,target);
            }
        }
    }
    int N;
    vector<bool> visited;
    vector<set<int>> adjoint;
};
#endif //LEETCODE_0401_H
