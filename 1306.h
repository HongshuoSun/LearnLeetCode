//
// Created by Administrator on 2020/5/22.
//

#ifndef LEETCODE_1306_H
#define LEETCODE_1306_H
#include "Common.h"
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        vector<bool> visited(N,false);
        stack<int> s;
        s.push(start);
        while(!s.empty()){
            auto current = s.top();
            s.pop();
            if(visited[current]){
                continue;
            }
            visited[current]=true;
            int right =  arr[current]+current;
            int left  = current-arr[current];
            if(right<N && !visited[right]){
                s.push(right);
            }
            if(left>=0 && !visited[left]){
                s.push(left);
            }
        }
        bool ans = false;
        for(int i=0;i<N;i++){
            if(arr[i]==0 &&visited[i]){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_1306_H
