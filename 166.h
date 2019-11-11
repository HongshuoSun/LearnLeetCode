//
// Created by sun51 on 2019/11/11.
//

#ifndef LEETCODE_166_H
#define LEETCODE_166_H
#include "Common.h"
class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if(numerator==0 || denominator==0){
            return "0";
        }
        string ans = "";
        if((numerator<0)^(denominator<0)){
            ans+='-';
        }
        numerator=abs(numerator); denominator = abs(denominator);
        long long zheng = numerator/denominator;
        ans+= to_string(zheng);
        numerator %=denominator;
        if(numerator==0){
            return ans;
        }
        ans+='.';

        map<int,int> modToIndex;
        while(numerator!=0){
            if(numerator!=0){
                if(modToIndex.count(numerator)>0){
                    ans +=')';
                    ans.insert(modToIndex[numerator],1,'(');
                    break;
                }else{
                    modToIndex.insert(make_pair(numerator,ans.length()));
                }
            }
            numerator*=10;
            int current = numerator/denominator;
            ans+=to_string(current);
            numerator %=denominator;
        }
        return ans;
    }
};
#endif //LEETCODE_166_H
