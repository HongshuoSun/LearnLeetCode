//
// Created by sun51 on 2019/5/21.
//

#ifndef LEETCODE_889CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H
#define LEETCODE_889CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return GenTree(pre.begin(),pre.end(),post.begin(),post.end());
    }
    TreeNode* GenTree(
            vector<int>::iterator preBegin,vector<int>::iterator preEnd,
            vector<int>::iterator postBegin,vector<int>::iterator postEnd)
    {
        if(preBegin>=preEnd || postBegin>=postEnd)
            return nullptr;
        TreeNode* node = new TreeNode(*preBegin);
        if(preBegin+1>=preEnd)
        {
            return node;
        }
        auto left = find(postBegin,postEnd,*(preBegin+1));

        node->left = GenTree(preBegin + 1, preBegin + 1 + (left - postBegin) + 1, postBegin, left + 1);

        node->right = GenTree(preBegin+1+(left-postBegin)+1,preEnd,left+1,postEnd);
        return node;
    }
};
#endif //LEETCODE_889CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H
