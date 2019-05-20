//
// Created by 孙宏硕 on 2019-05-20.
//

#ifndef LEETCODE_404SUMOFLEFTLEAVES_H
#define LEETCODE_404SUMOFLEFTLEAVES_H
#include "Common.h"
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum= 0;
        VisiteNode(root,false);
        return sum;
    }
    int sum;
    void VisiteNode(TreeNode* node,bool isLeft)
    {
        if(node == nullptr)
        {
            return;
        }
        if(node->left== nullptr&& node->right == nullptr)
        {
            if(isLeft)
            {
                sum+=node->val;
            }
        } else{
            VisiteNode(node->left,true);
            VisiteNode(node->right,false);
        }
    }
};
#endif //LEETCODE_404SUMOFLEFTLEAVES_H
