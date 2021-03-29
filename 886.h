#include "Common.h"
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        n=N;
        count = 0;
        graph = vector<vector<bool>>(N+1,vector<bool>(N+1,true));
        color = vector<int>(N+1,0);
        for(const auto& e :dislikes){
            graph[e[0]][e[1]]=false;
            graph[e[1]][e[0]]=false;
        }
        bool ans = true;
        for(int i=1;i<=N;i++){
            if(!color[i]){
                ans &=DFS(i,1);
            }
        }
        return ans;
    }
    bool DFS(int i,int c){
        if(color[i]==0){
            color[i] = c;
            bool ans = true;
            for(int j=1;j<=n;j++){
                if(!graph[i][j]){
                    ans = ans && DFS(j, c==1?2:1);
                }
            }
            return ans;
        }else{
            if(color[i]!=c){
                return false;
            }else{
                return true;
            }
        }
    }
    vector<vector<bool>> graph;
    vector<int> color;
    int n;
    int count;
};