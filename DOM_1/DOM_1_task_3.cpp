#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int amount = 0, check = 0;
	int temp = 0;
	vector<int> arr;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		if (temp > 0) {
			arr.push_back(temp);
			check++;
		}
	}

	if (check == 0) {
		cout << 1;
	}
	else {
		sort(arr.begin(), arr.end());
		if (arr[0] > 1) {
			cout << 1;
			return 0;
		}

		for (int i = 0; i < check; i++) {
			if (i == check - 1) {
				cout << arr[i] + 1;
				break;
			}
			else if (arr[i] == arr[i + 1]) {
				continue;
			}
			else if ((arr[i] + 1) != arr[i + 1]) {
				cout << arr[i] + 1;
				break;
			}
		}
	}
	

	return 0;
}