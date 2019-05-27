//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_9PALINDROMENUMBER_H
#define LEETCODE_9PALINDROMENUMBER_H
#include "Common.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string num = to_string(x);
        int i=0,j = num.length()-1;
        while(i<j){
            if(num[i++]!=num[j--]){
                return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_9PALINDROMENUMBER_H
