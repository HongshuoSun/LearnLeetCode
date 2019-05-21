//
// Created by sun51 on 2019/5/18.
//

#ifndef LEETCODE_508MOSTFREQUENTSUBTREESUM_H
#define LEETCODE_508MOSTFREQUENTSUBTREESUM_H

#include "Common.h"
#include <functional>
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxCount = -1;
        int currentCount = -1;
        map<int,int> sumMap;
        vector<int> result;
        std::function<int(TreeNode*)> f = [&maxCount,&currentCount,&sumMap,&f,&result](TreeNode* node)->int{
            if(node== nullptr)
            {
                return 0;
            }
            int leftSum = 0;
            int rightSum = 0;
            if(node->left!= nullptr)
            {
                leftSum = f(node->left);
            }
            if(node->right!= nullptr)
            {
                rightSum = f(node->right);
            }
            int treeSum = node->val+leftSum+rightSum;
            sumMap[treeSum]++;
            if(sumMap[treeSum]>maxCount)
            {
                maxCount =sumMap[treeSum];
                result.clear();
                result.push_back(treeSum);
            }
            else if(sumMap[treeSum]==maxCount)
            {
                result.push_back(treeSum);
            }
            return treeSum;
        };
        f(root);
        return result;
    }
};
#endif //LEETCODE_508MOSTFREQUENTSUBTREESUM_H
