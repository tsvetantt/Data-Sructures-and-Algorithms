#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;






int main() {
    vector<string> nameArr;
    vector<int> grades;
    int amount = 0;
    cin >> amount;

    string tempName;
    int tempGrade;
    for (int i = 0; i < amount; i++) {
        cin >> tempName;
        nameArr.push_back(tempName);
    }
    for (int i = 0; i < amount; i++) {
        cin >> tempGrade;
        grades.push_back(tempGrade);
    }

    for (int i = 1; i < amount; i++) {
        int key = grades[i];
        string key_ = nameArr[i];
        int j = i - 1;
        while (j >= 0 && grades[j] < key) {
            grades[j + 1] = grades[j];
            nameArr[j + 1] = nameArr[j];
            j--;
        }
        grades[j + 1] = key;
        nameArr[j + 1] = key_;
    }
    int startindex = 0, endindex ;

    for (int i = 0; i < amount; i++) {
        cout << nameArr[i] << " " << grades[i]<<endl;
    }

    return 0;
}