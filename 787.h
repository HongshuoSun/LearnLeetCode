#include "Common.h"
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        N = n;
        graph = vector<map<int,int>>(N,map<int,int>());
        visited = vector<int>(N,INT32_MAX);
        for(const auto& f : flights){
            graph[f[0]][f[1]]=f[2];
            graph[f[1]][f[0]]=f[2];
        }
        visited[src]=0;
        DFS(src,K);
        return visited[dst] == INT32_MAX ? -1: visited[dst];
    }
    void DFS(int a,int count){
        if(count <0){
            return;
        }
        for(const auto & neighb : graph[a]){
            if(visited[neighb.first]==INT32_MAX || visited[neighb.first] > visited[a]+ neighb.second){
                visited[neighb.first] = visited[a]+neighb.second;
                DFS(neighb.first,count-1);
            }
        }
    }
    vector<map<int,int>> graph;
    vector<int> visited;
    int N;
};