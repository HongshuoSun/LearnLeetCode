//
// Created by Administrator on 2020/5/19.
//

#ifndef LEETCODE_1059_H
#define LEETCODE_1059_H
#include "Common.h"
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        in = vector<unordered_set<int>>(n);
        out = vector<unordered_set<int>>(n);
        visited = vector<bool>(n,false);
        for(const auto& edge:edges){
            out[edge[0]].insert(edge[1]);
            in[edge[1]].insert(edge[0]);
        }
        dest = destination;
        ans= true;
        count = 0;
        DFS(source);
        return ans&& count>0;
    }
private:
    int count = 0;
    int ans = true;
    int dest;
    vector<unordered_set<int>> in;
    vector<unordered_set<int>> out;
    vector<bool> visited;
    void DFS(int current){
        if(visited[current]){
            ans = false;
        }
        visited[current]= true;
        if(current == dest){
            if(out[dest].size()>0){
                ans = false;
            }else{
                count++;
            }
            visited[current]=false;
            return;
        }
        if(out[current].size()<1){
            ans=false;
            return;
        }
        for(const auto& child :out[current]){
            if(visited[child]){
                ans = false;
                return;
            }
            DFS(child);
        }
        visited[current]=false;
    }
};
#endif //LEETCODE_1059_H
