//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_230KTHSMALLESTELEMENTINABST_H
#define LEETCODE_230KTHSMALLESTELEMENTINABST_H
#include "Common.h"
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        InOrder(root,k);
        return val;
    }
    void InOrder(TreeNode* root,int& k)
    {
        if(root == NULL)
        {
            return;
        }
        InOrder(root->left,k);
        k--;
        if(k == 0)
        {
            val = root->val;
            return;
        }
        else if(k<0)
        {
            return;
        }
        InOrder(root->right,k);
    }
    int val;
};
#endif //LEETCODE_230KTHSMALLESTELEMENTINABST_H
