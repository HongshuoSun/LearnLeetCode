//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_16_19_H
#define LEETCODE_16_19_H
#include "Common.h"
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ans;
        m = land.size();
        if(m<1){
            return ans;
        }
        n=land[0].size();
        if(n<1){
            return ans;
        }
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(!land[x][y]){
                    ans.push_back(DFS(x,y,land));
                }
            }
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
    int DFS(int x,int y,vector<vector<int>>& land){
        if(x<0||x>=m||y<0||y>=n){
            return 0;
        }
        if(land[x][y]){
            return 0;
        }
        int ans = 1;
        land[x][y]=1;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans+=DFS(x+i,y+j,land);
            }
        }
        return ans;
    }
    int m;
    int n;
};
#endif //LEETCODE_16_19_H
