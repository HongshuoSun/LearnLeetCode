#include <iostream>
#include "106ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
int main() {
    Solution s;
    vector<int> i = {9,3,15,20,7};
    vector<int> p =  {9,15,7,20,3};
    s.buildTree(i,p);


    return 0;
}