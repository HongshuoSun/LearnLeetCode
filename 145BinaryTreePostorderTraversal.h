//
// Created by 孙宏硕 on 2019-05-20.
//

#ifndef LEETCODE_145BINARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODE_145BINARYTREEPOSTORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        unordered_set<TreeNode*> visited;
        stack<TreeNode*> myStack;
        if(root!= nullptr)
        {
            myStack.push(root);
        }
        while(!myStack.empty()) {
            auto current = myStack.top();
            if (current->left == nullptr || visited.find(current->left) != visited.end()) {
                if (current->right == nullptr || visited.find(current->right) != visited.end()) {
                    result.push_back(current->val);
                    visited.insert(current);
                    myStack.pop();
                } else {
                    myStack.push(current->right);
                }
            } else {
                myStack.push(current->left);
            }
        }
        return result;
    }
};
#endif //LEETCODE_145BINARYTREEPOSTORDERTRAVERSAL_H
