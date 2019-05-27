//
// Created by 孙宏硕 on 2019-05-23.
//

#ifndef LEETCODE_863ALLNODESDISTANCEKINBINARYTREE_H
#define LEETCODE_863ALLNODESDISTANCEKINBINARYTREE_H
#include "Common.h"
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

    }
    bool GenPath(TreeNode* node,TreeNode* target,bool isLeft)
    {
        if(node == target)
        {
            path.push_back(make_pair(node,isLeft));
        } else{
            path.push_back(make_pair(node,isLeft));
            if()
        }
    }
    vector<pair<TreeNode*,bool>> path;
};
#endif //LEETCODE_863ALLNODESDISTANCEKINBINARYTREE_H
