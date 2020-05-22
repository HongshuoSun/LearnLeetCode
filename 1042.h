//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_1042_H
#define LEETCODE_1042_H
#include "Common.h"
#include <unordered_set>
class Solution {
public:
    vector<unordered_set<int>> graph;
    int n;
    vector<int> colors;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        colors= vector<int>(N,0);
        graph= vector<unordered_set<int>>(N);
        n = N;
        for(const auto& path:paths){
            graph[path[0]-1].insert(path[1]-1);
            graph[path[1]-1].insert(path[0]-1);
        }
        for(int i=0;i<n;i++){
            if(!colors[i]){
                Color(i);
            }
        }
        return colors;
    }
    void Color(int node){
        int color = 0xff;
        for(auto i : graph[node]){
            if(colors[i]){
                color = color & ~(1<< (colors[i]));
            }
        }
        for(int i=1;i<=4;i++){
            if(color& (1<<i)){
                colors[node] = i;
                break;
            }
        }
        for(auto i : graph[node]){
            if(!colors[i]){
                Color(i);
            }
        }
    }
};
#endif //LEETCODE_1042_H
