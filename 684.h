//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_684_H
#define LEETCODE_684_H

#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,int> findMap;
        vector<int> ans;
        for(const auto &i :edges){
            int iParent = GetParent(findMap,i[0]);
            int jParent = GetParent(findMap,i[1]);
            if(iParent!=jParent){
                Union(findMap,iParent,jParent);
            }else{
                ans = i;
            }
        }
        return ans;
    }
    int GetParent( map<int,int>& findMap,int node) {
        if (findMap.count(node) < 1) {
            findMap.insert(make_pair(node,-1));
            return node;
        } else {
            int parent = node;
            vector<int> findStack;
            while (findMap[parent] >= 0) {
                findStack.push_back(parent);
                parent = findMap[parent];
            }
            for ( auto i:findStack) {
                findMap[i] = parent;
            }
            return parent;
        }

    }
    void Union(map<int,int>& findMap,int i,int j){
        int iParent = GetParent(findMap,i);
        int jParent = GetParent(findMap,j);
        if(iParent!=jParent){
            if(findMap[iParent]<findMap[jParent]){
                findMap[iParent] = findMap[iParent]+findMap[jParent];
                findMap[jParent] = iParent;
            }else{
                findMap[jParent] = findMap[iParent]+findMap[jParent];
                findMap[iParent] = jParent;
            }
        }
    }
};
#endif //LEETCODE_684_H
