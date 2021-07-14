//
// Created by bugma on 7/12/2021.
//

#ifndef LEETCODE_622_H
#define LEETCODE_622_H
#include "Common.h"
class MyCircularQueue {
private:
    vector<int> myQueue;
    int maxSize;
    int curSize;
    int curHead;

public:
    MyCircularQueue(int k) :myQueue(k),
                            maxSize(k),
                            curSize(0),
                            curHead(0){

    }

    bool enQueue(int value) {
        if(curSize<maxSize) {
            int tailIdx = (curHead + curSize) % maxSize;
            myQueue[tailIdx] = value;
            curSize++;
            return true;
        }else{
            return false;
        }
    }

    bool deQueue() {
        if(curSize>0){
            curHead = (curHead+1)%maxSize;
            curSize--;
            return true;
        }else{
            return false;
        }
    }

    int Front() {
        return curSize>0?myQueue[curHead]:-1;
    }

    int Rear() {
        return curSize>0?myQueue[(curHead+curSize-1)%maxSize]:-1;
    }

    bool isEmpty() {
        return curSize==0;
    }

    bool isFull() {
        return curSize>=maxSize;
    }
};
#endif //LEETCODE_622_H
