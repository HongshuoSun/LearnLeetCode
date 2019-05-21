//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_250COUNTUNIVALUESUBTREES_H
#define LEETCODE_250COUNTUNIVALUESUBTREES_H
#include "Common.h"
class Solution {
public:
    int result;
    int countUnivalSubtrees(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        result = 0;
        isSame(root);
        return result;
    }
    bool isSame(TreeNode* node)
    {
        if(node== nullptr)
        {
            return true;
        }
        if(node->left== nullptr&& node->right== nullptr)
        {
            result++;
            return true;
        }
        else
        {
            bool flagL = true;
            bool falgR = true;
            if(node->left!=nullptr)
            {
                flagL = isSame(node->left)&& node->left->val == node->val;
            }
            if(node->right!= nullptr)
            {
                falgR = isSame(node->right)&& node->right->val == node->val;
            }
            if(flagL&&falgR)
            {
                result++;
            }
            return flagL&&falgR;
        }
    }
};
#endif //LEETCODE_250COUNTUNIVALUESUBTREES_H
