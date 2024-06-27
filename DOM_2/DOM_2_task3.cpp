#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class student {
    int grade;
    string name;

public:
    void setGrade(int grade) {
        this->grade = grade;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    int getGrade() {
        return this->grade;
    }
};

void swap(vector<student> &arr, int i, int j) {
    student temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<student> &arr, int low, int high) {
    int pivot = arr[high].getGrade();
    string temp = arr[high].getName();
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j].getGrade() == pivot && arr[j].getName() < temp) {
            swap(arr, i, j);
            i++;
        }
        if (arr[j].getGrade() > pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, high);
    return i;
}

void sort(vector<student> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    int amount = 0;
    cin >> amount;
    vector<student> arr(amount);

    for (int i = 0; i < amount; i++) {
        string tempName;
        cin >> tempName;
        arr[i].setName(tempName);
    }
    for (int i = 0; i < amount; i++) {
        int tempGrade = 0;
        cin >> tempGrade;
        arr[i].setGrade(tempGrade);
    }


  
    sort(arr, 0, amount - 1);


    for (int i = 0; i < amount; i++) {
        cout << arr[i].getName() << " " << arr[i].getGrade() << "\n";
    }
   

    return 0;
}

