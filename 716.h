//
// Created by sun51 on 2019/11/5.
//

#ifndef LEETCODE_716_H
#define LEETCODE_716_H
#include "Common.h"
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {

    }
    void push(int x) {
        if(maxStack.empty()|| maxStack.top()<=x){
            maxStack.push(x);
        }
        dataStack.push(x);
    }

    int pop() {
        int top = dataStack.top();
        dataStack.pop();
        if (maxStack.top() <= top) {
            maxStack.pop();
        }
        return top;
    }
    int top() {
        return dataStack.top();
    }

    int peekMax() {
        return maxStack.top();
    }
    int popMax() {
        int maxTop = maxStack.top();
        maxStack.pop();
        stack<int> tempStack;
        while(!dataStack.empty()&& dataStack.top()!=maxTop){
            tempStack.push(dataStack.top());
            dataStack.pop();
        }
        if(!dataStack.empty()&& dataStack.top() == maxTop){
            dataStack.pop();
        }
        while(!tempStack.empty()){
            this->push(tempStack.top());
            tempStack.pop();
        }
        return maxTop;
    }
    stack<int> dataStack;
    stack<int> maxStack;
};

#endif //LEETCODE_716_H
