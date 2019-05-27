//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_510INORDERSUCCESSORINBSTII_H
#define LEETCODE_510INORDERSUCCESSORINBSTII_H
#include "Common.h"
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* result = nullptr;
        if(node== nullptr){

        }else if(node->right!= nullptr){
            result = node->right;
            while(result->left!= nullptr){
                result = result->left;
            }

        }else {
            auto current = node;
            while (current != nullptr) {
                if (current->parent!= nullptr && current->parent->left == current) {
                    result = current->parent;
                    break;
                } else {
                    current = current->parent;
                }
            }
        }
        return result;
    }
};
#endif //LEETCODE_510INORDERSUCCESSORINBSTII_H
