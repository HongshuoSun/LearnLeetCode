//
// Created by bugma on 2022/1/25.
//

#ifndef LEETCODE_2055_H
#define LEETCODE_2055_H
#include "Common.h"
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int bucketSize = s.length();
        vector<int> prefixSum(bucketSize,0);
        vector<int> leftNearest(bucketSize,0);
        vector<int> rightNearest(bucketSize,0);
        int num = 0;
        int lastLZ = -1;
        for(int i=0;i<bucketSize;i++){
            prefixSum[i] = num;

            if(s[i]=='*'){
                num++;
            }else{
                lastLZ = i;
            }
            leftNearest[i] = lastLZ;
        }
        lastLZ = bucketSize;
        for(int i=bucketSize-1;i>=0;i--){

            if(s[i]=='*'){

            }else{
                lastLZ = i;
            }
            rightNearest[i] = lastLZ;
        }
        int querySize = queries.size();
        vector<int> ans(querySize,0);
        for(int idx = 0;idx<querySize;idx++){
            int begin = queries[idx][0];
            int end =   queries[idx][1];
            int left = rightNearest[begin];
            int right = leftNearest[end];
            if(right<=left){
                ans[idx]=0;
            }else{
                ans[idx] = std::max(0,prefixSum[right]-prefixSum[left]);
            }
        }
        return ans;
    }
};
#endif //LEETCODE_2055_H
