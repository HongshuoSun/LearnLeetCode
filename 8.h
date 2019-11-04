//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_8_H
#define LEETCODE_8_H
#include "Common.h"
class Solution {
public:
    int myAtoi(string str) {
        int minusCount = 0;
        int length = str.length();
        int begin = 0;
        long long ans = 0;
        while( begin<length && !(str[begin]>='0' && str[begin]<='9') ){
            if(str[begin]=='-' ||str[begin]=='+'){
                if(str[begin]=='-'){
                    minusCount++;
                }
                begin++;
                break;
            }else if(str[begin]==' '){
                begin++;
            }
            else{
                return ans;
            }
        }

        while(begin<length && (str[begin]>='0' && str[begin]<='9')){
            ans *=10;
            ans+= (str[begin]-'0');
            begin++;
            if(minusCount%2 == 1){
                if( ans*(-1)<=(long long)INT_MIN){
                    ans = abs((long long)INT_MIN);
                    break;
                }
            }else{
                if( ans>=INT_MAX){
                    ans = abs(INT_MAX);
                    break;
                }
            }
        }
        if(minusCount%2==1){
            ans = ans*-1;
        }
        return ans;
    }
};
#endif //LEETCODE_8_H
