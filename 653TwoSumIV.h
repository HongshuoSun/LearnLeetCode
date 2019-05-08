//
// Created by 孙宏硕 on 2019-05-06.
//

#ifndef LEETCODE_653TWOSUMIV_H
#define LEETCODE_653TWOSUMIV_H

#include "Common.h"
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        vector<int> nums;
        TreeNode* current = root;
        stack<TreeNode*> myStack;
        myStack.push(root);
        set<TreeNode*> visited;
        while(!myStack.empty())
        {
            auto current = myStack.top();
            if(current->left!=nullptr && visited.find(current->left) == visited.cend())
            {
                myStack.push(current->left);
            }
            else if(current->left==nullptr ||visited.find(current->left)!= visited.cend())
            {
                nums.push_back(current->val);
                myStack.pop();
                visited.insert(current);
                if(current->right!=nullptr )
                {
                    myStack.push(current->right);
                }

            }

        }

        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {

                if (nums[i]+nums[j]==k)
                {
                    return true;
                }
                if (nums[i]+nums[j]>k)
                {
                    break;
                }

            }
        }
        return false;

    }

};

#endif //LEETCODE_653TWOSUMIV_H
