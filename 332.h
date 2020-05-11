//
// Created by Administrator on 2020/5/11.
//

#ifndef LEETCODE_332_H
#define LEETCODE_332_H
#include "Common.h"
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        ans.clear();
        for(const auto& ticket:tickets){
            adj[ticket[0]][ticket[1]]++;
        }
        DFS("JFK");
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    void DFS(const string& current){

        for(auto& data :adj[current]) {
            if (data.second > 0) {
                data.second--;
                DFS(data.first);
            }
        }
        ans.push_back(current);
    }
    vector<string> ans;
    map<string,map<string,int>> adj;
};
#endif //LEETCODE_332_H
