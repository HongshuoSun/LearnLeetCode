//
// Created by sun51 on 2019/10/17.
//

#ifndef LEETCODE_12_H
#define LEETCODE_12_H
#include "Common.h"
class Solution {
public:
    string intToRoman(int num) {
        int qian,bai,shi,ge;
        qian = num/1000;
        bai = num%1000/100;
        shi = num%100/10;
        ge = num%10;
        string result;
        while((qian--)>0)
        {
            result+='M';
        }
        if(bai==9){
            result+="CM";
        }
        else if(bai==4){
            result+="CD";
        }else{
            if(bai>=5){
                result+="D";
                bai-=5;
            }
            while((bai--)>0){
                result+="C";
            }
        }

        if(shi==9){
            result+="XC";
        }
        else if(shi==4){
            result+="XL";
        }else{
            if(shi>=5){
                result+="L";
                bai-=5;
            }
            while((shi--)>0){
                result+="X";
            }
        }

        if(ge==9){
            result+="IX";
        }
        else if(ge==4){
            result+="IV";
        }else{
            if(ge>=5){
                result+="V";
                bai-=5;
            }
            while((ge--)>0){
                result+="I";
            }
        }
        return result;
    }
};

#endif //LEETCODE_12_H
