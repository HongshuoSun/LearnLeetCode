//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_560_H
#define LEETCODE_560_H
#include "Common.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        int ans = 0;
        vector<int> prefix(N,0);
        prefix[0] = nums[0];
        if(prefix[0]==k){
            ans++;
        }
        for(int i=1;i<N;i++){
            prefix[i] = prefix[i-1]+nums[i];
            int p = prefix[i];
            if(p==k){
                ans++;
            }
            for(int j=0;j<i;j++){
                p-=nums[j];
                if(p==k){
                    ans++;
                }
            }

        }
        return ans;
    }
};
#endif //LEETCODE_560_H
