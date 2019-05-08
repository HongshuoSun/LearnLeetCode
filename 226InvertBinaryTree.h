//
// Created by sun51 on 2019/5/7.
//

#ifndef LEETCODE_226INVERTBINARYTREE_H
#define LEETCODE_226INVERTBINARYTREE_H
#include "Common.h"
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
#endif //LEETCODE_226INVERTBINARYTREE_H
