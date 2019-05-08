//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_173BINARYSEARCHTREEITERATOR_H
#define LEETCODE_173BINARYSEARCHTREEITERATOR_H

#include <iostream>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
#include <set>
#include <stack>
using namespace std;
class BSTIterator {
private:
    set<TreeNode*> visited;
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        if(root != NULL)
        {
            myStack.push(root);
        }
    }

    /** @return the next smallest number */
    int next() {
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
                return current->val;
            }
            else if(current->left!=NULL)
            {
                myStack.push(current->left);
            }
        }
        return -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }
};
#endif //LEETCODE_173BINARYSEARCHTREEITERATOR_H
