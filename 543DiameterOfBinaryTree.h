//
// Created by sun51 on 2019/5/17.
//

#ifndef LEETCODE_543DIAMETEROFBINARYTREE_H
#define LEETCODE_543DIAMETEROFBINARYTREE_H

#include "Common.h"
class Solution {
public:
    int result;
    int diameterOfBinaryTree(TreeNode* root) {
        GetDepth(root);
        return result;
    }
    int GetDepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        auto leftDepth= GetDepth(root->left);
        auto rightDepth = GetDepth(root->right);
        auto pathLenght =  leftDepth+rightDepth;
        result = std::max(result,pathLenght);
        return 1+std::max(leftDepth,rightDepth);
    }
};
#endif //LEETCODE_543DIAMETEROFBINARYTREE_H
