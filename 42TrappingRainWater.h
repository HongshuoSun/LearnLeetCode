//
// Created by sun51 on 2019/5/7.
//

#ifndef LEETCODE_42TRAPPINGRAINWATER_H
#define LEETCODE_42TRAPPINGRAINWATER_H
#include "Common.h"
class Solution {
public:
    int trap(vector<int>& height) {
        size_t i =0;
        size_t j = +1;
        int sum = 0;
        size_t length = height.size();
        if(length < 3)
        {
            return sum;
        }
        while(i<length-2) {
            int temp = i;
            //把平的去掉 保证降序开头
            while (i <length-2 &&height[i] <= height[i + 1]) {
                i++;
            }
            j = i + 1;
            //把中间降序的去掉
            while(j<length-1&&height[j]>=height[j+1])
            {
                j++;
            }
            bool hasIncre = false;
            //取最长的递增
            while (j<length-1&& height[j] <= height[j + 1]) {
                if (height[j] < height[j + 1]) {
                    hasIncre = true;
                }
                j++;
            }
            if (hasIncre) {
                int h = std::min(height[i], height[j]);
                for (int k = i + 1; k < j; k++) {
                    if (height[k] > h) {
                        break;
                    }
                    sum += (h - height[k]);
                }
                i = j;
            }
            else
            {
                i = temp+1;
            }

        }
        return sum;
    }
};
#endif //LEETCODE_42TRAPPINGRAINWATER_H
