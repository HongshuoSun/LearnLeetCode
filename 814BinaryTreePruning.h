//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_814BINARYTREEPRUNING_H
#define LEETCODE_814BINARYTREEPRUNING_H
#include "Common.h"
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool allZero  = isAllZero(root);
        if(allZero)
        {
            return nullptr;
        }
        else
        {
            return root;
        }

    }
    bool isAllZero(TreeNode* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        bool leftZero = isAllZero(root->left);
        bool rightZero = isAllZero(root->right);
        if(leftZero)
        {
            root->left = nullptr;
        }
        if(rightZero)
        {
            root->right = nullptr;
        }
        if(root->val !=0)
        {
            return false;
        }
        else
        {
            return leftZero&&rightZero;
        }
    }
};
#endif //LEETCODE_814BINARYTREEPRUNING_H
