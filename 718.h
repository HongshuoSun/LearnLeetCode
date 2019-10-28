//
// Created by sun51 on 2019/10/28.
//

#ifndef LEETCODE_718_H
#define LEETCODE_718_H
#include "Common.h"
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ASize = A.size();
        int BSize = B.size();
        if(ASize<1||BSize<1){
            return 0;
        }
        if(ASize>BSize){
            swap(A,B);
            swap(ASize,BSize);
        }
        vector<int> dp(ASize,0);
        vector<int> lastDp(ASize,0);
        int ans = 0;
        for(int i=0;i<ASize;i++){
            lastDp[i] = A[i]==B[0]?1:0;
            ans = max(ans,lastDp[i]);
        }
        for(int i=1;i<BSize;i++){
            for(int j=0;j<ASize;j++){
                if(A[j]==B[i]){
                    if(j>0)
                        dp[j] = lastDp[j-1]+1;
                    else
                        dp[j] = 1;
                }else{
                    dp[j]=0;
                }
                ans = max(ans,dp[j]);
            }
            swap(dp,lastDp);
        }
        return ans;
    }
};
#endif //LEETCODE_718_H
