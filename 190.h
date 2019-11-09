//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_190_H
#define LEETCODE_190_H
#include "Common.h"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            ans<<=1;
            if(n&0x1){
                ans|=0x1;
            }

            n>>=1;
        }
        return n;
    }
};
#endif //LEETCODE_190_H
