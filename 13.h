//
// Created by sun51 on 2019/10/17.
//

#ifndef LEETCODE_13_H
#define LEETCODE_13_H
#include "Common.h"
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.length();
        for(int i=0;i<length;i++){
            int current = romanToIntMap[s[i]];
            if(i<length-1 &&   romanToIntMap[s[i+1]]>current )
            {
                result-=current;
            }else{
                result+=current;
            }
        }
        return result;
    }
    unordered_map<char,int> romanToIntMap={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
};
#endif //LEETCODE_13_H
