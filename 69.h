//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_69_H
#define LEETCODE_69_H
#include "Common.h"
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
        {
            return x;
        }
        int end = x/2+1;
        int begin = 1;
        int mid = 0;
        while(begin<end){
            mid = (begin+end)/2+1;
            if(mid*mid <x){
                begin=mid;
            }else if(mid*mid >x){
                end = mid-1;
            }
        }
        return begin;
    }
};
#endif //LEETCODE_69_H
