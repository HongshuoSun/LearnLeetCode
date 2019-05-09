//
// Created by sun51 on 2019/5/10.
//

#ifndef LEETCODE_106CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
#define LEETCODE_106CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = genSubTree(postorder.begin(),postorder.end(),inorder.begin(),inorder.end());
        return root;
    }
    TreeNode* genSubTree(vector<int>::const_iterator pB,vector<int>::const_iterator pE
            ,vector<int>::const_iterator iB,vector<int>::const_iterator iE)
    {
        if(pB>=pE||iB>=iE)
        {
            return NULL;
        }
        int val = *(pE-1);
        auto vIndexInInorder = find(iB,iE,val);
        TreeNode* node = new TreeNode(val);
        node->left = genSubTree(pB,pB+(vIndexInInorder-iB)+1,iB,vIndexInInorder);
        node->right = genSubTree(pB+(vIndexInInorder-iB)+1,pE-1,vIndexInInorder+1,iE);
        return node;
    }
};
#endif //LEETCODE_106CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
