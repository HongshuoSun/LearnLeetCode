//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_130_H
#define LEETCODE_130_H
#include "Common.h"
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        height = board.size();
        width  = board[0].size();
        int ans = 0;
        for(int i=1;i<height;i++){
            for(int j=1;j<width;j++){
                if(map[i][j]!='X'){
                    if(Fill(i,j)){

                    }
                }
            }
        }

    }
    vector<vector<char>>& map;
    int height;
    int width;
    bool Fill(int x,int y){
        if(map[x][y]=='X'){
            return true;
        }
        if(x==0||y==0){
            map[x][y] = 'X';
            return false;
        }
        else{
            map[x][y] = 'X';
            bool ans = true;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    ans&=Fill(x+i,y+j);
                }
            }
            return ans;
        }

    }
};
#endif //LEETCODE_130_H
