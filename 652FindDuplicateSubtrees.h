//
// Created by 孙宏硕 on 2019-05-13.
//

#ifndef LEETCODE_652FINDDUPLICATESUBTREES_H
#define LEETCODE_652FINDDUPLICATESUBTREES_H
#include "Common.h"
#include <sstream>
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,TreeNode*> visited;
        vector<TreeNode*> result;
        findDuplicateSubtree(root,result,visited);
        return result;
    }
    void findDuplicateSubtree(TreeNode* node,vector<TreeNode*> & result,map<string,TreeNode*>& visited)
    {
        if(node == NULL)
        {
            return;
        }
        bool  find = false;
        string str = serialize(node);
        auto it = visited.find(str);
        if(it!=visited.end() )
        {
            if(std::find(result.begin(),result.end(),it->second)==result.end())
            {
                result.push_back(it->second);

            }
        } else{
            visited.insert(make_pair(str,node));
        }

        findDuplicateSubtree(node->left,result,visited);
        findDuplicateSubtree(node->right,result,visited);
    }
    string serialize(TreeNode *root) {
        queue<TreeNode *> currentLevelQueue;
        queue<TreeNode *> nextLevelQueue;
        if (root != NULL) {
            nextLevelQueue.push(root);
        }
        string result;
        ostringstream resultSS(result);
        int currentLevelIndex = -1;
        while (!currentLevelQueue.empty() || !nextLevelQueue.empty()) {
            if (currentLevelQueue.empty()) {
                currentLevelIndex++;
                swap(currentLevelQueue, nextLevelQueue);
                continue;
            }

            auto current = currentLevelQueue.front();
            currentLevelQueue.pop();
            if (current == NULL) {
                resultSS << " " << "N";
            } else {


                resultSS << " " << (current->val);
                nextLevelQueue.push(current->left);
                nextLevelQueue.push(current->right);
            }
        }
        return resultSS.str();

    }

};

#endif //LEETCODE_652FINDDUPLICATESUBTREES_H
