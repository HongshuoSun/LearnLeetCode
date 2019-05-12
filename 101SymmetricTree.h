//
// Created by sun51 on 2019/5/13.
//

#ifndef LEETCODE_101SYMMETRICTREE_H
#define LEETCODE_101SYMMETRICTREE_H
#include "Common.h"
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        isSymmetricTree(root,root);
    }
    bool isSymmetricTree(TreeNode* left,TreeNode* right)
    {
        if(left== NULL&& right == NULL)
        {
            return true;
        }
        else if(left!=NULL && right!=NULL)
        {
            if(left->val == right->val)
            {
                return isSymmetricTree(left->right,right->left) &&isSymmetricTree(left->left,right->right);
            }else
            {
                return false;
            }
        } else{
            return false;
        }
    }
};
#endif //LEETCODE_101SYMMETRICTREE_H
