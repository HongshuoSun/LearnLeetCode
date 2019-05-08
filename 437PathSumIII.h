//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_437PATHSUMIII_H
#define LEETCODE_437PATHSUMIII_H

#include "Common.h"
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
        {
            return 0;
        }
        return (( sum == root->val)?1:0) +pathSum(root->left,sum,false)+pathSum(root->right,sum,false)+pathSum(root->left,sum-root->val,true)+pathSum(root->right,sum-root->val,true);
    }
    int pathSum(TreeNode* root, int sum,bool hasBeenConsume)
    {
        if(root == NULL)
        {
            return 0;
        }
        int count = 0;

        if(hasBeenConsume)
        {
            count =pathSum(root->left,sum-root->val,true)+pathSum(root->right,sum-root->val,true) + (( sum == root->val)?1:0);
        } else{
            count = pathSum(root->left,sum,false)+pathSum(root->right,sum,false)+pathSum(root->left,sum-root->val,true)+pathSum(root->right,sum-root->val,true)+ (( sum == root->val)?1:0);
        }
        return count;
    }
};
#endif //LEETCODE_437PATHSUMIII_H
