#include "Common.h"
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        for(const auto& p:prerequisites){
            graph[p[0]][p[1]]=true;
        }
        vector<bool> ans;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]&&graph[k][j]){
                        graph[i][j]=true;
                    }
                }
            }
        }
        for(const auto& q:queries){
            ans.push_back( graph[q[0]][q[1]]);
        }
        return ans;
    }
};