#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

bool visited[1000000];
int graphs[1000000];

unordered_map<long int, set<long int>> graph;
set<long int> nodes;


void dfs(long int start, int index_of_graph) {
    stack<long int> nodes_to_be_searched;
    nodes_to_be_searched.push(start);

    long int current = 0;
    visited[start] = true;
    graphs[start] = index_of_graph;

    while (!nodes_to_be_searched.empty()) {
        current = nodes_to_be_searched.top();
        nodes_to_be_searched.pop();

        for (auto node : graph[current]) {
            if (!visited[node]) {
                visited[node] = true;
                graphs[node] = index_of_graph;
                nodes_to_be_searched.push(node);
            }
        }
    }

}

int main() {
    long int n, m, k = 0, n1 = 0, n2 = 0;
    
    

    cin >> n >> m;

    for (long int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        nodes.insert(n1);
        nodes.insert(n2);
        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }
    int index_of_graph = 1;
    for (auto node : nodes) {
        if (!visited[node]) {
            dfs(node, index_of_graph);
            ++index_of_graph;
        }
    }

    cin >> k;
    long int start_node = 0, end_node = 0;
    vector<long int> ans;
    bool check = false;

    for (long int i = 0; i < k; i++) {
        cin >> start_node >> end_node;
        
        if (graphs[start_node] == graphs[end_node]) {
            ans.push_back(1);
            continue;
        }
        ans.push_back(0);
    }


    for (long int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}