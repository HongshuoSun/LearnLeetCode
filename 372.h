//
// Created by sun51 on 2019/11/11.
//

#ifndef LEETCODE_372_H
#define LEETCODE_372_H
#include "Common.h"
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for(int i=b.size()-1;i>=0;i--){
            res = (res*power(a,b[i]))%1337;
            a = power(a%1337,10)%1337;
        }
        return res;
    }
    int power(int  a, int b){
        if(b==0){
            return 1;
        }
        int ans =1;
        for(int i=b;i>0;i/=2){
            if(i&1){
                ans = (ans*a)%1337;
            }
            a= (a%1337)*(a%1337)%1337;
        }
        return ans;
    }
};
#endif //LEETCODE_372_H
