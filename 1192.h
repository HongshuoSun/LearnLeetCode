//
// Created by Administrator on 2020/5/12.
//

#ifndef LEETCODE_1192_H
#define LEETCODE_1192_H
#include "Common.h"
class Solution {
public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ans.clear();
        visited = vector<bool>(n,false);
        dfs = vector<int>(n,-1);
        graph = vector<set<int>>(n,set<int>());
        connect = vector<int>(n,-1);
        for(auto& i :connections){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        DFS(0,-1);
        return ans;
    }
private:
    vector<bool> visited;
    vector<int>  dfs;
    vector<int>  connect;
    stack<int>   s;
    vector<vector<int>> ans;
    vector<set<int>> graph;
    int index = 0;
    void DFS(int node,int parent){
        connect[node]= dfs[node] = index++;

        visited[node]=true;
        for(const auto & current:graph[node]){
            if(current == parent){
                continue;
            }
            if(!visited[current]){
                DFS(current,node);
                connect[node] = std::min(connect[node],connect[current]);
                if (connect[current] >= dfs[current]) {

                        ans.push_back(vector<int>{current, node});

                }
            }
            else{
                connect[node] = std::min(connect[node],dfs[current]);
            }
        }

    }
};
#endif //LEETCODE_1192_H
