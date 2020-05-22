//
// Created by Administrator on 2020/5/21.
//

#ifndef LEETCODE_45_H
#define LEETCODE_45_H
#include "Common.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        for(int i=0;i<N;i++){
            nums[i]+=i;
        }
        int ans = 0;
        int maxNum = 0;
        int minNum = 0;
        int last = 0;
        while(true){
            if(maxNum>=N-1){
                break;
            }
            int tmp = *max_element(nums.begin()+last,nums.begin()+maxNum+1);
            if(tmp == maxNum){
                if(maxNum<N-1){
                    ans = 0;
                }
                break;
            }
            last = maxNum;
            maxNum = tmp;
            ans++;
        }
        return ans;
    }

private:

};
#endif //LEETCODE_45_H
