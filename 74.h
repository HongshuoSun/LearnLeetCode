//
// Created by sun51 on 2019/10/18.
//

#ifndef LEETCODE_74_H
#define LEETCODE_74_H
#include "Common.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;
        for(const auto& line:matrix)
        {
            if(line.size()>0 && line.front()<=target && line.back()>=target){
                return  find(line,target);
            }
        }
        return false;

    }
    bool find(const vector<int>& data,int target){
        auto i = data.begin();
        auto j = data.end()-1;

        while(i<=j)
        {
            auto mid = (j-i)/2+i;
            if((*mid)<target){
                i = mid+1;
            }else if((*mid)>target){
                j = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_74_H
