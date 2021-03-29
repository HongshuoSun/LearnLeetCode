//
// Created by bugma on 2021/3/29.
//

#ifndef LEARNLEETCODE_04_03_H
#define LEARNLEETCODE_04_03_H
#include "Common.h"
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
//
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode*> ans;
        queue<TreeNode*> currentQueue;
        queue<TreeNode*> nextQueue;

        if(tree!= nullptr){
            nextQueue.push(tree);
        }
        while(!nextQueue.empty()){
            swap(currentQueue,nextQueue);
            ans.push_back(nullptr);
            ListNode* curListNode = nullptr;
            while(!currentQueue.empty()){
                TreeNode* node = currentQueue.front();
                currentQueue.pop();
                if(node->left!= nullptr){
                    nextQueue.push(node->left);
                }
                if(node->right!= nullptr){
                    nextQueue.push(node->right);
                }
                if(ans[ans.size()-1]== nullptr){
                    ans[ans.size()-1] = new ListNode(node->val);
                    curListNode = ans[ans.size()-1];
                }else{
                    curListNode->next = new ListNode(node->val);
                    curListNode = curListNode->next;
                }
            }
        }
        return ans;
    }
};
#endif //LEARNLEETCODE_04_03_H
