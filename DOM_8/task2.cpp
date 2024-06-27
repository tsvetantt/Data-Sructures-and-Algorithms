#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    long double amount = 0;
    long double temp = 0;

    priority_queue<long double> left_side;
    priority_queue<long double, vector<long double>, greater<long double>> right_side;

    vector<long double> nums;
    cin >> amount;
   
    for (int i = 0; i < amount; i++) {
        cin >> temp;
        if (temp < 0) {
            continue;
        }
        nums.push_back(temp);
    }

    for (int i = 0; i < nums.size(); i++) {
        temp = nums[i];
        if (i == 0) {
            left_side.push(temp);
            cout << fixed << setprecision(1) << left_side.top() << "\n";
            continue;
        }
        if (i == 1) {
            if (temp >= left_side.top()) {
                right_side.push(temp);
                cout << fixed << setprecision(1) << (left_side.top() + right_side.top()) / 2 << "\n";
            }
            else {
                right_side.push(left_side.top());
                left_side.pop();
                left_side.push(temp);
                cout << fixed << setprecision(1) << (left_side.top() + right_side.top()) / 2 << "\n";
            }
            continue;
        }
        if (temp <= left_side.top()) {
            if (left_side.size() == right_side.size()) {
                left_side.push(temp);
                cout << fixed << setprecision(1) << left_side.top() << "\n";
            }
            else {
                right_side.push(left_side.top());
                left_side.pop();
                left_side.push(temp);
                cout << fixed << setprecision(1) << (left_side.top() + right_side.top()) / 2 << "\n";
            }
        }
        else if (temp >= right_side.top()) {
            if (left_side.size() == right_side.size()) {
                left_side.push(right_side.top());
                right_side.pop();
                right_side.push(temp);
                cout << fixed << setprecision(1) << left_side.top() << "\n";
            }
            else {
                right_side.push(temp);
                cout << fixed << setprecision(1) << (left_side.top() + right_side.top()) / 2 << "\n";
            }
        }
        else if (temp > left_side.top() && temp < right_side.top()) {
            if (left_side.size() == right_side.size()) {
                left_side.push(temp);
                cout << fixed << setprecision(1) << left_side.top() << "\n";
            }
            else {
                right_side.push(temp);
                cout << fixed << setprecision(1) << (left_side.top() + right_side.top()) / 2 << "\n";
            }
        }
    }


    return 0;
}