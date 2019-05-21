//
// Created by sun51 on 2019/5/17.
//

#ifndef LEETCODE_257BINARYTREEPATHS_H
#define LEETCODE_257BINARYTREEPATHS_H
#include "Common.h"
#include <functional>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        std::function<void(TreeNode*,string)> f = [&](TreeNode* node,string str)->void{
            if(node== nullptr)
            {
                return;
            }
            else if(node->left!= nullptr|| node->right!=nullptr)
            {
                f(node->left,str+std::to_string(node->val)+"->");
                f(node->right,str+std::to_string(node->val)+"->");
            } else{
                result.push_back(str+std::to_string(node->val));
            }
        };
        f(root,"");
        return result;
    }
};
#endif //LEETCODE_257BINARYTREEPATHS_H
