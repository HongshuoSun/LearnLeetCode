//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_38_H
#define LEETCODE_38_H
#include "Common.h"
class Solution {
public:
    vector<int> getnext(const string& str)
    {
        int len=str.size();
        vector<int> next;
        next.push_back(-1);//next数组初值为-1
        int j=0,k=-1;
        while(j<len-1)
        {
            if(k==-1||str[j]==str[k])//str[j]后缀 str[k]前缀
            {
                j++;
                k++;
                next.push_back(k);
            }
            else
            {
                k=next[k];
            }
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        int size1 = haystack.length();
        int size2 = needle.length();
        if(size2==0){
            return 0;
        }
        vector<int> next = getnext(needle);
        int i=0,j=0;
        while(i<size1&&j<size2){
            if(j==-1||haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }
        }
        return j==size2? i-j:-1;
    }
};
#endif //LEETCODE_38_H
