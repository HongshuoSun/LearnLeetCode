//
// Created by sun51 on 2019/5/22.
//

#ifndef LEETCODE_366_FINDLEAVESOFBINARYTREE_H
#define LEETCODE_366_FINDLEAVESOFBINARYTREE_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        result = vector<vector<int>>();
        ColHeight(root);
        return result;
    }
    int ColHeight(TreeNode* root)
    {
        if(root == nullptr)
        {
            return -1;
        }
        int height = std::max(ColHeight(root->left),ColHeight(root->right))+1;
        while(result.size()<=height)
        {
            result.push_back(vector<int>());
        }
        result[height].push_back(root->val);
        return height;
    }
    vector<vector<int>> result;
};
#endif //LEETCODE_366_FINDLEAVESOFBINARYTREE_H
