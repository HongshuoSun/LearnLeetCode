//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_1061_H
#define LEETCODE_1061_H
#include "Common.h"
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        UnionFind<char> unionFind;
        for(char c='a';c<='z';c++){
            unionFind.Add(c);
        }
        for(int i=0;i<A.size();i++){
            unionFind.Union(A[i],B[i]);
        }
        string ans = S;
        for(int i=0;i<ans.size();i++){
            ans[i]=unionFind.Find(ans[i]);
        }
        return ans;
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
            T pa = Find(a);
            T pb = Find(b);
            if(pa!=pb) {
                if (pa < pb) {
                    parentMap[pb] = pa;
                } else {
                    parentMap[pa] = pb;
                }
            }
        }
    };
};
#endif //LEETCODE_1061_H
