//
// Created by 孙宏硕 on 2019-05-15.
//

#ifndef LEETCODE_979DISTRIBUTECOINSINBINARYTREE_H
#define LEETCODE_979DISTRIBUTECOINSINBINARYTREE_H
#include "Common.h"
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
    int dfs(TreeNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        auto left = dfs(node->left);
        auto right  = dfs(node->right);
        result+= abs(left)+abs(right);
        return left+right+node->val -1;

    }
    int result;
};
#endif //LEETCODE_979DISTRIBUTECOINSINBINARYTREE_H
