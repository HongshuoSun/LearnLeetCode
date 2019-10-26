//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_122_H
#define LEETCODE_122_H
#include "Common.h"

/*  overtime
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        if(count<=1){
            return 0;
        }
        vector<int> dp(count,0);
        for(int i=1;i<count;i++){
            dp[i] = dp[i-1];
            for(int j=0;j<i;j++){
                dp[i] = max(dp[i],dp[j]+ maxProfit2(prices.begin()+j,prices.begin()+i+1));
            }
        }
        return dp[count-1];
    }
    int maxProfit2(const vector<int>::iterator begin,const vector<int>::iterator end)
    {
        if(end<=begin){
            return 0;
        }
        int minimum = *begin;
        int ans = 0;
        for(auto it = begin;it<end;it++){
            ans = max(ans,*it-minimum);
            minimum = min(minimum,*it);
        }
        return ans;
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans= 0;
        int minimum;
        int maximum;
        int i=0;
        int count = prices.size();
        while(i<count){
            while(i<count-1&& prices[i]>prices[i+1])
                i++;
            minimum = prices[i];
            while(i<count-1&&prices[i]<prices[i+1]){
                i++;
            }
            maximum = prices[i];
            ans += max(0,maximum-minimum);
        }
        return ans;
    }
};

#endif //LEETCODE_122_H
