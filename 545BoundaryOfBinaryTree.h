//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_545BOUNDARYOFBINARYTREE_H
#define LEETCODE_545BOUNDARYOFBINARYTREE_H
#include "Common.h"
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> lastLine;
        vector<int> last;
        vector<int> first;
        vector<int> lastLevel;
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

    }
};
#endif //LEETCODE_545BOUNDARYOFBINARYTREE_H
