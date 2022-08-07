//
// Created by hongshuo on 2022/8/7.
//

#ifndef LEETCODE_156_H
#define LEETCODE_156_H
#include "Common.h"
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        return _DoUpsideDown(root->left,root,root->right);
    }
    TreeNode* _DoUpsideDown(TreeNode* cur,TreeNode *parent, TreeNode* rightBrother){
        if(cur== nullptr){
            return parent;
        }
        TreeNode* left = cur->left;
        TreeNode* right = cur->right;
        TreeNode* root = _DoUpsideDown(left,cur,right);
        parent->left = nullptr;
        parent->right = nullptr;
        cur->right = parent;
        cur->left = rightBrother;
        return root;
    }
};
#endif //LEETCODE_156_H
