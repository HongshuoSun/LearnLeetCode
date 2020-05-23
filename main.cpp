#include <iostream>
#include "130.h"
int main() {


    int n = 3;
    vector<vector<char>> data=
            {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution s;
    s.solve(data);

    return 0;
}