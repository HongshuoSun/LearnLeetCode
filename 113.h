//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_113_H
#define LEETCODE_113_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        want = sum;
        if(root== nullptr){
            return ans;
        }
        vector<int> path;
        Visit(root,0,path);
        return ans;
    }
    void Visit(TreeNode* node,int current,vector<int> path){
        if(node== nullptr){
            return;
        }
        path.push_back(node->val);
        if(node->left!= nullptr || node->right!= nullptr){
            if(node->left!= nullptr){
                Visit(node->left,current+node->val,path);
            }
            if(node->right!= nullptr){
                Visit(node->right,current+node->val,path);
            }
        }else if( node->val+current == want){
            ans.push_back(path);
        }
    }
    vector<vector<int>> ans;
    int want;
};
#endif //LEETCODE_113_H
