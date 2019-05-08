//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_872LEAFSIMILARTREES_H
#define LEETCODE_872LEAFSIMILARTREES_H
#include "Common.h"
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        dfs(root1,tree1);
        dfs(root2,tree2);
        return tree1 == tree2;
    }
    void dfs(TreeNode* root,vector<int>& leafs)
    {
        if( root ==NULL)
        {
        }else if( root->left == NULL && root->right == NULL)
        {
            leafs.push_back(root->val);
        }
        else
        {
            dfs(root->left,leafs);
            dfs(root->right,leafs);
        }
    }
};
#endif //LEETCODE_872LEAFSIMILARTREES_H
