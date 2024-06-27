#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>


using namespace std;


void battle(stack<int>& positive, queue<int>& negative, int& check) {

    if (positive.empty()) {
        while (!negative.empty()) {
            cout << negative.front()<<" ";
            check++;
            negative.pop();
        }
        return;
    }

    while (!positive.empty() && !negative.empty()) {
        if (positive.top() > (negative.front() * -1)) {
            negative.pop();
        }
        else if (positive.top() < (negative.front() * -1)) {
            positive.pop();
        }
        else {
            positive.pop();
            negative.pop();
        }
    }

    while (!negative.empty()) {
        cout << negative.front() << " ";;
        check++;
        negative.pop();
    }
    
}

int main() {
    int amount_of_people = 0;
    cin >> amount_of_people;

    stack<int> positive;
    queue<int> negative;


    vector<int> people;

    for (int i = 0; i < amount_of_people; i++) {
        int temp = 0;
        cin >> temp;
        people.push_back(temp);
    }

    int index = 0;
    int check = 0;


    while (index < amount_of_people) {
        while (people[index] > 0) {
            positive.push(people[index]);
            index++;
            if (index == amount_of_people) {
                break;
            }
        }
        if (index == amount_of_people) {
            battle(positive, negative, check);
            break;
        }
        while (people[index] < 0) {
            negative.push(people[index]);
            index++;
            if (index == amount_of_people) {
                break;
            }
        }
        battle(positive, negative, check);

    }

    stack<int> correct_positive;

    while (!positive.empty()) {
        correct_positive.push(positive.top());
        positive.pop();
    }

    while (!correct_positive.empty()) {
        cout << correct_positive.top() << " ";;
        check++;
        correct_positive.pop();
    }

    if (check == 0) {
        cout << " ";
    }

    return 0;
}
