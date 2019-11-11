//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_50_H
#define LEETCODE_50_H
#include "Common.h"
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0|| x==0){
            return 1;
        }
        if(n<0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1;
        for(int i=n;i>=0;i<<=1){
            if(i&1){
                ans = ans*x;
            }
            x*=x;
        }
        return ans;
    }
};
#endif //LEETCODE_50_H
