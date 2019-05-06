//
// Created by 孙宏硕 on 2019-05-06.
//

#ifndef LEETCODE_167TOWSUMII_H
#define LEETCODE_167TOWSUMII_H
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int length = numbers.size();
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {

                if (numbers[i]+numbers[j]==target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    i = length;
                    break;
                }
                if (numbers[i]+numbers[j]>target)
                {
                    break;
                }

            }
        }
        return result;
    }

};
#endif //LEETCODE_167TOWSUMII_H
