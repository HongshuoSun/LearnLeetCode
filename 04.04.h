//
// Created by bugma on 2021/3/29.
//

#ifndef LEETCODE_04_04_H
#define LEETCODE_04_04_H
#include "Common.h"
class Solution {
public:
    bool Depth(TreeNode* root,int& depth){
        if(root== nullptr){
            depth=0;
            return true;
        }else{
            int leftDepth=0,rightDepth=0;
            bool leftAns = Depth(root->left,leftDepth);
            bool rightAns = Depth(root->right,rightDepth);
            depth = std::max(leftDepth,rightDepth)+1;
            return leftAns&&rightAns &&  std::abs(leftDepth-rightDepth)<2 ;
        }
    }
    bool isBalanced(TreeNode* root) {
        int rootDepth = 0;
        return Depth(root,rootDepth);
    }

};
#endif //LEETCODE_04_04_H
