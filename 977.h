//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_977_H
#define LEETCODE_977_H
#include "Common.h"
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int length = A.size();
        if(length<1){
            return ans;
        }
        int minIndex = 0;
        int minNum =abs(A[0]);
        for(int i=1;i<length;i++){
            int current = abs(A[i]);
            if(current<minNum){
                minNum = current;
                minIndex = i;
            }
        }
        int left = minIndex;
        int right =minIndex+1;
        while(left>=0|| right<length){
            if(  right>=length ||  (left>=0&&  abs(A[left])<abs(A[right]))){
                ans.push_back(A[left]*A[left]);
                left--;
            }else{
                ans.push_back(A[right]*A[right]);
                right++;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_977_H
