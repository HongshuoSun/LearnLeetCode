//
// Created by 孙宏硕 on 2019-05-13.
//

#ifndef LEETCODE_449SERIALIZEANDDESERIALIZEBST_H
#define LEETCODE_449SERIALIZEANDDESERIALIZEBST_H
#include "Common.h"

#include <sstream>
#include <stdio.h>
class Codec {
public:

    // Encodes a tree to a single string.
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

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
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

};
#endif //LEETCODE_449SERIALIZEANDDESERIALIZEBST_H
