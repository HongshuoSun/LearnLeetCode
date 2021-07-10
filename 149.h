#ifndef LEETCODE_149_H
#define LEETCODE_149_H
#include "Common.h"
#include <numeric>
#include <limits>
class Solution {
public:
    float GetSclop(const vector<int>& pa,const vector<int>& pb)
    {
        if(pa[0]-pb[0]==0 ){
            return std::numeric_limits<float>::max();
        }else if(pa[1]==pb[1]){
            return 0;
        }else{
            float num =  static_cast<float>((pa[1]-pb[1]))/static_cast<float>((pa[0]-pb[0]));
            return num;
        }
    }
    int maxPoints(vector<vector<int>>& points) {
        map<float,int> bucket;
        int pointCount = points.size();
        
        int ans = 0;
        for(int i=0;i<pointCount;i++){
            bucket.clear();
            for(int j=i+1;j<pointCount;j++){
                float sclop = GetSclop(points[i],points[j]);
                bucket[sclop]++;
            }
            for(const auto& data:bucket){
                ans = std::max(ans,data.second);
            }
        }
        return ans+1;
    }
};
#endif