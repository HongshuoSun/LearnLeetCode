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
#endif //LEETCODE_COMMON_H
