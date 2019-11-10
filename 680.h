//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_680_H
#define LEETCODE_680_H
#include "Common.h"
class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome(s,0,s.length()-1,false);
    }
    bool isPalindrome(const string& s,int begin,int end,bool hasDeleted){
        if(begin<end){
            if(s[begin]!=s[end]){
                if(hasDeleted){
                    return false;
                }else{
                    return isPalindrome(s,begin+1,end,true)||isPalindrome(s,begin,end-1,true);
                }
            }else{
                return isPalindrome(s,begin+1,end-1,hasDeleted);
            }
        }else{
            return true;
        }
    }
};
#endif //LEETCODE_680_H
