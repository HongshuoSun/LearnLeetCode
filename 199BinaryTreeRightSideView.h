//
// Created by 孙宏硕 on 2019-05-10.
//

#ifndef LEETCODE_199BINARYTREERIGHTSIDEVIEW_H
#define LEETCODE_199BINARYTREERIGHTSIDEVIEW_H
#include "Common.h"
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> currentLevelTree;
        deque<TreeNode*> nextLevelTree;
        vector<int> result;
        if(root!=NULL)
        {
            nextLevelTree.push_back(root);
        }
        while(!currentLevelTree.empty() || !nextLevelTree.empty())
        {
            if(currentLevelTree.empty())
            {
                swap(currentLevelTree,nextLevelTree);
                continue;
            }
            auto current = currentLevelTree.front();
            currentLevelTree.pop_front();
            if(currentLevelTree.empty())
            {
                result.push_back(current->val);
            }
            if(current->left)
            {
                nextLevelTree.push_back(current->left);
            }
            if(current->right)
            {
                nextLevelTree.push_back(current->right);
            }
        }
        return result;
    }
};
#endif //LEETCODE_199BINARYTREERIGHTSIDEVIEW_H
