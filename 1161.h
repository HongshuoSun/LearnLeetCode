//
// Created by Administrator on 2020/5/21.
//

#ifndef LEETCODE_1161_H
#define LEETCODE_1161_H
#include "Common.h"
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        int sum = - 0xffffff;
        if(root!= nullptr){
            next.push(root);
        }
        int level;
        int i=0;
        while(!next.empty()){
            i++;
            swap(current,next);
            sum=0;
            while(!current.empty()){
                auto node = current.front();
                current.pop();
                sum+=node->val;
                if(node->left){
                    next.push(node->left);
                }
                if(node->right){
                    next.push(node->right);
                }
            }
            if(ans<sum){
                ans = sum;
                level =i;
            }
        }
        return level;
    }
};
#endif //LEETCODE_1161_H
