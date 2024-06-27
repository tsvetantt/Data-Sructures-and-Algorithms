#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>


using namespace std;



const int mod = 1000000007;
vector<vector<int>> dp(1010, vector<int>(3, -1));
int sum = 1;

int ways(int n, int lastColor) {
    if (n == 0)
        return 1;
    if (dp[n][lastColor] != -1)
        return dp[n][lastColor];
    int sum = 0;
    if (lastColor != 0)
        sum = (sum + ways(n - 1, 0)) % mod;
    if (lastColor != 1)
        sum = (sum + ways(n - 1, 1)) % mod;
    if (lastColor != 2)
        sum = (sum + ways(n - 1, 2)) % mod;
    if (lastColor != 1)
        sum = (sum - ways(n - 1, 0) + mod) % mod;
    dp[n][lastColor] = sum;
    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << ways(n, 0) << endl;
    return 0;
}




//vector<vector<int>> memo(1001, vector<int> (1001,0));
//const int MAX = 10080;
//
//int answer(vector<int> numbers) {
//
//}
//
//
//int main() {
//    int amount = 0, temp = 0;
//    vector<int> numbers;
//
//    cin >> amount;
//    for (int i = 0; i < amount; i++) {
//        cin >> temp;
//        numbers.push_back(temp);
//    }
//
//    sort(numbers.begin(), numbers.end());
//
//    
//
//
//
//
//
//    return 0;
//}
