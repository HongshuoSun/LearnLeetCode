//
// Created by sun51 on 2019/5/23.
//

#ifndef LEETCODE_894ALLPOSSIBLEFULLBINARYTREES_H
#define LEETCODE_894ALLPOSSIBLEFULLBINARYTREES_H
#include "Common.h"
class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int N) {
        if(N<=0)
        {
            return vector<TreeNode *>();
        }
        if(N == 1)
        {
            cache[1] =  vector<TreeNode*>(1,new TreeNode(0));
            return  cache[1];
        }
        if(cache.find(N)!=cache.end())
        {
            return cache[N];
        }
        vector<TreeNode*> result;
        for(int left=1;left<N;left+=2)
        {
            int right = N-left-1;
            for(auto lt:allPossibleFBT(left))
            {
                for(auto rt:allPossibleFBT(right))
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = lt;
                    root->right = rt;
                    result.push_back(root);
                }

            }
        }
        cache[N] = result;
        return result;
    }
    map<int,vector<TreeNode*>> cache;

} ;

#endif //LEETCODE_894ALLPOSSIBLEFULLBINARYTREES_H
