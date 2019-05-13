//
// Created by sun51 on 2019/5/13.
//

#ifndef LEETCODE_98VALIDATEBINARYSEARCHTREE_H
#define LEETCODE_98VALIDATEBINARYSEARCHTREE_H
#include "Common.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool hasFirst = false;
        stack<TreeNode*> myStack;
        set<TreeNode*> visited;
        int last = -1;
        if(root!=NULL)
        {
            myStack.push(root);
        }
        while(!myStack.empty())
        {
            auto current = myStack.top();
            if(current->left == NULL || visited.find(current->left)!=visited.end())
            {
                if(hasFirst)
                {
                    if(current->val < last)
                    {
                        return false;
                    }
                } else{
                    hasFirst = true;
                    last = current->val;
                }
                last = current->val;
                myStack.pop();
                visited.insert(current);
                if(current->right)
                {
                    myStack.push(current->right);
                }
            } else{
                myStack.push(current->left);
            }
        }
        return true;
    }

};
#endif //LEETCODE_98VALIDATEBINARYSEARCHTREE_H
