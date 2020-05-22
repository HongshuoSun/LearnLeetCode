//
// Created by Administrator on 2020/5/19.
//

#ifndef LEETCODE_802_H
#define LEETCODE_802_H
#include "Common.h"
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        N = graph.size();
        in=vector<set<int>>(N);
        out=vector<set<int>>(N);
        flag=vector<bool>(N,false);
        for(int i=0;i<N;i++){
            for(int j=0;j<graph[i].size();j++){
                out[i].insert(graph[i][j]);
                in[graph[i][j]].insert(i);
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(out[i].size()<1) {
                q.push(i);
            }
        }
        while(!q.empty()){
            const auto current = q.front();
            q.pop();
            flag[current] = true;
            for (const auto parent:in[current]) {
                out[parent].erase(current);
                if(out[parent].size()<=0){
                    q.push(parent);
                }
            }
            in[current].clear();
        }
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(flag[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    int N;
    vector<set<int>> in;
    vector<set<int>> out;
    vector<bool> flag;
};
#endif //LEETCODE_802_H
