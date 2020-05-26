//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_734_H
#define LEETCODE_734_H
#include "Common.h"
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size()){
            return false;
        }
        map<string,set<string>> strMap;
        for(auto& strs:pairs){
            if(strMap[strs[0]].count(strs[1])<1){
                strMap[strs[0]].insert(strs[1]);
            }
            if(strMap[strs[1]].count(strs[0])<1){
                strMap[strs[1]].insert(strs[0]);
            }
        }
        for(int i=0;i<words1.size();i++){
            if(words1[i]!=words2[i] &&  (strMap.count(words1[i])<1 ||   strMap[words1[i]].count(words2[i])<1)){
                return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_734_H
