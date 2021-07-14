//
// Created by bugma on 7/13/2021.
//

#ifndef LEETCODE_706_H
#define LEETCODE_706_H
#include "Common.h"
class MyHashMap {
private:
    struct KeyEqual : std::unary_function<std::pair<int,int>, bool>
    {
        std::pair<int,int> data;
        KeyEqual(std::pair<int,int> _data):
            data(_data){
        }
        bool operator()(std::pair<int,int> a) const { return  a.first == data.first; }
    };
public:
    /** Initialize your data structure here. */
    MyHashMap() :curSize(0),maxSize(16),bucket(16){

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = hashCode(key)%maxSize;
        list<std::pair<int,int>>& _list = bucket[idx];
        std::pair<int,int> keyValue = std::make_pair(key,value);
        KeyEqual keyEqual(keyValue);
        auto it = std::find_if(_list.begin(),_list.end(), keyEqual);
        if(it != _list.end()){
            it->second = value;
        }else{
            _list.push_front(keyValue);
            curSize++;
            if(curSize*2 > maxSize){
                reBuild();
            }
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = hashCode(key)%maxSize;
        list<std::pair<int,int>>& _list = bucket[idx];
        std::pair<int,int> keyValue = std::make_pair(key,-1);
        KeyEqual keyEqual(keyValue);
        auto it = std::find_if(_list.begin(),_list.end(), keyEqual);
        if(it != _list.end()){
            keyValue.second = it->second;
        }
        return keyValue.second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = hashCode(key)%maxSize;
        list<std::pair<int,int>>& _list = bucket[idx];
        std::pair<int,int> keyValue = std::make_pair(key,-1);
        KeyEqual keyEqual(keyValue);
        list<std::pair<int,int>>::iterator it = std::find_if(_list.begin(),_list.end(), keyEqual);
        if(it != _list.end()){
            _list.erase(it);
            curSize--;
        }

    }
private:
    int hashCode(int num){
        return std::hash<int>{}(num);
    }
    int curSize;
    int maxSize;
    vector<list<std::pair<int,int>>> bucket;
    void reBuild(){
        int _maxSize = maxSize*2;
        vector<list<std::pair<int,int>>> _bucket(_maxSize);
        for(auto const & _list:bucket){
            for(auto  ele:_list){
                int idx = hashCode(ele.first)%_maxSize;
                _bucket[idx].push_front(ele);
            }
        }
        maxSize = _maxSize;
        bucket = std::move(_bucket);
    }
};
#endif //LEETCODE_706_H
