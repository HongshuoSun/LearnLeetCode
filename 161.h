//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_161_H
#define LEETCODE_161_H
#include "Common.h"
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        sLength = s.length();
        tLength = t.length();
        if(abs(sLength-tLength)>1){
            return false;
        }
        bool hasEdit = false;
        return isSame(s,t,0,0,hasEdit)&&hasEdit;
    }
    bool isSame(const string& s,const string& t,int sCurrent,int tCurrent,bool& alreadyEdit) {
        if (sCurrent < sLength && tCurrent < tLength) {
            if (s[sCurrent] == t[tCurrent]) {
                return isSame(s, t, sCurrent + 1, tCurrent + 1, alreadyEdit);
            } else {
                if (alreadyEdit) {
                    return false;
                } else {
                    if (sLength == tLength) {
                        alreadyEdit = true;
                        return isSame(s, t, sCurrent + 1, tCurrent + 1, alreadyEdit);
                    } else if (sLength < tLength) {
                        alreadyEdit = true;
                        return isSame(s, t, sCurrent, tCurrent + 1, alreadyEdit);
                    } else {
                        alreadyEdit = true;
                        return isSame(s, t, sCurrent + 1, tCurrent, alreadyEdit);
                    }
                }
            }
        } else {
            if(sCurrent==sLength&&tCurrent==tLength){
                return true;
            }else{
                if(alreadyEdit){
                    return false;
                }
                alreadyEdit = true;
                return true;
            }
        }
    }
    int sLength;
    int tLength;
};
#endif //LEETCODE_161_H
