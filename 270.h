//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_270_H
#define LEETCODE_270_H
#include "Common.h"
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = 0;
        stack<TreeNode*> visitStack;
        while(root!= nullptr){
            ans =root->val;
            visitStack.push(root);
            root = root->left;

        }
        while(!visitStack.empty()){
            auto current = visitStack.top();
            visitStack.pop();
            if( abs(ans-target) > abs(current->val-target)){
                ans = current->val;
            }
            if(current->right!= nullptr){
                current = current->right;
                visitStack.push(current);
                current = current->left;
                while(current!= nullptr){
                    visitStack.push(current);
                    current = current->left;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_270_H
