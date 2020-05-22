//
// Created by Administrator on 2020/5/21.
//

#ifndef LEETCODE_55_H
#define LEETCODE_55_H
#include "Common.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for(int i=0;i<N && i <=ans;i++){
            ans = max(ans,nums[i]+i);
        }
        return ans>=N-1;
    }
};
#endif //LEETCODE_55_H
