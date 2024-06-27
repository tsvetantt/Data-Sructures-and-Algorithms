#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct request {
    long int time_to_get = 0;
    long int time_to_finish = 0;
    long int index = 0;

    request(long int time_to_get, long int time_to_finish, long int index) {
        this->time_to_get = time_to_get;
        this->time_to_finish = time_to_finish;
        this->index = index;
    }
};

struct compare_time_to_get {
    bool operator() (request& r1, request& r2) {
        return r1.time_to_get > r2.time_to_get;
    }
};

struct compare_time_to_finish {
    bool operator() (request& r1, request& r2) {
        if (r1.time_to_finish == r2.time_to_finish) {
            return r1.index > r2.index;
        }
        else {
            return r1.time_to_finish > r2.time_to_finish;
        }
    }
};

void print(priority_queue<request, vector<request>, compare_time_to_get>& request_by_time_to_get, priority_queue<request, vector<request>, compare_time_to_finish>& request_by_time_to_finish, int curr_time) {
    if (!request_by_time_to_finish.empty()) {

        cout << request_by_time_to_finish.top().index << " ";
        curr_time += request_by_time_to_finish.top().time_to_finish;
        request_by_time_to_finish.pop();

        while (!request_by_time_to_get.empty() && curr_time >= request_by_time_to_get.top().time_to_get) {
            request_by_time_to_finish.push(request_by_time_to_get.top());
            request_by_time_to_get.pop();

        }

        if (!request_by_time_to_finish.empty()) {
            print(request_by_time_to_get, request_by_time_to_finish, curr_time);
        }
       
    }
}

int main() {
    int amount = 0;
    long int time_to_get = 0, time_to_finish = 0;

    cin >> amount;
    priority_queue<request, vector<request>, compare_time_to_get> request_by_time_to_get;
    priority_queue<request, vector<request>, compare_time_to_finish> request_by_time_to_finish;

    for (long int i = 0; i < amount; i++) {
        cin >> time_to_get >> time_to_finish;
        request_by_time_to_get.push(request(time_to_get, time_to_finish, i));
    }

    request_by_time_to_finish.push(request_by_time_to_get.top());
    request_by_time_to_get.pop();
    print(request_by_time_to_get, request_by_time_to_finish, request_by_time_to_finish.top().time_to_get);


    return 0;
}