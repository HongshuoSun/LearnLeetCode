//
// Created by sun51 on 2019/10/17.
//

#ifndef LEETCODE_232_H
#define LEETCODE_232_H
#include "Common.h"
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        dataList.push_front(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = -1;
        if(dataList.size()>0){
            result = dataList.back();
            dataList.pop_back();
        }
        return result;
    }

    /** Get the front element. */
    int peek() {
        int result = -1;
        if(dataList.size()>0){
            result = dataList.back();
        }
        return result;
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return dataList.empty();
    }
    list<int> dataList;
};

#endif //LEETCODE_232_H
