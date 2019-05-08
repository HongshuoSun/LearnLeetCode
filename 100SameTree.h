//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_100SAMETREE_H
#define LEETCODE_100SAMETREE_H

#include "Common.h"
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p&&q)
        {
            return (p->val == q->val) &&isSameTree(p->left,q->left)
                   &&isSameTree(p->right,q->right);
        }
        else if(!p && !q)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif //LEETCODE_100SAMETREE_H
