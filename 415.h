//
// Created by sun51 on 2019/11/4.
//

#ifndef LEETCODE_415_H
#define LEETCODE_415_H
#include "Common.h"
class Solution {
public:
    string addStrings(string num1, string num2) {
        int maxLength = num1.length();
        int minLength = num2.length();
        if(maxLength<minLength){
            swap(num1,num2);
            swap(maxLength,minLength);
        }
        string ans = num1;
        bool jinWei = false;
        int current = 0;
        for(int i=0;i<minLength;i++){
            current = (jinWei?1:0)+ ans[maxLength-1-i]-'0'+num2[minLength-1-i]-'0';
            if(current>=10){
                current %=10;
                jinWei = true;
            }else{
                jinWei = false;
            }
            ans[maxLength-1-i] = current+'0';
        }
        for(int i=minLength;i<maxLength;i++){
            current = (jinWei?1:0)+ ans[maxLength-1-i]-'0';
            if(current>=10){
                current %=10;
                jinWei = true;
            }else{
                jinWei = false;
            }
            ans[maxLength-1-i] = current+'0';
        }
        if(jinWei){
            ans = "1"+ans;
        }
        return ans;
    }
};
#endif //LEETCODE_415_H
