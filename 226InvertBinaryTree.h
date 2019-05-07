//
// Created by sun51 on 2019/5/7.
//

#ifndef LEETCODE_226INVERTBINARYTREE_H
#define LEETCODE_226INVERTBINARYTREE_H
#include <iostream>
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
#include <algorithm>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
#endif //LEETCODE_226INVERTBINARYTREE_H
