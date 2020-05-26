//
// Created by Administrator on 2020/5/23.
//

#ifndef LEETCODE_394_H
#define LEETCODE_394_H
#include "Common.h"
class Solution {
public:
    string decodeString(string s) {
        ans = Process(0,s.length(),s);
        return ans;
    }
    string Process(int begin,int end,string& s){
        if(s[begin]>)
    }
    bool isNum(const char& c){
        return c>='0'&&c<='9';
    }
    bool isChar(const char& c){
        return (c>='a'&& c<='z')&&(c>='A'&&c<='Z');
    }
    string ans;
};
#endif //LEETCODE_394_H
