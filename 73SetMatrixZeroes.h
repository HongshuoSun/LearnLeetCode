//
// Created by 孙宏硕 on 2019-05-28.
//

#ifndef LEETCODE_73SETMATRIXZEROES_H
#define LEETCODE_73SETMATRIXZEROES_H
#include "Common.h"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ver = matrix.size();
        if(ver<1){
            return;
        }
        int hor = matrix[0].size();
        if(hor<1){
            return;
        }
        for(int i=0;i<ver;i++){
            for(int j=0;j<hor;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=0;i<ver;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<hor;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0;j<hor;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<ver;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0;i<ver;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<hor;j++){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
#endif //LEETCODE_73SETMATRIXZEROES_H
