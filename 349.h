//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_349_H
#define LEETCODE_349_H
#include "Common.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet;
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        for(auto&i : nums1){
            if(numSet.count(i)<1){
                numSet.insert(i);
            }
        }
        unordered_set<int> ansSet;
        for(auto& i:nums2){
            if(numSet.count(i)>0 && ansSet.count(i)<1){
                ansSet.insert(i);
            }
        }
        vector<int> ans;
        for(const auto &i :ansSet){
            ans.push_back(i);
        }
        return ans;
    }
};
#endif //LEETCODE_349_H
