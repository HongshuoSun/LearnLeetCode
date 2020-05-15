//
// Created by Administrator on 2020/5/13.
//

#ifndef LEETCODE_102_H
#define LEETCODE_102_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        if(root!= nullptr){
            next.push(root);
        }
        while(!next.empty()){
            swap(next,current);
            ans.push_back(vector<int>());
            int index = ans.size()-1;
            while(!current.empty()){
                auto node = current.front();
                current.pop();
                ans[index].push_back(node->val);
                if(node->left!= nullptr){
                    next.push(node->left);
                }
                if(node->right!= nullptr){
                    next.push(node->right);
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_102_H
