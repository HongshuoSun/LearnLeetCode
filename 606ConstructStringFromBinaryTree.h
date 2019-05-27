//
// Created by 孙宏硕 on 2019-05-23.
//

#ifndef LEETCODE_606CONSTRUCTSTRINGFROMBINARYTREE_H
#define LEETCODE_606CONSTRUCTSTRINGFROMBINARYTREE_H
#include "Common.h"
#include <sstream>
class Solution {
public:
    string tree2str(TreeNode* t) {
        ss = stringstream();
        if(t!= nullptr) {
            ss<<t->val;

            Visit(t->left);
            if(t->right!= nullptr)
            {
                Visit(t->right);
            }
        }
        return ss.str();

    }
    void Visit(TreeNode* node)
    {
        if(node == nullptr)
        {
            ss<<"()"<<endl;
            return;
        } else{
            ss<<"("<<node->val;
            if(node->left!= nullptr ||node->right!= nullptr)
            {
                Visit(node->left);
                if(node->right!= nullptr) {
                    Visit(node->right);
                }
            }
            ss<<")";
        }
    }
    stringstream ss;
};
#endif //LEETCODE_606CONSTRUCTSTRINGFROMBINARYTREE_H
