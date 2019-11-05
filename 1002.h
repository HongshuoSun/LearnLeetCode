//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_1002_H
#define LEETCODE_1002_H
#include "Common.h"
class Solution {
public:
    struct CharMap{
        int charMap[26]= {0};
    };
    vector<string> commonChars(vector<string>& A) {
        vector<CharMap> stringMap(A.size());
        int strCount = A.size();
        for(int i=0;i<strCount;i++){
            for(const auto& c:A[i]){
                stringMap[i].charMap[c-'a']++;
            }
        }
        vector<string> ans;
        for(char i=0;i<26;i++){
            int charCount = INT_MAX;
            for(const auto& charMap:stringMap){
                charCount = min(charCount,charMap.charMap[i]);
                if(charCount<1){
                    break;
                }
            }
            while(charCount>0){
                ans.push_back( string(1,i+'a'));
                charCount--;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_1002_H
