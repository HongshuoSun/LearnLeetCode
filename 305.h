//
// Created by Administrator on 2020/5/27.
//

#ifndef LEETCODE_305_H
#define LEETCODE_305_H
#include "Common.h"
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind unionFind(m*n);
        vector<vector<bool>> flag(m,vector<bool>(n,false));
        vector<int> ans;
        for(const auto & pos:positions){
            if(flag[pos[0]][pos[1]]){
                ans.push_back(unionFind.GetCount());
                continue;
            }
            flag[pos[0]][pos[1]]=true;
            unionFind.SetParent(pos[0]*n+pos[1]);
            if(pos[0]>=1&& flag[pos[0]-1][pos[1]]){
                unionFind.Union(    pos[0]*n+pos[1] ,  (pos[0]-1)*n+pos[1] );
            }
            if(pos[0]<m-1&& flag[pos[0]+1][pos[1]]){
                unionFind.Union(    pos[0]*n+pos[1] ,  (pos[0]+1)*n+pos[1] );
            }
            if(pos[1]>=1&& flag[pos[0]][pos[1]-1]){
                unionFind.Union(    pos[0]*n+pos[1] ,  (pos[0])*n+pos[1]-1 );
            }
            if(pos[1]<n-1&& flag[pos[0]][pos[1]+1]){
                unionFind.Union(    pos[0]*n+pos[1] ,  (pos[0])*n+pos[1]+1 );
            }
            ans.push_back(unionFind.GetCount());
        }
        return ans;
    }
private:

    struct UnionFind{
        vector<int> parentMap;

        int count;
        UnionFind():count(0){

        }
        UnionFind(int c):parentMap(c,-1),count(0){

        }
        void SetParent(int index){
            parentMap[index] = -1;
            count++;
        }
        int Find(int a){
            if(parentMap[a]>=0){
                parentMap[a] =Find(parentMap[a]);
                return parentMap[a];
            }
            return a;
        }
        void Union(int a,int b){
            int pa = Find(a);
            int pb = Find(b);
            if(pa!=pb){

                if(parentMap[pa]<=parentMap[pb]){
                    parentMap[pa]+=  parentMap[pb];
                    parentMap[pb] = pa;
                }else{
                    parentMap[pb]+=  parentMap[pa];
                    parentMap[pa] = pb;
                }
                count--;
            }
        }
        int GetCount(){
            return count;
        }
    };
};
#endif //LEETCODE_305_H
