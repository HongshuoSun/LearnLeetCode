//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_530MINIMUMABSOLUTEDIFFERENCEINBST_H
#define LEETCODE_530MINIMUMABSOLUTEDIFFERENCEINBST_H

#include "Common.h"
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        hasLast = false;
        last = -1;
        min = INTMAX_MAX -1;
        std::function<void(TreeNode*)> f = [&](TreeNode* node)->void{
            if(node== nullptr)
            {
                return;
            }
            f(node->left);
            if(hasLast && abs(node->val-last)<min)
            {
                min =abs(node->val-last);
            }
            hasLast = true;
            last = node->val;
            f(node->right);
        };
        f(root);
        return min;
    }
    bool hasLast;
    int last;
    long long min;
};
#endif //LEETCODE_530MINIMUMABSOLUTEDIFFERENCEINBST_H
