//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_563_H
#define LEETCODE_563_H
#include "Common.h"
class Solution {
public:
    int findTilt(TreeNode* root) {
        ans = 0;
        GetNum(root);
        return ans;
    }
    int GetNum(TreeNode* node){
        if(node== nullptr){
            return 0;
        }
        int leftSum = GetNum(node->left);
        int rightSum = GetNum(node->right);
        ans+= abs(leftSum-rightSum);
        return leftSum+rightSum+node->val;
    }
    int ans;
};
#endif //LEETCODE_563_H
