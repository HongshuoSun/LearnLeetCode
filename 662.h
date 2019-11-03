//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_662_H
#define LEETCODE_662_H
#include "Common.h"
class Solution {
public:
    map<unsigned  long long, unsigned  long long> L;
    map<unsigned  long long, unsigned  long long> R;
    void helper(TreeNode* root, unsigned  long long d, unsigned  long long x) {
        if (root == NULL) return;
        if (L.count(d) == 0) L[d] = x;
        if (R.count(d) == 0) R[d] = x;
        L[d] = min(L[d], x);
        R[d] = max(R[d], x);
        helper(root->left, d + 1, 2 * x);
        helper(root->right, d + 1, 2 * x + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        L.clear();
        R.clear();
        if (root == NULL) return 0;
        helper(root, 0, 0);
        unsigned  long long res = 0;
        for (auto& p : L) res = max(res, R[p.first] - p.second + 1);
        return res;
    }
};

#endif //LEETCODE_662_H
