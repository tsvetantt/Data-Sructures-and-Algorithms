#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int amount = 0;
	int temp = 0, sum = 0;

	cin >> amount;
	vector<int> arr;

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < amount; i++) {
		if (arr[i] < arr[i + 1]) {
			sum = sum + (arr[i + 1] - arr[i]);
		}
	}
	cout << sum;


	return 0;
}