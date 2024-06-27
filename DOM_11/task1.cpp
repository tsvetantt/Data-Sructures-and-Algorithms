#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, set<pair<int, int>>> graph;   // (from,(to,cost))
vector<int> timetable;
const int INF = 1000000;

int dijkstra(int stations,int start,int end) {
    vector<int> distances(stations,INF);      
    
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   //(time to get there,node)
    pq.push({ 0, start });


    while (!pq.empty()) {
        int current = pq.top().second;
        int time_to_station = pq.top().first;
        pq.pop();

        for (auto edge : graph[current]) {
            int new_time;
            if (edge.first == end) {
                new_time = distances[current] + edge.second;
                if (new_time < distances[edge.first]) {
                    distances[edge.first] = new_time;
                    pq.push({ new_time, edge.first });
                }
                continue;
            }
            int check_time = (distances[current] + edge.second) % timetable[edge.first];
            if (check_time == 0) {
                new_time = time_to_station + edge.second;
            }
            else {
                new_time = time_to_station + (timetable[edge.first] - check_time) + edge.second;
            }
            
            if (new_time < distances[edge.first]) {
                distances[edge.first] = new_time;
                pq.push({ new_time, edge.first });
            }
        }
    }
    if (distances[end] == INF) return -1;

    return distances[end];
}



int main() {
    int stations = 0, paths = 0, start = 0, end = 0;
    cin >> stations >> paths >> start >> end;

    
    int temp_time_for_station;
    for (int i = 0; i < stations; i++) {
        cin >> temp_time_for_station;
        timetable.push_back(temp_time_for_station);
    }

    int from, to, cost;
    for (int i = 0; i < paths; i++) {
        cin >> from >> to >> cost;
        graph[from].insert(make_pair(to, cost));
    }

    cout << dijkstra(stations, start, end);



    return 0;
}
