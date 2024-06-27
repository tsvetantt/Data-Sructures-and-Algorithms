#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




struct restriction
{
    int min;
    int max;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int students_amount;
    int competition_amount;

    cin >> students_amount;
    cin >> competition_amount;

    vector<int> students;
    vector<restriction> restrictions;

    for (int i = 0; i < students_amount; i++) {
        int temp = 0;
        cin >> temp;
        students.push_back(temp);
    }

    for (int i = 0; i < competition_amount; i++) {
        restriction temp;
        cin >> temp.min >> temp.max;
        restrictions.push_back(temp);
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < competition_amount; i++) {
        vector<int>::iterator min_index, max_index;
        min_index = lower_bound(students.begin(), students.end(),restrictions[i].min);
        max_index = upper_bound(students.begin(), students.end(), restrictions[i].max);
        if ((max_index - students.begin() - 1) < min_index - students.begin()) {
            cout << 0 << "\n";
            continue;
        }
        cout << ((max_index - students.begin() - 1) - (min_index - students.begin())) + 1 << "\n";
    }
    return 0;
}
