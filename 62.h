//
// Created by Administrator on 2019/10/23.
//

#ifndef LEETCODE_62_H
#define LEETCODE_62_H
#include "Common.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        int num1 = min(m,n);
        int num2 = max(m,n);
        if(num1<=1 || num2<=1){
            return 1;
        }
        vector<int> ans(num1,1);
        for(int i=1;i<num2;i++){
            for(int j=1;j<num1;j++){
                ans[j] = ans[j]+ans[j-1];
            }
        }
        return ans[num1-1];
    }
};
#endif //LEETCODE_62_H
