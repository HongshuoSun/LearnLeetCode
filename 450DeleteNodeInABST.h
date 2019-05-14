//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_450DELETENODEINABST_H
#define LEETCODE_450DELETENODEINABST_H
#include "Common.h"
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
        {
            return nullptr;
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
            return root;
        } else{
            if(root->left== nullptr )
            {
                return root->right;
            }
            else if(root->right == nullptr)
            {
                return root->left;
            }
            else
            {
                TreeNode* node = root->right;
                while(node->left!=nullptr)
                {
                    node = node->left;
                }
                root->val = node->val;
                root->right = deleteNode(root->right,node->val);
                return root;
            }
        }
    }
};
#endif //LEETCODE_450DELETENODEINABST_H
