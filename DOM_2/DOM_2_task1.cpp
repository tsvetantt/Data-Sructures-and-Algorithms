#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int amount = 0;
    vector<int> input; 

    cin >> amount;

    for (int i = 0; i < amount; i++) {
        int temp = 0;
        cin >> temp;
        input.push_back(temp);
    }
    
    for (int i = 0; i < amount; i++) {
        if (input[i] % 2 == 0) {
            cout << input[i]<<"\n";
        }
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] % 2 != 0) {
            cout << input[i] << "\n";
        }
    }


    return 0;
}