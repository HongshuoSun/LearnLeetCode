//
// Created by 孙宏硕 on 2019-05-20.
//

#ifndef LEETCODE_637AVERAGEOFLEVELSINBINARYTREE_H
#define LEETCODE_637AVERAGEOFLEVELSINBINARYTREE_H
#include "Common.h"
class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> currentLevelQueue;
        queue<TreeNode *> nextLevelQueue;
        if (root != NULL) {
            nextLevelQueue.push(root);
        }
        vector<double> result;
        int currentLevelNodeCount = -1;
        long sum = 0;
        while (true) {
            if (currentLevelQueue.empty()) {

                swap(currentLevelQueue, nextLevelQueue);
                if(currentLevelNodeCount > 0)
                {
                    result.push_back((double)sum/currentLevelNodeCount);
                }
                currentLevelNodeCount = currentLevelQueue.size();
                sum = 0;
                if(currentLevelQueue.empty())
                {
                    break;
                }
            }
            auto current = currentLevelQueue.front();
            currentLevelQueue.pop();
            sum+=current->val;
            if (current->left != NULL)
                nextLevelQueue.push(current->left);
            if (current->right != NULL)
                nextLevelQueue.push(current->right);
        }
        return result;
    }
};
#endif //LEETCODE_637AVERAGEOFLEVELSINBINARYTREE_H
