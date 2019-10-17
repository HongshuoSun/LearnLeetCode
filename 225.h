//
// Created by sun51 on 2019/10/17.
//

#ifndef LEETCODE_225_H
#define LEETCODE_225_H
#include "Common.h"
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack():size(0),dataQueue(nullptr),tempQueue(nullptr) {
        dataQueue = new queue<int>();
        tempQueue = new queue<int>();
    }
    ~MyStack(){
        if(dataQueue!= nullptr){
            delete(dataQueue);
            dataQueue = nullptr;
        }
        if(tempQueue!= nullptr){
            delete(tempQueue);
            tempQueue = nullptr;
        }
    }
    /** Push element x onto stack. */
    void push(int x) {
        size++;
        dataQueue->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = -1;
        while(dataQueue->size()>1){
            auto data = dataQueue->front();
            dataQueue->pop();
            tempQueue->push(data);
        }
        if(dataQueue->size()==1){
            result = dataQueue->front();
            dataQueue->pop();
            size--;
        }
        swap(dataQueue,tempQueue);
        return result;
    }

    /** Get the top element. */
    int top() {
        int result = -1;
        while(dataQueue->size()>1){
            auto data = dataQueue->front();
            dataQueue->pop();
            tempQueue->push(data);
        }
        if(dataQueue->size()==1){
            result = dataQueue->front();
            dataQueue->pop();
            tempQueue->push(result);
        }
        swap(dataQueue,tempQueue);
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
    int size = 0;
    queue<int>* dataQueue;
    queue<int>* tempQueue;
};

#endif //LEETCODE_225_H
