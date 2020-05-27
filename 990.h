//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_990_H
#define LEETCODE_990_H
#include "Common.h"
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind<char> unionFind;
        for(const auto& equ:equations){
            if(equ[1]=='='){
                if(!unionFind.Contains(equ[0])){
                    unionFind.Add(equ[0]);
                }
                if(!unionFind.Contains(equ[3])){
                    unionFind.Add(equ[3]);
                }
                unionFind.Union(equ[0],equ[3]);
            }
        }
        for(const auto& equ:equations){
            if(equ[1]=='!'){
                char a = equ[0];
                char b = equ[3];
                if(a==b){
                    return false;
                }
                else if(unionFind.Contains(a)&& unionFind.Contains(b)&& unionFind.Find(a)==unionFind.Find(b)){
                    return false;
                }
            }
        }
        return true;
    }
private:
    template<typename  T>
    struct UnionFind{
        map<T,T> parentMap;
        void Add(const T& a){
            if(parentMap.count(a)<1){
                parentMap.insert(make_pair(a,a));
            }
        }
        bool Contains(const T&a){
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
};
#endif //LEETCODE_990_H
