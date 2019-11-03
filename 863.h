//
// Created by sun51 on 2019/10/30.
//

#ifndef LEETCODE_863_H
#define LEETCODE_863_H

#include "Common.h"
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->k = K;
        this->target = target;
        find(root,K);
        return ans;
    }
    bool find(TreeNode* node,int & dis){
        if(node== nullptr){
            return 0;
        }
        if( node == target){
            dis = k-1;
            get(node,k);
            return true;
        }else{
            if(find(node->left,dis)){
                if(dis==0){
                    ans.push_back(node->val);
                }else if(dis>0){
                    get(node->right, dis - 1);
                }
                dis = dis-1;
                return true;
            }else if(find(node->right,dis)){
                if(dis==0){
                    ans.push_back(node->val);
                }else if(dis>0) {
                    get(node->left, dis - 1);
                }
                dis = dis-1;
                return true;
            }
            return false;
        }

    }
    void get(TreeNode* node,int dis){
        if(node== nullptr){
            return;
        }
        if(dis==0){
            ans.push_back(node->val);
        }else if(dis>0){
            get(node->left,dis-1);
            get(node->right,dis-1);
        }
    }
    TreeNode* target;
    vector<int> ans;
    int k;
};
#endif //LEETCODE_863_H
