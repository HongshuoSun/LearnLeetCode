//
// Created by sun51 on 2019/5/9.
//

#ifndef LEETCODE_104MAXIMUMDEPTHOFBINARYTREE_H
#define LEETCODE_104MAXIMUMDEPTHOFBINARYTREE_H

#include "Common.h"
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
#endif //LEETCODE_104MAXIMUMDEPTHOFBINARYTREE_H
