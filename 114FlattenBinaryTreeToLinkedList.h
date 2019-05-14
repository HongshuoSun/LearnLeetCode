//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_114FLATTENBINARYTREETOLINKEDLIST_H
#define LEETCODE_114FLATTENBINARYTREETOLINKEDLIST_H
#include "Common.h"
class Solution {
public:
    void flatten(TreeNode* root) {
        lastRight = root;
        while(lastRight!=NULL && lastRight->right!=NULL)
        {
            lastRight = lastRight->right;
        }
        ChangeToRight(root->left,false);
        ChangeToRight(root->right,true);
        root->left = NULL;

    }
    void ChangeToRight(TreeNode* node,bool isRightSubTree)
    {
       if(node == NULL)
       {
           return;
       }

        if(isRightSubTree)
        {
            auto left = node->left;
            node->left = NULL;
            ChangeToRight(left,false);
            ChangeToRight(node->right,true);
        }
        else
        {
            lastRight->right = node;
            auto left = node->left;
            auto right = node->right;
            node->left = node->right = NULL;
            lastRight  = lastRight->right;
            ChangeToRight(left,false);
            ChangeToRight(right,false);
        }
    }

    TreeNode* lastRight = NULL;
};
#endif //LEETCODE_114FLATTENBINARYTREETOLINKEDLIST_H
