//
// Created by 孙宏硕 on 2019-05-14.
//

#ifndef LEETCODE_776SPLITBST_H
#define LEETCODE_776SPLITBST_H
#include "Common.h"
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        parent = nullptr;
        TreeNode* node = FindNode(root,V);
        vector<TreeNode*> result;
        if(parent == nullptr && node!= nullptr)
        {
            result.push_back(node);
            result.push_back(node->right);
            node->right = nullptr;
        }
        else if(parent != nullptr && node!= nullptr)
        {
            if(parent->left == node)
            {
                parent->left = node->right;
                node->right = nullptr;
            }
            else
            {
                parent->right = node->left;
                node->left = nullptr;
            }
            result.push_back(node);
            result.push_back(root);
        } else{
            result.push_back(nullptr);
            result.push_back(nullptr);
        }
        return result;
    }
    TreeNode* FindNode(TreeNode* node,int v)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->val<v)
        {
           auto result =  FindNode(node->right,v);
           if(result == node->right)
           {
               parent = node;
           }
           return result;
        } else if(node->val > v)
        {
            auto result =  FindNode(node->left,v);
            if(result == node->left)
            {
                parent = node;
            }
            return result;
        }
        else
        {
            return node;
        }
    }
    TreeNode* parent;
};
#endif //LEETCODE_776SPLITBST_H
