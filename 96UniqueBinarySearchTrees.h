//
// Created by 孙宏硕 on 2019-05-15.
//

#ifndef LEETCODE_96UNIQUEBINARYSEARCHTREES_H
#define LEETCODE_96UNIQUEBINARYSEARCHTREES_H
#include "Common.h"
class Solution {
public:
    int numTrees(int n) {
        vector<int> resultNum(n+1,0);
        resultNum[0] = 1;
        resultNum[1] = 1;

        for(int i=1;i<=n;i++)
        {

            for(int j = 1;j<=i;j++)
            {
                resultNum[i] += resultNum[j-1]*resultNum[i-j];
            }
        }
        return resultNum[n];
    }
};
#endif //LEETCODE_96UNIQUEBINARYSEARCHTREES_H
