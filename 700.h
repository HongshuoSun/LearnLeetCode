//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_700_H
#define LEETCODE_700_H
#include "Common.h"
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root== nullptr){
            return root;
        }
        else if( root->val <val){
            return searchBST(root->right,val);
        }else if(root->val > val){
            return searchBST(root->left,val);
        }else{
            return root;
        }
    }
};
#endif //LEETCODE_700_H
