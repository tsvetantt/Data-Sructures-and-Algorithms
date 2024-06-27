#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s1, s2;
    int max_substr = 0, current_substr = 0, index = 0;;

    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) {
        index = i;
        current_substr = 0;
        if (max_substr > s1.size() - i) {
            cout << max_substr;
            return 0;
        }
        for (int j = 0; j < s2.size(); j++) {
            if (s1[index] == s2[j]) {
                current_substr++;
                index++;
            }
            else {
                index = i;
                max_substr = max(max_substr, current_substr);
                current_substr = 0;
            }
        }
    }

    cout << max_substr;
    return 0;
}