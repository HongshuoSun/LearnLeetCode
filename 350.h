//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_350_H
#define LEETCODE_350_H
#include "Common.h"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        map<int,int> nums1Map;
        for(const auto& i:nums1){
            nums1Map[i]++;
        }
        vector<int> ans;
        for(const auto& i:nums2){
            if(nums1Map.count(i)>0){
                ans.push_back(i);
                nums1Map[i]--;
                if(nums1Map[i]<1){
                    nums1Map.erase(i);
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_350_H
