//
// Created by Administrator on 2020/5/23.
//

#ifndef LEETCODE_1319_H
#define LEETCODE_1319_H
#include "Common.h"
class Solution {
private:
    template<typename  T>
    struct UnionFind{
        map<T,T> parentMap;
        void Add(const T& a){
            if(parentMap.count(a)<1){
                parentMap.insert(make_pair(a,a));
            }
        }
        void Contains(const T&a){
            return parentMap.count(a)>0;
        }
        T Find(const T&a){
            if(parentMap[a]!=a){
                parentMap[a] =Find(parentMap[a]);
            }
            return parentMap[a];
        }
        void Union(const T&a,const T&b){
            parentMap[ Find(a)]=Find(b);
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind<int> unionFind;
        for(int i=0;i<n;i++){
            unionFind.Add(i);
        }
        int count = 0;
        for (const auto &connect:connections) {
            auto a = connect[0];
            auto b = connect[1];
            if(unionFind.Find(a)==unionFind.Find(b)){
                count++;
            }else{
                unionFind.Union(a,b);
            }
        }
        set<int> parent;
        int region=0;
        for(int i=0;i<n;i++){
            if(parent.count( unionFind.Find(i))<1){
                parent.insert(unionFind.Find(i));
                region++;
            }
        }
        return count>=(region-1)?region-1:-1;
    }
};
#endif //LEETCODE_1319_H
