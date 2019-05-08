//
// Created by 孙宏硕 on 2019-05-07.
//

#ifndef LEETCODE_621TASKSCHEDULER_H
#define LEETCODE_621TASKSCHEDULER_H
#include "Common.h"

class Solution {
public:

    struct Task {
        int taskType;
        int count;
        int cooler;
    };
    struct TaskComp{
    public:
        bool operator()(const Task& a,const Task& b){
            if( a.cooler == 0 && b.cooler > 0)
            {
                return true;
            }
            else if (a.cooler>0 && b.cooler== 0 )
            {
                return false;
            } else {
                return a.count > b.count;
            }
        }

    };
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> TaskCooler(26,0);
        vector<Task> taskSet;
        int taskCountMap[26] = {0};
        for(auto c :tasks)
        {
            taskCountMap[c-'A']++;
        }
        for(int taskType = 0;taskType<26;taskType++)
        {
            if(taskCountMap[taskType]>0) {
                taskSet.push_back(Task{taskType, taskCountMap[taskType], 0});
            }
        }
        sort(taskSet.begin(),taskSet.end(),TaskComp());
        int time = 0;
        int currentTaskType = 0;
        while(!taskSet.empty()) {
            time++;
            auto it = taskSet.begin();
            if (it->cooler == 0) {
                currentTaskType = it->taskType;
                it->count--;
                it->cooler = n;
                if (it->count == 0) {
                    taskSet.erase(it);
                }

            } else {
                currentTaskType = -1;
            }
            for (auto i = taskSet.begin(); i != taskSet.end(); i++)
            {
                if(i->taskType != currentTaskType && i->cooler > 0)
                {
                    i->cooler --;
                }
            }
            sort(taskSet.begin(),taskSet.end(),TaskComp());
        }
        return time;
    }

};
#endif //LEETCODE_621TASKSCHEDULER_H
