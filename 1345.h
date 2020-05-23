//
// Created by Administrator on 2020/5/22.
//

#ifndef LEETCODE_1345_H
#define LEETCODE_1345_H
#include "Common.h"
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()>=3) {
            for (int i = 0; i < arr.size() - 3; i++) {
                int j = i;
                while (j < arr.size() - 2 && arr[j + 1] == arr[i]) {
                    j++;
                }
                if (j - i >= 2 && arr[j - 1] == arr[i]) {
                    arr.erase(arr.begin() + i + 1, arr.begin() + j);
                }
            }
        }
        int N = arr.size();
        vector<bool> visited(N,false);
        map<int,list<int>> valMap;
        for(int i=0;i<N;i++){
            valMap[arr[i]].push_back(i);
        }
        queue<int> q;
        queue<int> next;
        next.push(0);
        int ans = 0;
        while(!next.empty()){
            swap(next,q);
            while(!q.empty()){
                auto current = q.front();
                q.pop();
                if(current==N-1){
                    return ans;
                }
                if(visited[current]){
                    continue;
                }
                visited[current]=true;
                auto val = arr[current];
                auto left = current-1;
                auto right = current+1;
                if(left>=0&&!visited[left]){
                    next.push(left);
                }
                if(right<N&& !visited[right]){
                    next.push(right);
                }
                for(auto sameValueNode:valMap[val]){
                    if(sameValueNode!=current&&!visited[sameValueNode]){
                        next.push(sameValueNode);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
#endif //LEETCODE_1345_H
