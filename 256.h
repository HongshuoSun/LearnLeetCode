//
// Created by Administrator on 2019/10/22.
//

#ifndef LEETCODE_256_H
#define LEETCODE_256_H
#include "Common.h"
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans[3] = {0};
        int temp0,temp1,temp2;
        for(int i=0;i<n;i++){
            temp0 = ans[0];
            temp1 = ans[1];
            temp2 = ans[2];
            ans[0] = min(temp1,temp2)+costs[i][0];
            ans[1] = min(temp0,temp2)+costs[i][1];
            ans[2] = min(temp0,temp1)+costs[i][2];
        }
        return min(ans[0],min(ans[1],ans[2]));
    }
};
#endif //LEETCODE_256_H
