//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_107BINARYTREELEVELORDERTRAVERSALII_H
#define LEETCODE_107BINARYTREELEVELORDERTRAVERSALII_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(result.begin(),result.end());
        return result;
    }
};
#endif //LEETCODE_107BINARYTREELEVELORDERTRAVERSALII_H
