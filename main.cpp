#include <iostream>
#include "399.h"
int main() {


    int n = 3;
    vector<vector<string>> eq={{"a","b"},{"b","c"}};
    vector<double> val={2.0,3.0};
    vector<vector<string>> que = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    s.calcEquation(eq,val,que);

    return 0;
}