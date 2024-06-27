#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, vector<pair<int, int>>> graph;   // (from,(to,cost))
const long int INF = 10000000000;


void dijkstra(vector<vector<long int>>& distances, int start) {
    distances[start][start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   //(time to get there,node)
    pq.push({ 0, start });


    while (!pq.empty()) {
        int current = pq.top().second;
        int distanceToCurrent = pq.top().first;
        pq.pop();

        for (auto edge : graph[current]) {
            int newDistance = distanceToCurrent + edge.second;
            if (newDistance < distances[start][edge.first]) {
                distances[start][edge.first] = newDistance;
                pq.push({ newDistance, edge.first });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stations = 0, paths = 0, requests = 0;;
    cin >> stations >> paths >> requests;


    long int from, to, cost;
    for (int i = 0; i < paths; i++) {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    int start, end;

    vector<vector<long int>> distances(stations, vector<long int>(stations, INF));

    vector<int> ans;

    vector<bool> check(stations, false);

    for (int i = 0; i < requests; i++) {
        cin >> start >> end;
        if (!check[start]) {
            dijkstra(distances, start);
            check[start] = true;
        }
        if (distances[start][end] == INF) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(distances[start][end]);
        }
    }


    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}


