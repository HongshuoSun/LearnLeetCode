//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_115_H
#define LEETCODE_115_H
#include "Common.h"
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(minStack.empty()|| minStack.top()>=x){
            minStack.push(x);
        }
        dataStack.push(x);
    }

    void pop() {
        if(!dataStack.empty()){
            int top = dataStack.top();
            dataStack.pop();
            if(minStack.top()==top){
                minStack.pop();
            }
        }
    }

    int top() {
        if(dataStack.empty()){
            return -1;
        }
        return dataStack.top();
    }

    int getMin() {
        if(!minStack.empty()){
            return minStack.top();
        }
        return -1;
    }
    stack<int> dataStack;
    stack<int> minStack;
};

#endif //LEETCODE_115_H
