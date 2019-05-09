//
// Created by 孙宏硕 on 2019-05-09.
//

#ifndef LEETCODE_235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
#define LEETCODE_235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
#include "Common.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        else
        {
            if( p->val <root->val&& q->val < root->val)
            {
                return lowestCommonAncestor(root->left,p,q);
            }
            else if(p->val> root->val &&q->val>root->val )
            {
                return lowestCommonAncestor(root->right,p,q);
            }
            else
            {
                return root;
            }
        }
    }
};

#endif //LEETCODE_235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
