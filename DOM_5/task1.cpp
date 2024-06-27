#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int x = 0;
	int y = 0;

	point(int x, int  y) {
		this->x = x;
		this->y = y;
	}
};




int main() {
	int n = 0, m = 0, days = 0;
	cin >> n >> m >> days;


	bool** matrix = new bool* [m];

	for (int i = 0; i < m; i++){
		matrix[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			matrix[i][j] = false;
		}
	}

	int x, y;

	int counter = 0;

	queue<point> points;

	while (cin >> y >> x) {
		point temp(x - 1, y - 1);
		points.push(temp);
		matrix[x - 1][y - 1] = true;
		counter++;
	}
		

	for (int i = 0; i < days; i++) {
		int size = points.size();
		for (int j = 0; j < size; j++) {
			point current = points.front();
			point left((current.x - 1), current.y);
			point right((current.x + 1), current.y);
			point top(current.x, (current.y - 1));
			point bottom(current.x, (current.y + 1));

			if (current.x - 1 >= 0) {
				if (matrix[left.x][left.y] == false) {
					matrix[left.x][left.y] = true;
					counter++;
					points.push(left);
				}
				
			}

			if (current.x + 1 < m) {
				if (matrix[right.x][right.y] == false) {
					matrix[right.x][right.y] = true;
					counter++;
					points.push(right);
				}
				

			}

			if (current.y - 1 >= 0) {
				if (matrix[top.x][top.y] == false) {
					matrix[top.x][top.y] = true;
					counter++;
					points.push(top);
				}
			}

			if (current.y + 1 < n) {
				if (matrix[bottom.x][bottom.y] == false) {
					matrix[bottom.x][bottom.y] = true;
					counter++;
					points.push(bottom);
				}
			}

			points.pop();
			/*for (long long int i = 0; i < m; i++) {
				for (long long int j = 0; j < n; j++) {
					if (matrix[i][j]) {
						cout << 1;
					}
					else {
						cout << 0;
					}
				}
				cout << endl;
			}

			cout << endl;*/
		}
	}

	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	cout << (n * m) - counter;

	return 0;
}
