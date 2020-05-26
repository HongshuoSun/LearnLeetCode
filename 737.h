//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_737_H
#define LEETCODE_737_H
#include "Common.h"
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        UnionFind<string> unionFind;
        for (auto &strs:pairs) {
            if(!unionFind.Contains(strs[0])){
                unionFind.Add(strs[0]);
            }
            if(!unionFind.Contains(strs[1])){
                unionFind.Add(strs[1]);
            }
            unionFind.Union(strs[0],strs[1]);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && ( !unionFind.Contains(words1[i]) ||!unionFind.Contains(words2[i]) || unionFind.Find(words1[i])!=unionFind.Find(words2[i])))
            {
                return false;
            }
        }
        return true;
    }
private:

    template< typename  T>
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
#endif //LEETCODE_737_H
