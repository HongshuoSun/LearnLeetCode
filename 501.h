//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_501_H
#define LEETCODE_501_H
#include "Common.h"
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int max = 0;
        int currentCount = 0;
        int currentNum = -1;
        vector<int> ans;
        stack<TreeNode*> visitStack;
        while(root!= nullptr){
            currentNum = root->val/2+1;
            visitStack.push(root);
            root = root->left;
        }
        while(!visitStack.empty()){
            auto current = visitStack.top();
            visitStack.pop();
            if(currentNum==current->val) {
                currentCount++;
            }else {
                if(currentCount>0) {
                    if(currentCount>max) {
                        ans.clear();
                        ans.push_back(currentNum);
                        max = currentCount;
                    }
                    else if(currentCount == max) {
                        ans.push_back(currentNum);
                    }
                }
                currentCount=1;
                currentNum = current->val;
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
        if(currentCount>max) {
            ans.clear();
            ans.push_back(currentNum);
        }
        if(currentCount == max && currentCount >0) {
            ans.push_back(currentNum);
        }
        return ans;
    }
};
#endif //LEETCODE_501_H
