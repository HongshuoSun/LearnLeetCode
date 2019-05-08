//
// Created by 孙宏硕 on 2019-05-08.
//

#ifndef LEETCODE_507PERFECTNUMBER_H
#define LEETCODE_507PERFECTNUMBER_H
#include "Common.h"
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==0 ||num == 1)
        {
            return false;
        }

        int sum = 1;
        int upper = sqrt(num);
        for(int i=2;i<=upper;i++)
        {
            if((num%i)==0)
            {
                int j = num/i;
                sum+=i;
                if(j!=i)
                {
                    sum+=j;
                }
                if(sum > num)
                {
                    return false;
                }
            }
        }
        return sum == num;
    }
};
#endif //LEETCODE_507PERFECTNUMBER_H
