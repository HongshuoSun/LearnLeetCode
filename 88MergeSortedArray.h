//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_88MERGESORTEDARRAY_H
#define LEETCODE_88MERGESORTEDARRAY_H
#include "Common.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int totalCount = m+n;
        nums1.resize(m+n);
        int i=m-1,j = n-1;
        int current = m+n-1;
        while(i>=0 &&j>=0)
        {
            nums1[i]>nums2[j]?( nums1[current--] = nums1[i--]):(nums1[current--] = nums2[j--]);
        }
        while (i>=0){
            nums1[current--] = nums1[i--];
        }
        while (j>=0){
            nums1[current--] = nums2[j--];
        }
    }
};
#endif //LEETCODE_88MERGESORTEDARRAY_H
