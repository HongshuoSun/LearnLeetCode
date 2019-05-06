//
// Created by 孙宏硕 on 2019-05-06.
//

#ifndef LEETCODE_170TWOSUMIII_H
#define LEETCODE_170TWOSUMIII_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
using namespace std;
class TwoSum {

public:

    TwoSum() {

    }


    void add(int number) {
        if(nums.find(number)==nums.end())
        {
            nums.insert(number);
        } else  if(sameNums.find(number)==sameNums.end()){
            sameNums.insert(number);
        }
    }


    bool find(int value) {
        auto it = nums.cbegin();
        auto end = nums.cend();
        for(;it!=end;it++)
        {
            auto current = *it;
            auto rend = value-current;
            if(nums.find(rend)!=nums.cend())
            {
                if(rend == current )
                {
                    if(sameNums.find(rend)!=sameNums.cend()) {
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
        return  false;
    }

private:

    set<int> nums;
    set<int> sameNums;
};

#endif //LEETCODE_170TWOSUMIII_H
