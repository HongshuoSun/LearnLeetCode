//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_125_H
#define LEETCODE_125_H
#include "Common.h"
class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.length();
        bool isPalindrome = true;
        int begin = 0;
        int end = length-1;
        while(begin<end){
            while(begin<end&&!isChar(s[begin])){
                begin++;
            }
            while(begin<end &&!isChar(s[end])){
                end--;
            }
            if(begin<end){
                if(!isSame(s[begin],s[end])){
                    isPalindrome = false;
                    break;
                }else{
                    begin++;
                    end--;
                }
            }
        }
        return isPalindrome;
    }
    inline bool isChar(char c){
        return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');
    }
    inline bool isSame(char a,char b){
        if(a>='A'&&a<='Z'){
            a = 'a'+(a-'A');
        }
        if(b>='A'&&b<='Z'){
            b = 'a'+(b-'A');
        }
        return a == b;
    }
};
#endif //LEETCODE_125_H
