//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_94BINARYTREEINORDERTRAVERSAL_H
#define LEETCODE_94BINARYTREEINORDERTRAVERSAL_H
#include <vector>
#include <stack>
#include <set>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        set<TreeNode*> visited;
        stack<TreeNode*> myStack;
        vector<int> result;
        if(root!=NULL)
        {
            myStack.push(root);
        }
        while(!myStack.empty())
        {
            auto current = myStack.top();
            if(  current->left == NULL || visited.find(current->left)!= visited.end() )
            {

                visited.insert(current);
                myStack.pop();
                if(current->right!=NULL)
                {
                    myStack.push(current->right);
                }
                result.push_back(current->val);
            }
            else if(current->left!=NULL)
            {
                myStack.push(current->left);
            }
        }
        return result;
    }
};
#endif //LEETCODE_94BINARYTREEINORDERTRAVERSAL_H
