//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_538CONVERTBSTTOGREATERTREE_H
#define LEETCODE_538CONVERTBSTTOGREATERTREE_H
#include "Common.h"
#include <functional>
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        std::function<void(TreeNode*)> f=[&](TreeNode* node)->void{
            if(node== nullptr)
            {
                return;
            }

            f(node->right);
            node->val+=sum;
            sum+= node->val-sum;
            f(node->left);
        };
        f(root);
        return root;
    }
    int sum;
};
#endif //LEETCODE_538CONVERTBSTTOGREATERTREE_H
