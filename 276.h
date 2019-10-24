//
// Created by sun51 on 2019/10/23.
//

#ifndef LEETCODE_276_H
#define LEETCODE_276_H
#include "Common.h"
class Solution {
public:
    int numWays(int n, int k) {
        if(n<=1){
            return n==1?k:0;
        }

        int r1 = k;
        int r2 = k*k;
        int temp;
        for(int i=2;i<n;i++){
            temp = r1*(k-1)+r2*(k-1);
            r1=r2;
            r2 = temp;
        }
        return r2;
    }
};
#endif //LEETCODE_276_H
