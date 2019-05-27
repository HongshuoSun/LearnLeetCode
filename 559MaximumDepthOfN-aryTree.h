//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_559MAXIMUMDEPTHOFN_ARYTREE_H
#define LEETCODE_559MAXIMUMDEPTHOFN_ARYTREE_H
#include "Common.h"
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr){
            return 0;
        }
        int max = -1;
        for(const auto& i:root->children)
        {
            max = std::max(max,maxDepth(i));
        }
        return max+1;
    }
};
#endif //LEETCODE_559MAXIMUMDEPTHOFN_ARYTREE_H
