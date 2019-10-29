//
// Created by sun51 on 2019/10/29.
//

#ifndef LEETCODE_278_H
#define LEETCODE_278_H
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1,end = n;
        int mid = (begin+end)/2;
        while(begin<end){
            mid = begin+(end-begin)/2;
            if(isBadVersion(mid)){
                end = mid;
            }else{
                begin = mid+1;
            }
        }
        return begin;
    }
};
#endif //LEETCODE_278_H
