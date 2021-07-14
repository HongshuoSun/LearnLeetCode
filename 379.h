//
// Created by bugma on 7/14/2021.
//

#ifndef LEETCODE_379_H
#define LEETCODE_379_H
#include "Common.h"
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    size_t maxSize;
    std::vector<bool> usedFlag;
    std::vector<int> canUsedArray;
    PhoneDirectory(int maxNumbers):maxSize(maxNumbers),usedFlag(maxNumbers,false),canUsedArray(maxNumbers,0) {
        for(size_t idx=0;idx<maxNumbers;idx++){
            canUsedArray[idx] = idx;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(canUsedArray.size()==0){
            return -1;
        }else{
            int ans = canUsedArray.back();
            usedFlag[ans] = true;
            canUsedArray.pop_back();
            return ans;
        }
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if(number<0||number>=maxSize){
            return false;
        }
        return !usedFlag[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if(number<0||number>=maxSize){

        }else{
            if(usedFlag[number]){
                usedFlag[number]= false;
                canUsedArray.push_back(number);
            }
        }
    }
};
#endif //LEETCODE_379_H
