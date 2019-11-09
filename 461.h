//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_461_H
#define LEETCODE_461_H
#include "Common.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x^y;
        int ans = 0;
        while(x!=0){
            if(x&0x1){
                ans++;
            }
            x >>=1;
        }
        return ans;
    }
};
#endif //LEETCODE_461_H
