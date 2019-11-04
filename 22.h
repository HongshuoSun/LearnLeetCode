//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_22_H
#define LEETCODE_22_H

#include "Common.h"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        if(n<=0){
            return ans;
        }
        Generate("",0,0);
        return ans;
    }
    void Generate(string str,int leftCount,int rightCount){
        if(leftCount==rightCount && leftCount==n){
            ans.push_back(str);
            return;
        }
        if(leftCount<n){
            Generate(str+'(',leftCount+1,rightCount);

        }
        if(rightCount<leftCount){
            Generate(str+')',leftCount,rightCount+1);
        }

    }
    int n;
    vector<string> ans;
};
#endif //LEETCODE_22_H
