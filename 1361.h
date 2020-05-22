//
// Created by Administrator on 2020/5/18.
//

#ifndef LEETCODE_1361_H
#define LEETCODE_1361_H
#include "Common.h"
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n,0);
        vector<int> outDegree(n,0);

        for(int i=0;i<leftChild.size();i++){
            int lc = leftChild[i];
            if(lc<0){
                continue;
            }
            outDegree[i]++;
            inDegree[lc]++;
        }
        for(int i=0;i<rightChild.size();i++){
            int rc = rightChild[i];
            if(rc<0){
                continue;
            }
            outDegree[i]++;
            inDegree[rc]++;
        }
        bool findRoot = false;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                if(outDegree[i]==0&&n>1){
                    return false;
                }
                if(findRoot){
                    return false;
                }
                findRoot = true;
            }else if(inDegree[i]>1){
                return false;
            }

            if(outDegree[i]>2){
                return false;
            }
        }
        return findRoot;
    }
};
#endif //LEETCODE_1361_H
