//
// Created by sun51 on 2019/10/30.
//

#ifndef LEETCODE_18_H
#define LEETCODE_18_H
#include "Common.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
        std::sort(nums.begin(),nums.end());
        auto begin = nums.begin();
        auto end = nums.end();
        for(auto i = begin;i<end-3;i++){
            for(auto j = i+1;j<end-2;j++){
                auto k = j+1,l = end-1;
                while(k<l){
                    int current = *i+*j+*k+*l;
                    if(current<target){
                        k++;
                        while(k<l && *k == *(k-1)) k++;
                    }else if(current >target){
                        l--;
                        while(k<l && *l == *(l+1)) l--;
                    }else{
                        ans.push_back({*i,*j,*k,*l});
                        k++,l--;
                        while(k<l && *k==*(k-1)) k++;
                        while(k<l && *l ==*(l+1)) l--;
                    }
                }
                while( j<end-2 &&*j == *(j+1)) j++;
            }
            while( i<end-1 &&*i == *(i+1)) i++;
        }
        return ans;
    }
};
#endif //LEETCODE_18_H
