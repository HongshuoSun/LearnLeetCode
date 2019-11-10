//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_360_H
#define LEETCODE_360_H
#include "Common.h"
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        double extremumX = INT_MIN;
        if(a!=0){
            extremumX = -1.0*b/(2*a);
        }
        int length = nums.size();
        int minIndex = 0;
        for(int i=0;i<length;i++){
            if(abs(nums[minIndex]-extremumX)>abs(nums[i]-extremumX)){
                minIndex = i;
            }
        }
        int left = minIndex;
        int right = minIndex+1;
        vector<int> ans;
        while(left>=0&& right<=length-1){
            if(abs(nums[left]-extremumX)<abs(nums[right]-extremumX)){
                ans.push_back( a*nums[left]*nums[left]+b*nums[left]+c );
                left--;
            }else{
                ans.push_back( a*nums[right]*nums[right]+b*nums[right]+c );
                right++;
            }
        }
        while(left>=0){
            ans.push_back( a*nums[left]*nums[left]+b*nums[left]+c );
            left--;
        }
        while(right<=length-1){
            ans.push_back( a*nums[right]*nums[right]+b*nums[right]+c );
            right++;
        }
        if(a<0|| (a==0 && b<0)){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};
#endif //LEETCODE_360_H
