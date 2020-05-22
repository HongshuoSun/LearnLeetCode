//
// Created by Administrator on 2020/5/19.
//

#ifndef LEETCODE_1102_H
#define LEETCODE_1102_H
#include "Common.h"
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m=A.size();
        int n = A[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        auto comp = [](const Point& p1,const Point& p2)->bool {
            return p1.weight < p2.weight;
        };
        priority_queue<Point,vector<Point>,decltype(comp)> q(comp);
        q.push(Point{0,0,A[0][0]});
        int x;
        int y;
        int ans = 0xffffff;
        while(!q.empty()){
            auto current = q.top();
            q.pop();
            x = current.x;
            y = current.y;
            visited[x][y]=true;
            ans = min(ans,current.weight);
            if(x == m-1 && y == n-1){
                break;
            }
            if(y-1>=0 && !visited[x][y-1]){
                q.push({x,y-1,A[x][y-1]});
            }
            if(y+1<n&& !visited[x][y+1]){
                q.push({x,y+1,A[x][y+1]});
            }
            if(x+1<m&& !visited[x+1][y]){
                q.push({x+1,y,A[x+1][y]});
            }
            if(x-1>=0&& !visited[x-1][y]){
                q.push({x-1,y,A[x-1][y]});
            }
        }
        return ans;
    }
private:
    struct Point{
        int x;
        int y;
        int weight;
    };
};
#endif //LEETCODE_1102_H
