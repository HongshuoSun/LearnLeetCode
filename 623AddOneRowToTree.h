//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_623ADDONEROWTOTREE_H
#define LEETCODE_623ADDONEROWTOTREE_H
#include "Common.h"
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d <= 1)
        {
            auto newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        } else{
            preOrder(root,1,v,d);
            return root;
        }
    }
    TreeNode* preOrder(TreeNode* node,int level,int v, int d)
    {
        level++;
        if(level == d)
        {
            auto left = node->left;
            auto right = node->right;
            node->left = new TreeNode(v);
            node->left = left;
            node->right = new TreeNode(v);
            node->right->right = right;
            return node;
        }
        else
        {
            preOrder(node->left,level,v,d);
            preOrder(node->right,level,v,d);
        }
    }
};
#endif //LEETCODE_623ADDONEROWTOTREE_H
