//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_717_H
#define LEETCODE_717_H
#include "Common.h"
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int length = bits.size();
        if(length<=1){
            return true;
        }
        if(bits[length-1]!=0 || bits[length-2]==1){
            return false;
        }
        return true;
    }
};
#endif //LEETCODE_717_H
