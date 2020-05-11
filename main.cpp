#include <iostream>
#include "310.h"
int main() {
    vector<vector<int>> data = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    Solution s;
    s.findMinHeightTrees(6,data);
    return 0;
}