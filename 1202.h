//
// Created by Administrator on 2020/5/26.
//

#ifndef LEETCODE_1202_H
#define LEETCODE_1202_H
#include "Common.h"
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind unionFind(s.size());
        for(const auto& e:pairs){
            unionFind.Union(e[0],e[1]);
        }
        map<int,set<int>> unionClass = unionFind.GetClass();
        vector<bool> processed(s.size(),false);
        int length = s.size();
        string ans = s;
        for(int i=0;i<ans.size();i++){
            if(processed[i]){
                continue;
            }
            int parent = unionFind.Find(i);
            if(unionClass.count(parent)>0){
               const set<int>& data = unionClass[parent];
               int charMap['z'-'a'+1]{0};
               for(auto index:data) {
                   charMap[s[index] - 'a']++;
                   processed[index]=true;
               }
               int charIndex = 0;
               for(auto index:data){
                    while(charMap[charIndex]==0){
                        charIndex++;
                    }
                    ans[index]=charIndex+'a';
                    charMap[charIndex]--;
               }
            }
        }
        return ans;
    }
private:

    struct UnionFind{
        vector<int> parentMap;
        UnionFind(){

        }
        UnionFind(int count):parentMap(count,-1){

        }
        int Find(int a){
            if(parentMap[a]>=0){
                parentMap[a] =Find(parentMap[a]);
                return parentMap[a];
            }
            return a;
        }
        void Union(int a,int b){
            int pa = Find(a);
            int pb = Find(b);
            if(pa!=pb){

                if(parentMap[pa]<=parentMap[pb]){
                    parentMap[pa]+=  parentMap[pb];
                    parentMap[pb] = pa;
                }else{
                    parentMap[pb]+=  parentMap[pa];
                    parentMap[pa] = pb;
                }
            }
        }
        map<int,set<int>> GetClass(){
            map<int,set<int>> ans;
            for(int i=0;i<parentMap.size();i++){
                int pa = Find(i);
                if(ans.count(pa)<1){
                    ans.insert(make_pair(pa,set<int>{pa}));
                }
                if(ans[pa].count(i)<1){
                    ans[pa].insert(i);
                }
            }
            return ans;
        }
    };
};
#endif //LEETCODE_1202_H
