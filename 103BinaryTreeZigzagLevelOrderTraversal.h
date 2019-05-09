//
// Created by 孙宏硕 on 2019-05-09.
//

#ifndef LEETCODE_103BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define LEETCODE_103BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        list<TreeNode*> currentLevelQueue;
        list<TreeNode*> nextLevelQueue;
        if(root!=NULL)
        {
            nextLevelQueue.push_front(root);
        }
        vector<vector<int>> result;
        int currentLevelIndex =-1;
        while(!currentLevelQueue.empty()||!nextLevelQueue.empty()) {
            if (currentLevelQueue.empty()) {
                currentLevelIndex++;
                swap(currentLevelQueue, nextLevelQueue);
                result.push_back(vector<int>());
            }
            TreeNode* current = NULL;
            if((currentLevelIndex%2)>0)
            {
                current =  currentLevelQueue.back();
                currentLevelQueue.pop_back();
                result[currentLevelIndex].push_back(current->val);
                if (current->right != NULL)
                    nextLevelQueue.push_front(current->right);
                if (current->left != NULL)
                    nextLevelQueue.push_front(current->left);
            } else{
                current =  currentLevelQueue.front();
                currentLevelQueue.pop_front();
                result[currentLevelIndex].push_back(current->val);
                if (current->left != NULL)
                    nextLevelQueue.push_back(current->left);

                if (current->right != NULL)
                    nextLevelQueue.push_back(current->right);
            }


        }
        return result;
    }
};

#endif //LEETCODE_103BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
