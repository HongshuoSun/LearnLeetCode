//
// Created by sun51 on 2019/11/4.
//

#ifndef LEETCODE_43_H
#define LEETCODE_43_H
#include "Common.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        int maxLength = num1.length();
        int minLength = num2.length();
        if(maxLength<minLength){
            swap(num1,num2);
            swap(maxLength,minLength);
        }
        string ans = string(maxLength,'0');
        int jinWei = 0;
        for(int i=0;i<minLength;i++){
            int currentNum = num2[minLength-1-i]-'0';
            for(int j=0;j<=maxLength;j++){
                int current =  (j<maxLength?((num1[maxLength-1-j]-'0')*currentNum):0)+ jinWei;
                if(current>=10){
                    jinWei = current/10;
                    current = current%10;
                }else{
                    jinWei = 0;
                }

                while(ans.length()<(j+i+1)){
                    ans = ans+'0';
                }
                int currentIndex = j+i;
                current = (ans[currentIndex]-'0')+current;
                while(current>=10){
                    ans[currentIndex] = (current%10)+'0';
                    currentIndex++;
                    if(ans.length()<currentIndex+1){
                        ans = ans+'0';
                    }
                    current = current/10 + ans[currentIndex]-'0';
                }
                ans[currentIndex] = current+'0';
            }
        }
        while(ans.length()>1&&ans[ans.length()-1]=='0'){
            ans.pop_back();
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
#endif //LEETCODE_43_H
