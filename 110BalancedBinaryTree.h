//
// Created by sun51 on 2019/5/9.
//

#ifndef LEETCODE_110BALANCEDBINARYTREE_H
#define LEETCODE_110BALANCEDBINARYTREE_H

#include "Common.h"
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        if(abs(GetHeight(root->left)-GetHeight(root->right))<2)
        {
            if(isBalanced(root->left)&&isBalanced(root->right))
            {
                return true;
            }
        }
        return false;
    }
    int GetHeight(TreeNode* root)
    {
        if(root ==NULL)
        {
            return 0;
        }
        else
        {
            return max(GetHeight(root->left),GetHeight(root->right))+1;
        }
    }
};
#endif //LEETCODE_110BALANCEDBINARYTREE_H
