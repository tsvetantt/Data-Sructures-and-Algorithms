#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parents(1001);

int find_parent(int node) {
    while (node != parents[node]) {
        node = parents[node];
    }
    return node;
}

void connect(int n1, int n2) {
    int parent_of_n1 = find_parent(n1);
    int parent_of_n2 = find_parent(n2);

    if (parent_of_n1 != parent_of_n2) {
        parents[parent_of_n2] = parent_of_n1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }

    int start, end;
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        connect(start, end);
    }

    int q; 
    cin >> q;
    int r, s, e;
    for (int i = 0; i < q; i++) {
        cin >> r >> s >> e;
        if (r == 2) {
            connect(s, e);
            continue;
        }

        if (find_parent(s) == find_parent(e)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

    return 0;
}

