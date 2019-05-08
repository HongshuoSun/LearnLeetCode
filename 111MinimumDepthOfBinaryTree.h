//
// Created by sun51 on 2019/5/9.
//

#ifndef LEETCODE_111MINIMUMDEPTHOFBINARYTREE_H
#define LEETCODE_111MINIMUMDEPTHOFBINARYTREE_H

#include "Common.h"
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            if(root->left!=NULL && root->right!=NULL)
            {
                return min(minDepth(root->left),minDepth(root->right))+1;
            }
            else if(root->left!=NULL)
            {
                return minDepth(root->left)+1;
            }
            else
            {
                return minDepth(root->right)+1;
            }
        }
    }
};
#endif //LEETCODE_111MINIMUMDEPTHOFBINARYTREE_H
