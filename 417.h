#include "Common.h"
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        ans = vector<vector<int>>();
        height = matrix.size();
        width  = matrix[0].size();
        redFlag = vector<vector<bool>>(height,vector<bool>(width,false));
        blackFlag = vector<vector<bool>>(height,vector<bool>(width,false));
        visited = vector<vector<bool>>(height,vector<bool>(width,false));
        for(int i=0;i<width;i++){
            redFlag[0][i]=true;
            DFS(matrix,i,0,true);
        }
        for(int j=0;j<height;j++){
            redFlag[j][0]=true;
            DFS(matrix,0,j,true);
        }
        visited = vector<vector<bool>>(height,vector<bool>(width,false));
        for(int i=0;i<width;i++){
            blackFlag[height-1][i]=true;
            DFS(matrix,i,height-1,false);
        }
        for(int j=0;j<height;j++){
            blackFlag[j][width-1]=true;
            DFS(matrix,width-1,j,false);
        }
        for(int w=0;w<width;w++){
            for(int h=0;h<height;h++){
                if(redFlag[h][w]&&blackFlag[h][w]){
                    ans.push_back({h,w});
                }
            }
        }
        return ans;
    }
    void DFS(const vector<vector<int>>& matrix, int w,int h,int flag){
        if(w<0||w>=width||h<0||h>=height){
            return;
        }
        if(visited[h][w]){
            return;
        }
        visited[h][w]=true;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if( (::abs(i)+::abs(j)) != 1){
                    continue;
                }
                if(w+i <0 || w+i >=width){
                    continue;
                }
                if(h+j<0||h+j>=height){
                    continue;
                }
                if(matrix[h+j][w+i]>=matrix[h][w]){
                    if(flag){
                        redFlag[h+j][w+i]=true;
                    }else{
                        blackFlag[h+j][w+i]=true;
                    }
                    DFS(matrix,w+i,h+j,flag);
                }
            }
        }
    }
    int width;
    int height;
    vector<vector<int>> ans;
    vector<vector<bool>> visited;
    vector<vector<bool>> redFlag;
    vector<vector<bool>> blackFlag;
};