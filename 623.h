//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_623_H
#define LEETCODE_623_H
#include "Common.h"
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d,bool isLeft = true) {
        if(d<=0 ){
            return root;
        }
        else if(d==1){
            TreeNode* node = new TreeNode(v);
            if(isLeft){
                node->left = root;
            }else{
                node->right = root;
            }
            return node;
        }else if(root!= nullptr){
            root->left = addOneRow(root->left,v,d-1,true);
            root->right = addOneRow(root->right,v,d-1,false);
            return root;
        }else{
            return nullptr;
        }
    }
};
#endif //LEETCODE_623_H
