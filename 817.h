//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_817_H
#define LEETCODE_817_H
#include "Common.h"
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,int> subset;
        for(const auto& i:G){
            subset[i]++;
        }
        int ans = 0;
        ListNode* current = head;
        bool hasLast=false;
        while(current!= nullptr){
            if(subset.count(current->val)>0){
                subset[current->val]--;
                hasLast = true;
            }else{
                if(hasLast){
                    hasLast = false;
                    ans++;
                }
            }
            current = current->next;
        }
        if(hasLast){
            ans++;
        }
        return ans;
    }
};
#endif //LEETCODE_817_H
