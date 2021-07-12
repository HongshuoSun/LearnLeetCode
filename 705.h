//
// Created by bugma on 7/12/2021.
//

#ifndef LEETCODE_705_H
#define LEETCODE_705_H
#include "Common.h"
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

        maxSize = 16;
        curSize = 0;
        bucket = vector<list<int>>(maxSize);
    }

    void add(int key) {
        if(curSize*2 > maxSize){
            reBuild();
        }
        int idx =  hashCode(key)%maxSize;
        bucket[idx].push_front(key);
        curSize++;
    }

    void remove(int key) {
        int idx =  hashCode(key)%maxSize;
        bucket[idx].remove(key);
        curSize--;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx =  hashCode(key)%maxSize;
        return std::find(bucket[idx].begin(),bucket[idx].end(),key)!=bucket[idx].end();
    }
    void reBuild(){
        int _maxSize = maxSize*2;
        vector<list<int>> _bucket(_maxSize);
        for(auto const & _list:bucket){
            for(auto  ele:_list){
                int idx = hashCode(ele)%_maxSize;
                _bucket[idx].push_front(ele);
            }
        }
        maxSize = _maxSize;
        bucket = std::move(_bucket);
    }
private:
    int hashCode(int num){
       return std::hash<int>{}(num);
    }
    int curSize;
    int maxSize;
    vector<list<int>> bucket;
};
#endif //LEETCODE_705_H
