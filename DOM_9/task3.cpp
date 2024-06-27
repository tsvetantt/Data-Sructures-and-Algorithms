#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;
int main() {


    long long int n, m, temp, result = 0;
    cin >> n >> m;
    queue<long long int> numbers;
    unordered_map<long long int, long long int> i, k;


    for (long long int i = 0; i < n; i++) {
        cin >> temp;
        numbers.push(temp);
        k[temp] += 1;
    }

    while (!numbers.empty()) {
        temp = numbers.front();
        k[temp] -= 1;

        if (i.find(temp / m) != i.end()) {
            if (k.find(temp * m) != k.end()) {
                result += i[temp / m] * k[temp * m];
            }
        }

        i[temp] += 1;

        numbers.pop();
    }

    cout << result;

    return 0;
}