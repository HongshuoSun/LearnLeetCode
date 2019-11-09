//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_136_H
#define LEETCODE_136_H
#include "Common.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto& i:nums){
            ans ^=i;
        }
        return ans;
    }
};
#endif //LEETCODE_136_H
