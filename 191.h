//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_191_H
#define LEETCODE_191_H
#include "Common.h"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n!=0){
            ans++;
            n &=n-1;
        }
        return ans;
    }
};
#endif //LEETCODE_191_H
