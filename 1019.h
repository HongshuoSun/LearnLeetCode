//
// Created by sun51 on 2019/11/9.
//

#ifndef LEETCODE_1019_H
#define LEETCODE_1019_H

#include "Common.h"
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> dataStack;
        vector<int> ans;
        ListNode* current = head;
        int currentIndex = 0;
        while(current!= nullptr) {
            if (ans.size() < (currentIndex + 1)) {
                ans.resize(currentIndex + 1, 0);
            }
            while(!dataStack.empty()){
                auto top = dataStack.top();
                if(top.second < current->val){
                    ans[top.first]=current->val;
                    dataStack.pop();
                }else{
                    break;
                }
            }
            dataStack.push(make_pair(currentIndex,current->val));
            current = current->next;
            currentIndex++;
        }
        return ans;
    }
};
#endif //LEETCODE_1019_H
