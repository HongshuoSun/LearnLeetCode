//
// Created by 孙宏硕 on 2019-05-13.
//

#ifndef LEETCODE_513FINDBOTTOMLEFTTREEVALUE_H
#define LEETCODE_513FINDBOTTOMLEFTTREEVALUE_H

#include "Common.h"
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> currentLevelQueue;
        queue<TreeNode*> nextLevelQueue;
        if(root!=NULL)
        {
            nextLevelQueue.push(root);
        }
        int result = 0;
        int currentLevelIndex =-1;
        int firstFlag = false;
        while(!currentLevelQueue.empty()||!nextLevelQueue.empty()) {
            if (currentLevelQueue.empty()) {
                currentLevelIndex++;
                swap(currentLevelQueue, nextLevelQueue);
                firstFlag = true;
            }
            auto current = currentLevelQueue.front();
            currentLevelQueue.pop();
            if(firstFlag)
            {
                result = current->val;
                firstFlag = false;
            }
            if (current->left != NULL)
                nextLevelQueue.push(current->left);
            if (current->right != NULL)
                nextLevelQueue.push(current->right);
        }
        return result;
    }

};
#endif //LEETCODE_513FINDBOTTOMLEFTTREEVALUE_H
