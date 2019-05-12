//
// Created by sun51 on 2019/5/13.
//

#ifndef LEETCODE_129SUMROOTTOLEAFNUMBERS_H
#define LEETCODE_129SUMROOTTOLEAFNUMBERS_H
#include "Common.h"
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNum(root,0,sum);
        return sum;
    }
    void sumNum(TreeNode*root ,int num,int& sum)
    {
        if(root ==NULL)
        {

        }
        else if(root->left== NULL && root->right == NULL)
        {
            sum+= num*10+root->val;
        }
        else
        {
            if(root->left!=NULL)
            {
                sumNum(root->left,num*10+root->val,sum);
            }
            if(root->right!=NULL)
            {
                sumNum(root->right,num*10+root->val,sum);
            }
        }
    }
};
#endif //LEETCODE_129SUMROOTTOLEAFNUMBERS_H
