//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_108CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#define LEETCODE_108CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#include "Common.h"
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return GenTree(nums,0,nums.size());
    }
    TreeNode* GenTree(vector<int>& nums,int begin,int end)
    {
        if(begin == end)
        {
            return NULL;
        }
        else
        {
            int mid = (begin+end)/2;
            int val = nums[mid];
            TreeNode* node = new TreeNode(val);
            node->left = GenTree(nums,begin,mid);
            node->right = GenTree(nums,mid+1,end);
            return node;
        }
    }
};
#endif //LEETCODE_108CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
