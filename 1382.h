//
// Created by Administrator on 2020/5/13.
//

#ifndef LEETCODE_1382_H
#define LEETCODE_1382_H

#include "Common.h"
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vals.clear();
        Visit(root);
        return build(vals.begin(),vals.end());
    }
private:
    TreeNode* build(vector<int>::iterator begin,vector<int>::iterator end)
    {
        if(begin>=end){
            return nullptr;
        }
        auto mid = (end-begin)/2+begin;
        TreeNode* node = new TreeNode(*mid);
        node->left = build(begin,mid);
        node->right = build(mid+1,end);
        return node;
    }
    void Visit(TreeNode* node){
        if(node== nullptr){
            return;
        }
        Visit(node->left);
        vals.push_back(node->val);
        Visit(node->right);
    }
    vector<int> vals;
};
#endif //LEETCODE_1382_H
