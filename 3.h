//
// Created by sun51 on 2019/11/3.
//

#ifndef LEETCODE_3_H
#define LEETCODE_3_H
#include "Common.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> charToIndex;
        int length = s.length();
        int ans = 1;
        if(length<=1){
            return length;
        }
        charToIndex[s[0]]=0;
        int begin = 0,end = 1;
        for(;end<length;end++){
            if(charToIndex.count(s[end])<1){
                charToIndex[s[end]] = end;
                ans = max(ans,end-begin+1);
            }
            else{
                int newBegin = charToIndex[s[end]]+1;
                for(int i=begin;i<newBegin;i++){
                    charToIndex.erase(s[i]);
                }
                begin = newBegin;
                charToIndex[s[end]] = end;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_3_H
