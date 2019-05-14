//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_515FINDLARGESTVALUEINEACHTREEROW_H
#define LEETCODE_515FINDLARGESTVALUEINEACHTREEROW_H
#include "Common.h"
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> currentLevelQueue;
        queue<TreeNode*> nextLevelQueue;
        if(root!=NULL)
        {
            currentLevelQueue.push(root);
        }
        vector<int> result;
       int currentLargest = -1;
        bool hasVal = false;
        while(!currentLevelQueue.empty()||!nextLevelQueue.empty()) {
            if (currentLevelQueue.empty()) {

                swap(currentLevelQueue, nextLevelQueue);
                result.push_back(currentLargest);
                hasVal = false;
            }
            auto current = currentLevelQueue.front();
            currentLevelQueue.pop();
            if(!hasVal || currentLargest < current->val)
            {
                hasVal = true;
                currentLargest = current->val;
            }
            if (current->left != NULL)
                nextLevelQueue.push(current->left);
            if (current->right != NULL)
                nextLevelQueue.push(current->right);
        }
        if(hasVal)
        {
            result.push_back(currentLargest);
        }
        return result;

    }
};
#endif //LEETCODE_515FINDLARGESTVALUEINEACHTREEROW_H
