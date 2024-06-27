#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
    int index = 0;
    int from = 0;
    int to = 0;
    long long int cost = 0;
    long long int profit = 0;

    edge(int from, int to, long long int cost, long long int profit, int index) {
        this->index = index;
        this->from = from;
        this->to = to;
        this->cost = cost;
        this->profit = profit;
    }

    bool operator<(edge& second) {
        return this->cost < second.cost || (this->cost == second.cost && this->profit >= second.profit);
    }
};

int find_parent(int node, vector<int>& parents) {
    while (node != parents[node]) {
        node = parents[node];
    }
    return node;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<edge> roads;
    vector<int> depth(n + 1, 1);

    vector<int> parents;
    for (int i = 0; i <= n; i++) {
        parents.push_back(i);
    }

    long long int f, t, c, p;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> c >> p;
        roads.push_back(edge(f, t, c, p, i + 1));
    }
    int counter = 0;
    sort(roads.begin(), roads.end());

    for (int i = 0; i < roads.size(); i++) {
        auto current_edge = roads[i];

        int p1 = find_parent(current_edge.from, parents);
        int p2 = find_parent(current_edge.to, parents);

        if (p1 != p2) {
            if (depth[p1] < depth[p2]) {
                parents[p1] = p2;
                depth[p2] += depth[p1];
            }
            else {
                parents[p2] = p1;
                depth[p1] += depth[p2];
            }
            cout << current_edge.index << "\n";
            counter++;
            if (counter == n - 1) {
                break;
            }
        }
    }

    return 0;
}