#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int parents[1001];

struct road {
    int from;
    int to;
    int speed_limit;

    road(int f, int t, int s) {
        this->from = f;
        this->to = t;
        this->speed_limit = s;
    }
};

int find_parent(int node) {
    while (node != parents[node]) {
        node = parents[node];
    }
    return node;
}

void connect(int n1, int n2, int p1, int p2) {
    if (p1 != p2) {
        parents[p2] = p1;
    }
}

struct op_speed {
    bool operator()( road& first, road& second) const {
        return first.speed_limit < second.speed_limit;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<road, vector<road>, op_speed> roads;

    int f, t, s;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> s;
        roads.push(road(f, t, s));
    }

    while (!roads.empty()) {

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        auto current_road = roads.top();
        int min_speed = current_road.speed_limit;
        int max_speed_diff = 0;

        for (road& currentRoad : roads) {
            if (uni.connect(currentRoad.start, currentRoad.end)) {
                maxSpeedDifference = max(maxSpeedDifference, currentRoad.optimalSpeed - minSpeed);

                //how the hell did I forget you for so long, god damn it... 
                //crucial mid-cycle break check... :D
                if (maxSpeedDifference >= minSpeedAndDifference.second) {
                    break;
                }
            }
        }

        roads.erase(roads.begin());

        if (uni.getCount() > 1) {
            continue;
        }

        if (maxSpeedDifference < minSpeedAndDifference.second) {
            minSpeedAndDifference = { minSpeed, maxSpeedDifference };
        }
    }





    return 0;
}

