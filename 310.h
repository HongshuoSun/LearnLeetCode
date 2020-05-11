//
// Created by Administrator on 2020/5/11.
//

#ifndef LEETCODE_310_H
#define LEETCODE_310_H
#include "Common.h"
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=1){
            return vector<int>{0};
        }
        vector<set<int>> data;

        set<int> current;
        set<int> next;
        vector<bool> visited(n,false);
        data.resize(n);
        for(const auto& edge:edges){
            data[edge[0]].insert(edge[1]);
            data[edge[1]].insert(edge[0]);
        }
        bool end = false;

        for(int i=0;i<n;i++){
            if(data[i].size()==1){
                next.insert(i);
            }
        }

        while(next.size()>0) {
            current = next;
            next.clear();
            for(auto &i:current){
                visited[i]= true;
            }
            for (auto &i:current) {
                auto &adjNodes = data[i];
                for (const auto &adj:adjNodes) {
                    data[adj].erase(i);
                    if ( !visited[adj] &&  data[adj].size() <= 1) {
                        if(next.count(adj)<1){
                            next.insert(adj);
                        }
                    }
                }
                data[i].clear();
            }
        }
        vector<int> ans;
        for(auto& i:current){
            ans.push_back(i);
        }
        return ans;
    }
};
#endif //LEETCODE_310_H
