//
// Created by Administrator on 2020/5/22.
//

#ifndef LEETCODE_721_H
#define LEETCODE_721_H
#include "Common.h"
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        map<string,string> emailToName;
        UnionFind<string> unionFind;
        for(const auto & account:accounts){
            string name = account[0];
            int emailCount = account.size()-1;
            if(emailCount<1){
                continue;
            }
            string mainEmail = account[1];
            unionFind.Add(mainEmail);
            emailToName[mainEmail]=name;
            for(int i=2;i<account.size();i++){
                emailToName[account[i]]=name;
                unionFind.Add(account[i]);
                unionFind.Union(mainEmail,account[i]);
            }
        }
        map<string,set<string>> emailList;
        for(const auto& data:emailToName)
        {
            string parent = unionFind.Find(data.first);
            if(emailList.count(parent)<1){
                emailList[parent] = set<string>();
            }
            if(emailList[parent].count(data.first)<1){
                emailList[parent].insert(data.first);
            }
        }
        vector<vector<string>> ans;
        for(const auto& emails:emailList){
            ans.push_back({});
            int current = ans.size()-1;
            ans[current].push_back(emailToName[emails.first]);
            for(auto& email:emails.second) {
                ans[current].push_back(email);
            }
        }
        return ans;
    }
private:
    template< typename  T>
    struct UnionFind{
        map<T,T> parentMap;
        void Add(const T& a){
            if(parentMap.count(a)<1){
                parentMap.insert(make_pair(a,a));
            }
        }
        bool Contains(const T&a){
            return parentMap.count(a)>0;
        }
        T Find(const T&a){
            if(parentMap[a]!=a){
                parentMap[a] =Find(parentMap[a]);
            }
            return parentMap[a];
        }
        void Union(const T&a,const T&b){
            parentMap[ Find(a)]=Find(b);
        }
    };
};
#endif //LEETCODE_721_H
