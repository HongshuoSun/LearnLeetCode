//
// Created by bugma on 7/6/2021.
//

#ifndef LEETCODE_146_H
#define LEETCODE_146_H
#include "Common.h"
#include <map>
#include <set>
class LRUCache {
public:
    LRUCache(int capacity) {
        MAX_COUNT = capacity;
    }

    int get(int key) {
        int ans = -1;
        if(idxMap.find(key)!=idxMap.end()){
            auto it = idxMap[key];
            ans = (*it).second;
            data.erase(it);
            data.push_front(std::make_pair(key,ans));
            idxMap[key] = data.begin();
        }
        return ans;
    }

    void put(int key, int value) {
        if(idxMap.find(key)!=idxMap.end()){
            auto it = idxMap[key];
            data.erase(it);
            data.push_front(std::make_pair(key,value));
            idxMap[key] = data.begin();
        }else{
            if(idxMap.size()>=MAX_COUNT){
                int lastKey = data.back().first;
                data.pop_back();
                idxMap.erase(lastKey);
            }
            data.push_front(std::make_pair(key,value));
            idxMap[key] = data.begin();
        }
    }
private:
    std::list<std::pair<int,int>> data;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> idxMap;
    int MAX_COUNT;
};
#endif //LEETCODE_146_H
