//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_965_H
#define LEETCODE_965_H
#include "Common.h"
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        else{
            return isUnivalTree(root->left,root->val) && isUnivalTree(root->right,root->val);
        }
    }
    bool isUnivalTree(TreeNode* node,int val){
        if(node== nullptr){
            return true;
        }
        else if(node->val!=val){
            return false;
        }else{
            return isUnivalTree(node->left,val)&& isUnivalTree(node->right,val);
        }
    }
};
#endif //LEETCODE_965_H
