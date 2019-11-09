//
// Created by sun51 on 2019/11/6.
//

#ifndef LEETCODE_401_H
#define LEETCODE_401_H

#include "Common.h"
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        Generate(0,0,num);
        vector<string> ans;
        for(const auto & binary : allBinarys){
            ans.push_back(binaryToString(binary));
        }
        return ans;
    }
    void Generate(uint32_t currentNum,int currentIndex,int count){

        if(count==0){
            allBinarys.push_back(currentNum);
        }else{
            if(currentIndex>=11){
                return;
            }
            Generate(currentNum| 0x1<<currentIndex,currentIndex+1,count-1);
            Generate(currentNum,currentIndex+1,count);
        }
    }
    vector<uint32_t> allBinarys;
    string binaryToString(uint32_t num){
        int hour = num>>6;
        int minute = num& (0x3f);
        return to_string(hour)+":"+  (minute<10?("0"+to_string(minute)):to_string(minute));
    }
};
#endif //LEETCODE_401_H
