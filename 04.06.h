//
// Created by bugma on 2021/3/29.
//

#ifndef LEETCODE_04_06_H
#define LEETCODE_04_06_H
#include "Common.h"
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> treeStack;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        while(node!= nullptr ||!treeStack.empty()){
            while(node!= nullptr){
                treeStack.push(node);
                node = node->left;
            }
            node = treeStack.top();
            if(last == p){
                return node;
            }
            last = node;
            treeStack.pop();
            node = node->right;
        }
        return nullptr;
    }
};
#endif //LEETCODE_04_06_H
