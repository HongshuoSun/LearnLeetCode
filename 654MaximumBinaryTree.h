//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_654MAXIMUMBINARYTREE_H
#define LEETCODE_654MAXIMUMBINARYTREE_H
#include "Common.h"
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return genSubTree(nums,0,nums.size());
    }
    TreeNode* genSubTree(vector<int>& nums,int begin,int end)
    {
        if( begin >= end )
        {
            return NULL;
        }
        TreeNode* root = NULL;
        int maxIndex = GetMaxIndex(nums, begin, end);
        root = new TreeNode(nums[maxIndex]);
        root->left =  genSubTree(nums,begin,maxIndex);
        root->right = genSubTree(nums,maxIndex+1,end);
        return root;

    }
    inline int GetMaxIndex(vector<int>& nums, int begin,int end)
    {
        int maxIndex = begin;
        for(int i=begin+1;i<end;i++)
        {
            if(nums[i]> nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

};
#endif //LEETCODE_654MAXIMUMBINARYTREE_H
