//
// Created by sun51 on 2019/5/17.
//

#ifndef LEETCODE_988SMALLESTSTRINGSTARTINGFROMLEAF_H
#define LEETCODE_988SMALLESTSTRINGSTARTINGFROMLEAF_H

#include "Common.h"
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*,string>> currentLine;
        queue<pair<TreeNode*,string>> nextLine;
        result = "";
        hasLeft = false;
        if(root!= nullptr)
        {
            nextLine.push(make_pair( root,""));
        }
        while(!currentLine.empty()||!nextLine.empty())
        {
            if(currentLine.empty())
            {
                std::swap(currentLine,nextLine);
                continue;
            }
            auto current = currentLine.front();
            currentLine.pop();
            string currentStr = (current.second+char('a'+current.first->val));
            if(current.first->left == nullptr && current.first->right == nullptr)
            {

                reverse(currentStr.begin(),currentStr.end());
                if(!hasLeft || currentStr<result)
                {
                    hasLeft = true;
                    result = currentStr;
                }
            } else{
                if(current.first->left!= nullptr)
                {
                    nextLine.push( make_pair(current.first->left,currentStr));
                }
                if(current.first->right!= nullptr)
                {
                    nextLine.push( make_pair(current.first->right,currentStr));
                }
            }
        }
        return result;
    }

    bool hasLeft = false;
    string result;
};
#endif //LEETCODE_988SMALLESTSTRINGSTARTINGFROMLEAF_H
