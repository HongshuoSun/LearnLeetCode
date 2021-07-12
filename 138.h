
#ifndef LEETCODE_138_H
#define LEETCODE_138_H

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
#include <utility>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> nodeMap;
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        Node* oldHead = head;
        while(oldHead!=nullptr){
            Node* newNode = new Node(oldHead->val);
            cur->next = newNode;
            nodeMap[oldHead]=newNode;
            cur = cur->next;
            oldHead = oldHead->next;
        }
        oldHead = head;
        cur = dummy->next;
        while(oldHead!=nullptr)
        {
            if(oldHead->random!=nullptr){
                cur->random = nodeMap[oldHead->random];
            }
            oldHead = oldHead->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
#endif //LEETCODE_138_H
