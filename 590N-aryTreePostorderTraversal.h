//
// Created by 孙宏硕 on 2019-05-20.
//

#ifndef LEETCODE_590N_ARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODE_590N_ARYTREEPOSTORDERTRAVERSAL_H
#include "Common.h"
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        stack< pair<  Node*,int>> myStack;
        if(root!= nullptr)
        {
            myStack.push(make_pair(root,0));
        }
        while(!myStack.empty()) {
            auto current = myStack.top();
            if (current.second > 0) {
                myStack.pop();
                result.push_back(current.first->val);

            } else {
                myStack.pop();
                myStack.push(make_pair(current.first,1));
                for (int index = current.first->children.size() - 1; index >= 0; index--) {
                    auto child = current.first->children[index];
                    if (child != nullptr) {
                        myStack.push(make_pair(child,0));
                    }
                }
            }
        }
        return result;
    }
};
#endif //LEETCODE_590N_ARYTREEPOSTORDERTRAVERSAL_H
