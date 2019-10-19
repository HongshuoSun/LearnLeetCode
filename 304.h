//
// Created by sun51 on 2019/10/19.
//

#ifndef LEETCODE_304_H
#define LEETCODE_304_H
#include "Common.h"
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rowLength =0;
        colLength = 0;
        rowLength = matrix.size();
        if(rowLength>0){
            colLength = matrix[0].size();
            prefixSum.resize(rowLength,vector<int>(colLength,0));
        }
        int sum =0;
        for(int j=0;j<colLength;j++){
            sum+=matrix[0][j];
            prefixSum[0][j]=sum;
        }
        for(int i=1;i<rowLength;i++){
            sum=0;
            for(int j=0;j<colLength;j++){
                sum+=matrix[i][j];
                prefixSum[i][j]=sum+prefixSum[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int matrix1Sum = prefixSum[row2][col2];
        int matrix2Sum = row1>0?prefixSum[row1-1][col2]:0;
        int matrix3Sum = col1>0?prefixSum[row2][col1-1]:0;
        int matrix4Sum = (row1>0 && col1>0)?prefixSum[row1-1][col1-1]:0;
        return matrix1Sum-matrix2Sum-matrix3Sum+matrix4Sum;
    }
    vector<vector<int>> prefixSum;
    int rowLength;
    int colLength;
};
#endif //LEETCODE_304_H
