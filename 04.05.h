//
// Created by bugma on 2021/3/29.
//

#ifndef LEETCODE_04_05_H
#define LEETCODE_04_05_H
#include "Common.h"



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> treeStack;
        TreeNode* node = root;

        bool hasLast =false;
        int last = -1;
        while(node!= nullptr ||!treeStack.empty()){
            while(node!= nullptr){
                treeStack.push(node);
                node = node->left;
            }
            node = treeStack.top();
            treeStack.pop();
            if(hasLast){
                if(last>=node->val){
                    return false;
                }
                last = node->val;
            }else{
                hasLast=true;
                last = node->val;
            }
            node = node->right;
        }
        return true;
    }
};
#endif //LEETCODE_04_05_H
