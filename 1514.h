#include "Common.h"

class Solution {
public:
    struct Edge{
        int start;
        int end;
        double cost;
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<bool> vi(n, false);

        vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            path[e[0]].push_back({ succProb[i], e[1] });
            path[e[1]].push_back({ succProb[i], e[0] });
        }

        priority_queue<pair<double, int>> pq;
        pq.push({ 1, start });

        while (!pq.empty()) {
            auto [curProb, cur] = pq.top();
            pq.pop();

            if (vi[cur]) continue;
            vi[cur] = true;

            if (cur == end) return curProb;

            for (auto [nextProb, next] : path[cur]) {
                if (vi[next]) continue;
                pq.push({ curProb * nextProb, next });
            }
        }

        return 0;
    }
private:
    vector<double> distance;
    vector<bool>   visited;
    vector<map<int,double>> graph;
};