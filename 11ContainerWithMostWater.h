//
// Created by 孙宏硕 on 2019-05-06.
//

#ifndef LEETCODE_11CONTAINERWITHMOSTWATER_H
#define LEETCODE_11CONTAINERWITHMOSTWATER_H
#include "Common.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int length = height.size();
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {
                auto current = (j-i)*min(height[i],height[j]);
                if(max<current)
                {
                    max = current;
                }
            }
        }
        return max;
    }
};
#endif //LEETCODE_11CONTAINERWITHMOSTWATER_H
