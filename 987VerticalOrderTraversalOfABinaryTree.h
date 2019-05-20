//
// Created by 孙宏硕 on 2019-05-15.
//

#ifndef LEETCODE_987VERTICALORDERTRAVERSALOFABINARYTREE_H
#define LEETCODE_987VERTICALORDERTRAVERSALOFABINARYTREE_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        treeMap =  map<int,map<int,vector<int>>>();
        visit(root,0,0);
        vector<vector<int>> result;
        for(auto v:treeMap)
        {
            result.push_back(vector<int>());
            for(auto h : v.second)
            {
                for(auto e:h.second)
                {
                    result[result.size()-1].push_back(e);
                }

            }
        }
        return result;
    }
    map<int,map<int,vector<int>>> treeMap;

    void visit(TreeNode* node,int vertIndex,int horiIndex )
    {
        if(node == nullptr)
        {
            return;
        }
        if(treeMap.find(vertIndex)==treeMap.end())
        {
            treeMap.insert(make_pair(vertIndex,map<int,vector<int>>()));
        }
        if( treeMap[vertIndex].find(horiIndex) ==  treeMap[vertIndex].end())
        {
            treeMap[vertIndex].insert(make_pair(horiIndex,vector<int>()));
        }
        treeMap[vertIndex][horiIndex].push_back(node->val);
        visit(node->left,vertIndex-1,horiIndex+1);
        visit(node->right,vertIndex+1,horiIndex+1);
    }
};
#endif //LEETCODE_987VERTICALORDERTRAVERSALOFABINARYTREE_H
