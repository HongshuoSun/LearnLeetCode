//
// Created by 孙宏硕 on 2019-05-28.
//

#ifndef LEETCODE_289GAMEOFLIFE_H
#define LEETCODE_289GAMEOFLIFE_H
#include "Common.h"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        ver = board.size();
        if(ver<1){
            return;
        }
         hor = board[0].size();
        if(hor<1){
            return;
        }
        for(int i=0;i<ver;i++){
            for(int j=0;j<hor;j++){
                int originalVal = board[i][j];
                int count =GetEightNeighbors(board,i,j);
                if(count < 2 && originalVal ==life ){
                    board[i][j] = liftToDead;
                }
                else if((count==2||count==3)&&originalVal == life){
                    board[i][j] = life;
                }
                else if(count>3 && originalVal == life){
                    board[i][j] = liftToDead;
                }
                else if(count ==3 && originalVal == dead){
                    board[i][j] = deadToLife;
                }
            }
        }
        for(int i=0;i<ver;i++){
            for(int j=0;j<hor;j++){
                int originalVal = board[i][j];
                if(originalVal == deadToLife)
                {
                    board[i][j] = life;
                }
                else if(originalVal ==liftToDead )
                {
                    board[i][j] = dead;
                }
            }
        }

    }
    int GetEightNeighbors(const vector<vector<int>>& board,const int i,const int j){
        int result = 0;
        for(int curI=i-1;curI<i+2;curI++){
            for(int curJ = j-1;curJ<j+2;curJ++){
                if( curI>=0 &&curI<ver && curJ>=0&&curJ<hor      && (curI != i || curJ != j)) {
                    if(board[curI][curJ]==life ||board[curI][curJ]==liftToDead ){
                        result++;
                    }
                }
            }
        }
        return result;
    }

    int ver;
    int hor;
    const int life = 1;
    const int dead = 0;
    const int deadToLife = -2;
    const int liftToDead = -1;
};
#endif //LEETCODE_289GAMEOFLIFE_H
