//
// Created by sun51 on 2019/11/4.
//

#ifndef LEETCODE_67_H
#define LEETCODE_67_H
#include "Common.h"
class Solution {
public:
    string addBinary(string a, string b) {
        int maxLength = a.length();
        int minLength = b.length();
        if(maxLength<minLength){
            swap(a,b);
            swap(maxLength,minLength);
        }
        string ans = a;
        bool jinWei = false;

        for(int i=0;i<minLength;i++){
            int current = jinWei?1:0;
            current+= ans[maxLength-1-i]-'0'+ b[minLength-1-i]-'0';
            if(current>1){
                current = (current % 2);
                jinWei = true;
            }else{
                jinWei = false;
            }
            ans[maxLength-1-i] =  (current+'0');
        }
        for(int i=minLength;i<maxLength;i++){
            int current = jinWei?1:0;
            current+= (ans[maxLength-1-i]-'0');
            if(current>1){
                current = (current % 2);
                jinWei = true;
            }else{
                jinWei = false;
            }
            ans[maxLength-1-i] =  (current+'0');
        }
        if(jinWei){
            ans.insert(ans.begin(),'1');
        }
        return ans;
    }
};
#endif //LEETCODE_67_H
