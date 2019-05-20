//
// Created by 孙宏硕 on 2019-05-20.
//

#ifndef LEETCODE_429N_ARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_429N_ARYTREELEVELORDERTRAVERSAL_H
#include "Common.h"

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> currentLevelQueue;
        queue<Node*> nextLevelQueue;
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
            for(auto i:current->children)
            {
                if(i!= nullptr)
                {
                    nextLevelQueue.push(i);
                }
            }
        }
        return result;
    }
};
#endif //LEETCODE_429N_ARYTREELEVELORDERTRAVERSAL_H
