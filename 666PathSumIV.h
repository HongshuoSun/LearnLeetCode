//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_666PATHSUMIV_H
#define LEETCODE_666PATHSUMIV_H
#include "Common.h"
class Solution {
public:
    int pathSum(vector<int>& nums) {
        int tree[15]{-1};
        for(auto num:nums)
        {
            int level = num/100;
            int indexInLevel = num%100 /10;
            int indexInTree = pow(2,level-1)+indexInLevel -1;
            tree[indexInLevel] = num%10;
        }
        int sum = 0;
        for(int index = 14;index>=0;index--)
        {
            int currentIndex = index;
            if(tree[currentIndex] >=0)
            {
                if(currentIndex>=7  || (tree[currentIndex*2+1]==-1 && tree[currentIndex*2+2]==-1))
                {
                    while(1)
                    {
                        sum += (tree[currentIndex]);
                        if(currentIndex == 0)
                        {
                            break;
                        }
                        currentIndex /=  2;
                    }
                }
            }
        }
        return sum;
    }
};
#endif //LEETCODE_666PATHSUMIV_H
