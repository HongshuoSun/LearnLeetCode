//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_841_H
#define LEETCODE_841_H
#include "Common.h"
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int ans = 0;
        int N = rooms.size();
        vector<bool> hasKey(N,false);
        queue<int> keys;
        keys.push(0);
        hasKey[0] =true;
        while(!keys.empty()){
            ans++;
            auto current = keys.front();
            keys.pop();
            for(const auto& key:rooms[current]){
                if(!hasKey[key]){
                    keys.push(key);
                    hasKey[key] = true;
                }
            }
        }
        return ans>=N;
    }
};
#endif //LEETCODE_841_H
