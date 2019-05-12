//
// Created by sun51 on 2019/5/13.
//

#ifndef LEETCODE_236LOWESTCOMMONANCESTOROFABINARYTREE_H
#define LEETCODE_236LOWESTCOMMONANCESTOROFABINARYTREE_H

#include "Common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        anc = NULL;
        HasNode(root,p,q);
        return anc;
    }
    bool HasNode(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == NULL)
        {
            return false;
        }
        int left = HasNode(root->left,p,q)?1:0;
        int right =HasNode(root->right,p,q)?1:0;
        int mid = ((root == p)||(root == q))?1:0;
        if((mid+left+right)>1)
        {
            anc =root;
        }
        return (left+right+mid)>0?true:false;
    }
    TreeNode* anc;
};
#endif //LEETCODE_236LOWESTCOMMONANCESTOROFABINARYTREE_H
