//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_14_H
#define LEETCODE_14_H
#include "Common.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        char currentChar= ' ';
        int currentIndex=0;

        int strCount = strs.size();
        if(strCount<1){
            return ans;
        }
        int minLength = strs[0].length();
        vector<int> strLengthMap(strCount,0);

        for(const auto& str :strs){
            strLengthMap[currentIndex] = str.length();
            minLength = min(  strLengthMap[currentIndex],minLength);
            currentIndex++;
        }
        for(int i=0;i<minLength;i++){
            auto currentChar = strs[0][i];
            bool same = true;
            for(int j=1;j<strCount;j++){
                if(strs[j][i]!=currentChar){
                    same = false;
                    break;
                }
            }
            if(same){
                ans+=currentChar;
            }else{
                break;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_14_H
