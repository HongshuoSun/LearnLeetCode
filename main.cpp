#include <iostream>
#include "653TwoSumIV.h"
int main() {
    Solution s;
    TreeNode t1(5);
    TreeNode t2(3);
    TreeNode t3(6);
    TreeNode t4(2);
    TreeNode t5(4);
    TreeNode t6(7);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;
    s.findTarget(&t1,7);


    return 0;
}