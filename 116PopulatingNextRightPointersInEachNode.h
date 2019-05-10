//
// Created by 孙宏硕 on 2019-05-10.
//

#ifndef LEETCODE_116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
#define LEETCODE_116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H

#include "Common.h"
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
        deque<Node*> currentLevelTree;
        deque<Node*> nextLevelTree;
        if(root!= nullptr)
        {
            nextLevelTree.push_back(root);
        }
        Node* last = nullptr;
        while(!currentLevelTree.empty() || !nextLevelTree.empty())
        {
            if(currentLevelTree.empty())
            {
                swap(currentLevelTree,nextLevelTree);
                last = nullptr;
                continue;
            }
            auto current = currentLevelTree.front();
            currentLevelTree.pop_front();
            current->next = last;
            last = current;
            if(current->right)
            {
                nextLevelTree.push_back(current->right);
            }
            if(current->left)
            {
                nextLevelTree.push_back(current->left);
            }

        }
        return root;
    }
};
#endif //LEETCODE_116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
