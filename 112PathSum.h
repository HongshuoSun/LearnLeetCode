//
// Created by sun51 on 2019/5/8.
//

#ifndef LEETCODE_112PATHSUM_H
#define LEETCODE_112PATHSUM_H
#include <iostream>
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
using namespace std;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
        {
            return false;
        }
        else if(root->left ==NULL && root->right == NULL )
        {
            return root->val == sum;
        }
        else
        {
            return hasPathSum(root->left,sum- (root->val))
                   || hasPathSum(root->right,sum- (root->val));
        }
    }
};
#endif //LEETCODE_112PATHSUM_H
