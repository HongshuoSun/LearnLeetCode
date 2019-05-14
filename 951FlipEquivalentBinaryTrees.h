//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_951FLIPEQUIVALENTBINARYTREES_H
#define LEETCODE_951FLIPEQUIVALENTBINARYTREES_H
#include "Common.h"
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)
        {
            if(root2 == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(root2 ==nullptr)
        {
            return false;
        } else{
            if(root1->val != root2->val)
            {
                return false;
            } else {
                return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
                    ||(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
            }
        }
    }
};
#endif //LEETCODE_951FLIPEQUIVALENTBINARYTREES_H
