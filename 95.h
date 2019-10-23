//
// Created by Administrator on 2019/10/23.
//

#ifndef LEETCODE_95_H
#define LEETCODE_95_H
#include "Common.h"
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i=1;i<=n;i++){
            vector<TreeNode*> lefts = getSubTree(1,i-1);
            vector<TreeNode*> rights = getSubTree(i+1,n);

            for(auto left:lefts){
                for(auto right:rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> getSubTree(int begin,int end){
        vector<TreeNode*> ans;
        if(begin>end ){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=begin;i<=end;i++){

            vector<TreeNode*> lefts = getSubTree(begin,i-1);
            vector<TreeNode*> rights = getSubTree(i+1,end);
            for(auto left:lefts){
                for(auto right:rights){
                    TreeNode* root = new TreeNode(i);
                    root->right = right;
                    root->left = left;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_95_H
