//
// Created by Administrator on 2019/10/26.
//

#ifndef LEETCODE_322_H
#define LEETCODE_322_H
#include "Common.h"
/*
 * for i->1:amount
 *  for j->0:coins.size()
 *  dp[i] = min(dp[i],dp[i-coins[j]]+1);
 * */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinSize = coins.size();
        sort(coins.begin(),coins.end());
        int MAX = 99999999;
        vector<int> dp(amount+1,MAX);
        int begin = 0;
        while(begin<coinSize && coins[begin]<1){
            begin++;
        }
        int end = begin;
        while(end<coinSize && coins[end]<=amount){
            end++;
        }
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=begin;j<end;j++){
                dp[i] = min(dp[i], ((i-coins[j]) >=0)?(dp[i-coins[j]]+1):MAX);
            }
        }
        return dp[amount]<MAX?dp[amount]:-1;
    }
};
#endif //LEETCODE_322_H
