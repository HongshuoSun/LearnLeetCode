//
// Created by Administrator on 2020/5/15.
//

#ifndef LEETCODE_469_H
#define LEETCODE_469_H
#include "Common.h"
class Solution {
private:
    struct Point{
        int x;
        int y;
    };
    int Cross(const vector<int>& a,const vector<int>& b,const vector<int>& p ){
        return ((a[0]-p[0])*(b[1]-p[1])-(a[1]-p[1])*(b[0]-p[0]));
    }
public:
    bool isConvex(vector<vector<int>>& points) {
        
    }
};
#endif //LEETCODE_469_H
