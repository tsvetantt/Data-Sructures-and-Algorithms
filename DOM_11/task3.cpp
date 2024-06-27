#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAXN = 500000;
const long int INF = 10000000000;


int V, E, s, e;
unordered_map<int, vector<pair<int, int>>> graph;
int min_dist[MAXN]; 

int main()
{
    cin >> V >> E >> s >> e;

   
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

  
    queue<int> q;
    q.push(s);
    min_dist[s] = 0;


    vector<vector<long int>> distances(V, vector<long int>(V, INF));
    distances[s][s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   
    pq.push({ 0, s });


    while (!pq.empty()) {
        int current = pq.top().second;
        int distanceToCurrent = pq.top().first;
        pq.pop();

        for (auto edge : graph[current]) {
            int newDistance = distanceToCurrent + edge.second;
            if (newDistance < distances[s][edge.first]) {
                distances[s][edge.first] = newDistance;
                pq.push({ newDistance, edge.first });
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= V; i++)
        if (min_dist[i] == min_dist[e])
            ans++;

    cout << ans << endl;

    return 0;
}