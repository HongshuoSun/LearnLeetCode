//
// Created by 孙宏硕 on 2019-05-09.
//

#ifndef LEETCODE_109CONVERTSORTEDLISTTOBINARYSEARCHTREE_H
#define LEETCODE_109CONVERTSORTEDLISTTOBINARYSEARCHTREE_H

#include "Common.h"
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for(ListNode* current = head;current!=NULL;current = current->next)
        {
            nums.push_back(current->val);
        }
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

#endif //LEETCODE_109CONVERTSORTEDLISTTOBINARYSEARCHTREE_H
