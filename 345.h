//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_345_H
#define LEETCODE_345_H
#include "Common.h"
class Solution {
public:
    string reverseVowels(string s) {
        int begin = 0;
        int end = s.length()-1;
        int length = s.length();
        while(begin<end){
            while(  begin<end && !isYuanYin(s[begin]))
                begin++;
            while(  begin<end && !isYuanYin(s[end]))
                end--;
            if(begin<end){
                swap(s[begin],s[end]);
                begin++;
                end--;
            }
        }
        return s;
    }
    inline bool isYuanYin(char c){
        if(c>='A'&& c<='Z'){
            c = 'a'+ (c-'A');
        }
        return c=='a' || c =='e'||c=='i'||c=='o'||c=='u';
    }
};
#endif //LEETCODE_345_H
