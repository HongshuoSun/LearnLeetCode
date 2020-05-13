//
// Created by Administrator on 2020/5/13.
//

#ifndef LEETCODE_1135_H
#define LEETCODE_1135_H
#include "Common.h"
class Solution {

    struct Edge{
        int cast;
        int a;
        int b;
    };
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if(N==0){
            return -1;
        }
        if(N==1){
            return 0;
        }
        vector<map<int,int>> graph=vector<map<int,int>>(N+1,map<int,int>());
        vector<int> parent(N+1,-1);

        auto compare2 = [](const Edge& lhs,const  Edge& rhs)
        {
            return lhs.cast >= rhs.cast;
        };
        priority_queue<Edge,vector<Edge>,decltype(compare2)> q1(compare2);
        vector<bool> visited= vector<bool>(N+1,false);
        for(const auto& edge:connections){
            Edge e;
            e.a = edge[0];
            e.b=edge[1];
            e.cast = edge[2];
            q1.push(e);
        }
        int cost=0;
        int count = 0;
        while(!q1.empty()){
            auto current = q1.top();
            q1.pop();
            if(Find(current.a,parent)!=Find(current.b,parent)){
                cost+=current.cast;
                Union(current.a,current.b,parent);
            }
        }
        return *min_element(parent.begin()+1,parent.end())==-N?cost:-1;
    }

    int Find(int a,vector<int>& parents){
        if(parents[a]>=0){
            parents[a]=Find(parents[a],parents);
            return parents[a];
        }else{
            return a;
        }

    }
    void Union(int a,int b,vector<int>& parents){
        int pa = Find(a,parents);
        int pb = Find(b,parents);
        if(pa==pb){
            return;
        }
        if(parents[pa]<parents[pb]){
            parents[pa] +=parents[pb];
            parents[pb]=pa;
        }else{
            parents[pb] +=parents[pa];
            parents[pa]=pb;
        }
    }
};
#endif //LEETCODE_1135_H
