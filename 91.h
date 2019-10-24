//
// Created by sun51 on 2019/10/24.
//

#ifndef LEETCODE_91_H
#define LEETCODE_91_H
#include "Common.h"
class Solution {
public:
    int numDecodings(string s) {
        int r1=0,r2=0;
        int length = s.length();
        if(length<1){
            return 0;
        }
        if(length==1||s[0]=='0'){
            return s[0]=='0'?0:1;
        }
        int lastNum=s[0]-'0',currentNum=0;
        int temp = 0;
        r2 = lastNum!=0?1:0;
        r1 =1;
        for(int i=1;i<length;i++){
            temp=0;
            currentNum = s[i]-'0';
            if((currentNum+lastNum*10)>=10 && (currentNum+lastNum*10)<=26){
                temp+=r1;
            }
            if(currentNum>0){
                temp+=r2;
            }
            r1=r2;
            r2=temp;
            lastNum = currentNum;
        }
        return r2;
    }
};
#endif //LEETCODE_91_H
