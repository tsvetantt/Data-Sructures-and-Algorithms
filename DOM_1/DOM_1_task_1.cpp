#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int amount = 0;
	int size = 0,deletedLetter = 0;
	
	cin >> amount;
	vector<int> arr;
	

	for (int i = 0; i < amount; i++) {
		deletedLetter = 0;
		cin >> size;
		string tempSchedule;
		cin >> tempSchedule;

		for (int i = 0; i < size - 1; i++) {
			if (tempSchedule[i] != tempSchedule[i + 1]) {
				continue;
			}
			else{
				deletedLetter++;
			}
		}

		arr.push_back(deletedLetter);
	}


	for (int i = 0; i < amount; i++) {
		cout << arr[i] << endl;
	}
	

	return 0;
}