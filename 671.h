//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_671_H
#define LEETCODE_671_H
#include "Common.h"
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        visite(root);
        set<int>::iterator it = mySet.begin();
        it++;
        if(it!=mySet.end()){
            return *it;
        }else{
            return -1;
        }

    }
    void visite(TreeNode* node){
        if(node == nullptr){
            return;
        }
        int num = node->val;
        if(mySet.count(num)==0){
            mySet.insert(num);
        }
        if(node->left != nullptr){
           visite(node->left);
           visite(node->right);
        }
    }
    set<int> mySet;
};
#endif //LEETCODE_671_H
