//
// Created by sun51 on 2019/10/30.
//

#ifndef LEETCODE_118_H
#define LEETCODE_118_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows<1){
            return ans;
        }
        ans.resize(numRows);
        ans[0] = {1};
        for(int i=1;i<numRows;i++){
            ans[i].resize(i+1,1);

            for(int j=1;j<=i-1;j++){
                ans[i][j]= ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};
#endif //LEETCODE_118_H
