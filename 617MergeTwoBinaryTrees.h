//
// Created by 孙宏硕 on 2019-05-07.
//

#ifndef LEETCODE_617MERGETWOBINARYTREES_H
#define LEETCODE_617MERGETWOBINARYTREES_H
#include "Common.h"
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2 == NULL)
        {
            return NULL;
        }
        else if(t1==NULL && t2!=NULL)
        {
            return t2;
        }
        else if (t1!=NULL && t2==NULL){
            return t1;
        }
        else
        {
            t1->val = t1->val+t2->val;
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);
            return t1;
        }
    }
};
#endif //LEETCODE_617MERGETWOBINARYTREES_H
