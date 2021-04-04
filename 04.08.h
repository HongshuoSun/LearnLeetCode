//
// Created by bugma on 2021/3/29.
//

#ifndef LEETCODE_04_08_H
#define LEETCODE_04_08_H
#include "Common.h"
class Solution {
public:
    const int pBit = 1;
    const int qBit = 2;
    list<TreeNode*> pList;
    list<TreeNode*> qList;
    int Visit(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==nullptr){
            return 0;
        }
        int hasQ=0;
        int hasP=0;
        if(node==p){
            pList.push_back(node);
            hasP=1<<pBit;
        }
        if(node==q){
            qList.push_back(node);
            hasQ=1<<qBit;
        }
        if(hasP&&hasQ){
            return hasP|hasQ;
        }
        int lRes = Visit(node->left,p,q);
        if(lRes& (1<<pBit)){
            pList.push_back(node);
            hasP = 1<<pBit;
        }
        if(lRes& (1<<qBit)){
            qList.push_back(node);
            hasQ = 1<<qBit;
        }
        int rRes = Visit(node->right,p,q);
        if(rRes& (1<<pBit)){
            pList.push_back(node);
            hasP = 1<<pBit;
        }
        if(rRes& (1<<qBit)){
            qList.push_back(node);
            hasQ = 1<<qBit;
        }
        return hasP|hasQ;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        Visit(root,p,q);
        list<TreeNode*>::reverse_iterator pIt= this->pList.rbegin();
        list<TreeNode*>::reverse_iterator qIt = this->qList.rbegin();

        while(pIt!=pList.rend() && qIt!=qList.rend()&&  *pIt == *qIt){
            ans = *pIt;
            pIt++;
            qIt++;
        }
        return ans;
    }
};
#endif //LEETCODE_04_08_H
