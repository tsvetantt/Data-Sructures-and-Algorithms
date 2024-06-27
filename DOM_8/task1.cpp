#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int size_of_group = 0, amount_to_get = 0, cycles = 0;
    int amount_of_requests = 0;

    priority_queue<int, vector<int>,greater<int>> requests;
    queue<int> all_requests;
    cin >> size_of_group >> amount_to_get >> cycles;

    cin >> amount_of_requests;
    int temp = 0;

    for (int i = 0; i < amount_of_requests ; i++){
        cin >> temp;
        all_requests.push(temp);
    }

    int counter = 0;
    
    while (cycles != 0) {
        while ( !all_requests.empty() && counter != amount_to_get) {
            requests.push(all_requests.front());
            all_requests.pop();
            counter += 1;
        }
        counter = 0;

        for(int i =0; i < size_of_group;i++){
            cout << requests.top() << " ";
            requests.pop();
        }
        cycles -= 1;
    }
    


    return 0;
}
