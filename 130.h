//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_130_H
#define LEETCODE_130_H
#include "Common.h"
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m<=1){
            return;
        }
        n  = board[0].size();
        if(n<=1){
            return;
        }
        for(int j=0;j<n;j++){
            Fill(0,j,'O','1',board);
        }
        for(int j=0;j<n;j++){
            Fill(m-1,j,'O','1',board);
        }
        for(int i=0;i<m;i++){
            Fill(i,0,'O','1',board);
        }
        for(int i=0;i<m;i++){
            Fill(i,n-1,'O','1',board);
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                Fill(i,j,'O','X',board);
            }
        }
        for(int j=0;j<n;j++){
            Fill(0,j,'1','O',board);
        }
        for(int j=0;j<n;j++){
            Fill(m-1,j,'1','O',board);
        }
        for(int i=0;i<m;i++){
            Fill(i,0,'1','O',board);
        }
        for(int i=0;i<m;i++){
            Fill(i,n-1,'1','O',board);
        }
    }
    int m;
    int n;
    void Fill(int x,int y,char oldChar,char newChar,vector<vector<char>>& board){
        if(x<0||x>=m||y<0||y>=n){
            return;
        }
        if(board[x][y]!=oldChar){
            return ;
        }
        board[x][y] = newChar;

        Fill(x-1,y,oldChar,newChar,board);
        Fill(x+1,y,oldChar,newChar,board);
        Fill(x,y-1,oldChar,newChar,board);
        Fill(x,y+1,oldChar,newChar,board);
    }
};
#endif //LEETCODE_130_H
