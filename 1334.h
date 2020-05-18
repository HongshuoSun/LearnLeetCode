//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_1334_H
#define LEETCODE_1334_H
#include "Common.h"
#define INT_MAX 2147483647
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        N = n;
        graph= vector<vector<unsigned int>>(N,vector<unsigned int>(N,MAX_INT));
        for(const auto& edge :edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        for(int i=0;i<N;i++){
            graph[i][i] = 0;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k = 0;k<N;k++){
                    if(graph[j][k]> graph[j][i]+graph[i][k]){
                        graph[j][k] = graph[j][i]+graph[i][k];
                    }
                }
            }
        }
        int ans = -1;
        int minCount = MAX_INT;
        for(int i=0;i<N;i++){
            int count = 0;
            for(int j=0;j<N;j++){
                if(graph[i][j]<=distanceThreshold&& i!=j){
                    count++;
                }
            }
            if(count<minCount){
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }
private:
    int N;
    unsigned int MAX_INT =INT_MAX/2-1;
    vector<vector<unsigned  int>> graph;
};
#endif //LEETCODE_1334_H
