//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_561ARRAYPARTITIONI_H
#define LEETCODE_561ARRAYPARTITIONI_H

#include "Common.h"
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = 0;
        auto end = nums.end();
        for(auto it = nums.begin();it<end;it= it+2)
        {
            result+= *it;
        }
        return result;
    }
};
#endif //LEETCODE_561ARRAYPARTITIONI_H
