//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_535_H
#define LEETCODE_535_H
#include "Common.h"
class Solution {
public:
    Solution(){

    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeMap.count(longUrl)>0){
            return encodeMap[longUrl];
        }
        int length = deCode.size();
        encodeMap.insert(make_pair(longUrl,to_string(length)));
        deCode.push_back(longUrl);
        return to_string(length);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        char buf[256];
        int num;
        num =  std::stoi(shortUrl);
        return deCode[num];
    }
    map<string,string> encodeMap;
    vector<string> deCode;
};
#endif //LEETCODE_535_H
