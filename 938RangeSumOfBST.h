//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_938RANGESUMOFBST_H
#define LEETCODE_938RANGESUMOFBST_H
#include <iostream>

#include "Common.h"
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
        {
            return 0;
        }
        int sum = 0;
        set<TreeNode*> visited;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty())
        {
            auto current = myStack.top();
            if(  current->left == NULL || visited.find(current->left)!= visited.end() )
            {
                if( L<= current->val && current->val <=R)
                {
                    sum+= current->val;
                }
                else if(current->val > R)
                {
                    break;
                }
                visited.insert(current);
                myStack.pop();
                if(current->right!=NULL)
                {
                    myStack.push(current->right);
                }
            }
            else if(current->left!=NULL)
            {
                myStack.push(current->left);
            }
        }
        return sum;
    }
};

#endif //LEETCODE_938RANGESUMOFBST_H
