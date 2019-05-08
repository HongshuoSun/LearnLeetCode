//
// Created by 孙宏硕 on 2019-05-07.
//

#ifndef LEETCODE_739DAILYTEMPERATURES_H
#define LEETCODE_739DAILYTEMPERATURES_H
#include "Common.h"
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        constexpr  int MAX_T = 101;
        constexpr int MAX_INDEX = 30001;
        const size_t length = T.size();
        vector<int> result(length,0);
        vector<int> next(MAX_T+1,-1);
        for(int index=length-1;index>=0;index--)
        {
            int currentT = T[index];
            int minIndex = MAX_INDEX;
            for(int t =currentT+1;t<=MAX_T;t++)
            {
                if(next[t]>=0 && next[t]<minIndex)
                {
                    minIndex = next[t];
                }
            }
            if(minIndex<MAX_INDEX){
                result[index] = minIndex-index;
            } else{
                result[index] = 0;
            }
            next[currentT] = index;
        }
        return result;
    }
};
#endif //LEETCODE_739DAILYTEMPERATURES_H
