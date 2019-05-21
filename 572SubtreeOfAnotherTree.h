//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_572SUBTREEOFANOTHERTREE_H
#define LEETCODE_572SUBTREEOFANOTHERTREE_H

#include "Common.h"
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s== nullptr)
        {
            return t == nullptr;
        } else {
            return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
   bool isSameTree(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) {
            return true;
        } else if (s != nullptr && t != nullptr) {
            if (s->val != t->val) {
                return false;
            } else {
                return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
            }
        } else {
            return false;
        }
    };
};
#endif //LEETCODE_572SUBTREEOFANOTHERTREE_H
