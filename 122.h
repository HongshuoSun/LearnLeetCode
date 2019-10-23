//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_122_H
#define LEETCODE_122_H
#include "Common.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length<1){
            return 0;
        }
        int prefixMin = prices[0];
        int result = 0;
        for(int i=1;i<length;i++){
            int sub = prices[i]-prefixMin;
            prefixMin = min(prices[i],prefixMin);
            result = max(result,sub);
        }
        return result;
    }
};
#endif //LEETCODE_122_H
