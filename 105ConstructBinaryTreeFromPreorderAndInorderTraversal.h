//
// Created by sun51 on 2019/5/9.
//

#ifndef LEETCODE_105CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#define LEETCODE_105CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H

#include "Common.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        TreeNode* root = genSubTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
        return root;
    }
    TreeNode* genSubTree(vector<int>::const_iterator pB,vector<int>::const_iterator pE
            ,vector<int>::const_iterator iB,vector<int>::const_iterator iE)
    {
        if(pB>=pE||iB>=iE)
        {
            return NULL;
        }
        int val = *pB;
        auto vIndexInInorder = find(iB,iE,val);
        TreeNode* node = new TreeNode(val);
        node->left = genSubTree(pB+1,pB+(vIndexInInorder-iB)+1,iB,vIndexInInorder);
        node->right = genSubTree(pB+(vIndexInInorder-iB)+1,pE,vIndexInInorder+1,iE);
        return node;
    }
};
#endif //LEETCODE_105CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
