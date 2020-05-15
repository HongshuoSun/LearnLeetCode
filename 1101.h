//
// Created by Administrator on 2020/5/13.
//

#ifndef LEETCODE_1101_H
#define LEETCODE_1101_H
#include "Common.h"
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> parents(N,-1);
        auto comp = [](const Log& a,const Log& b){
            return a.time>b.time;
        };
        priority_queue<Log,vector<Log>,decltype(comp)> q(comp);
        for(const auto& log :logs){
            Log g;
            g.time = log[0];
            g.friendA=log[1];
            g.friendB=log[2];
            q.push(g);
        }
        while(!q.empty()){
            auto current = q.top();
            q.pop();
            if(Find(current.friendA,parents)!=Find(current.friendB,parents)){
                Union(current.friendA,current.friendB,parents);
                auto pa = Find(current.friendA,parents);
                if(parents[pa]== -N){
                    return current.time;
                }
            }

        }
        return -1;
    }
private:
    struct Log{
        int time;
        int friendA;
        int friendB;
    };
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
#endif //LEETCODE_1101_H
