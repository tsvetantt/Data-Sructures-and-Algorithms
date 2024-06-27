#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int ternary_search(long long int l, long long int r,long long int key, long long int count,long long int power){
    if (l > r) {
        return count;
    }

        long long int mid1 = l + ((r - l) / 3) + 1;
        long long int mid2 = r - ((r - l) / 3) - 1;

        if (mid1 <= key && key <= mid2) {
            return count;
        }
        if (mid1 == key && mid2 == key) {
            return power;
        }
        if (mid1 == mid2 && key != mid1) {
            return ++power;
        }
        if (key < mid1) {
            return ternary_search(l, mid1 - 1, key, ++count, power);
        }
        else if (key > mid2) {
            return ternary_search(mid2 + 1, r, key, ++count, power);
        }
        else {
            return ternary_search(mid1 + 1, mid2 - 1, key, ++count, power);
        }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int power = 0;
    cin >> power;
    long long int powered = pow(3, power);

    int people = 0;
    cin >> people;


    vector<long long int> people_invited;
    for (int i = 0; i < people; i++) {
        long long int temp;
        cin >> temp;
        people_invited.push_back(temp);
    }

    for (int i = 0; i < people; i++)
    {
        cout << ternary_search(0, powered - 1, people_invited[i] - 1, 1, power) << "\n";
    }


    return 0;
}
