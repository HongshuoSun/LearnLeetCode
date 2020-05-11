#include <iostream>
#include "332.h"
int main() {
    // [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    vector<vector<string>> data = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution s;
    s.findItinerary(data);
    return 0;
}