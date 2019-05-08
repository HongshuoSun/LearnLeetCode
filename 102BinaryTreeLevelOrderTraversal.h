//
// Created by sun51 on 2019/5/9.
//

#ifndef LEETCODE_102BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_102BINARYTREELEVELORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> currentLevelQueue;
        queue<TreeNode*> nextLevelQueue;
        if(root!=NULL)
        {
            nextLevelQueue.push(root);
        }
        vector<vector<int>> result;
        int currentLevelIndex =-1;
        while(!currentLevelQueue.empty()||!nextLevelQueue.empty()) {
            if (currentLevelQueue.empty()) {
                currentLevelIndex++;
                swap(currentLevelQueue, nextLevelQueue);
                result.push_back(vector<int>());
            }
            auto current = currentLevelQueue.front();
            currentLevelQueue.pop();
            result[currentLevelIndex].push_back(current->val);
            if (current->left != NULL)
                nextLevelQueue.push(current->left);
            if (current->right != NULL)
                nextLevelQueue.push(current->right);
        }
        return result;
    }
};
#endif //LEETCODE_102BINARYTREELEVELORDERTRAVERSAL_H
