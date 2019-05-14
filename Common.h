//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

TreeNode* GetTree(const std::string& str)
{
    stringstream ss(str);
    string current;
    int index = 0;
    char buff[64];
    queue<TreeNode *> before;
    TreeNode *root = NULL;
    int count = 0;
    while (ss >> current) {
        TreeNode *parent = NULL;
        if (!before.empty()) {
            parent = before.front();
        }

        TreeNode *node = NULL;
        if (current == "N") {
            node = NULL;
        } else {
            int currentVal = 0;
            sscanf(current.c_str(), "%d", &currentVal);
            node = new TreeNode(currentVal);
            before.push(node);
        }
        if (parent != NULL) {
            if (count == 0) {
                parent->left = node;
                count++;
            } else {
                parent->right = node;
                before.pop();
                count = 0;
            }

        } else if (root == NULL) {
            root = node;
        }
    }
    ss.clear();
    return root;
}
#endif //LEETCODE_COMMON_H
