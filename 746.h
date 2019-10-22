//
// Created by sun51 on 2019/10/23.
//

#ifndef LEETCODE_746_H
#define LEETCODE_746_H
#include "Common.h"
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int r1=0;
        int r2=0;
        int length = cost.size();
        int tmp;
        for(int i=2;i<length+1;i++){
            tmp = min(r1+cost[i-2],r2+cost[i-1]);
            r1=r2;
            r2=tmp;
        }
        return r2;
    }
};
#endif //LEETCODE_746_H
