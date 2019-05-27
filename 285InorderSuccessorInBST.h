//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_285INORDERSUCCESSORINBST_H
#define LEETCODE_285INORDERSUCCESSORINBST_H
#include "Common.h"
/*
class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *result = nullptr;
        bool find = false;
        stack<pair<TreeNode *, int>> myStack;
        if (root != nullptr) {
            myStack.push(make_pair(root, 0));
        }
        while (!myStack.empty()) {
            auto top = myStack.top();
            if (top.second > 0 || top.first->left == nullptr) {
                myStack.pop();
                if (find) {
                    result = top.first;
                    break;
                }
                if (top.first == p) {
                    find = true;
                }
                if (top.first->right != nullptr) {
                    myStack.push(make_pair(top.first->right, 0));
                }
            } else {
                myStack.pop();
                myStack.push(make_pair(top.first, 1));
                myStack.push(make_pair(top.first->left, 0));
            }
        }
        return result;
    }
};
 */

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr){
            return nullptr;
        }
        hot = nullptr;
        return Visit(root,p);
    }
    TreeNode* Visit(TreeNode* node,TreeNode* p) {
        while (node != nullptr) {
            if (node->val == p->val) {
                if(node->right!=nullptr){
                    auto result = node->right;
                    while(result->left!= nullptr){
                        result = result->left;
                    }
                    return result;
                }else{
                    return hot;
                }
            } else if (node->val > p->val) {
                hot = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return nullptr;
    }
    TreeNode* hot;
};
#endif //LEETCODE_285INORDERSUCCESSORINBST_H
