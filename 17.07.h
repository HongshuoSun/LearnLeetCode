//
// Created by bugma on 2020/5/27.
//

#ifndef LEETCODE_17_07_H
#define LEETCODE_17_07_H
#include "Common.h"
class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        UnionFind<string> unionFind;
        for(const auto& namestr :synonyms){

            int currentIndex = 1;
            int lastIndex = currentIndex;
            while(namestr[lastIndex]!=','){
                lastIndex++;
            }
            string currentStr= namestr.substr(currentIndex,lastIndex);
            if(!unionFind.Contains(currentStr)){
                unionFind.Add(currentStr);
            }
            currentIndex=lastIndex+1;

        }


        for(const auto& nameStr :names){
            int leftbracketIndex = 0;
            while(nameStr[leftbracketIndex]!='('){
                leftbracketIndex++;
            }
            string name = nameStr.substr(0,leftbracketIndex);
            int num =  stoi(  nameStr.substr(leftbracketIndex+1,nameStr.size()-1));
        }
    }
private:
    template <typename T>
    struct UnionFind{
        map<T,T> parentMap;

        UnionFind(){

        }
        void Add(const T& e){
            parentMap[e] = e;
        }
        bool Contains(const T& e){
            return parentMap.count(e)>0;
        }
        int Find(const T& a){
            if(parentMap[a]!=a){
                parentMap[a] =Find(parentMap[a]);
                return parentMap[a];
            }
            return a;
        }
        void Union(const T& a,const T& b){
            int pa = Find(a);
            int pb = Find(b);
            if(pa!=pb){
                if(parentMap[pa]<parentMap[pb]){
                    parentMap[pb] = pa;
                }else{
                    parentMap[pa] = pb;
                }
            }
        }
    };
};

#endif //LEETCODE_17_07_H
