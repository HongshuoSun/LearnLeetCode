//
// Created by sun51 on 2019/11/4.
//

#ifndef LEETCODE_71_H
#define LEETCODE_71_H
#include "Common.h"
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> pathStack;
        string current;
        int length = path.length();
        for(int i=0;i<=length;i++){
            if(i<length &&path[i]!='/'){
                current.push_back(path[i]);
            }else{
                if(current.length()>0){
                    if(current=="."){

                    }else if(current == ".."){
                        if(!pathStack.empty()) {
                            pathStack.pop_back();
                        }
                    }else{
                        pathStack.push_back(current);
                    }
                }
                current.clear();
            }
        }
        string ans= "";
        while(!pathStack.empty()){
            ans.append("/"+pathStack.front());
            pathStack.pop_front();
        }
        if(ans.length()<1){
            ans.append("/");
        }
        return ans;
    }
};
#endif //LEETCODE_71_H
