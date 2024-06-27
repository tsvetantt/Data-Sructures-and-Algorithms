#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	Node* left_zero = nullptr;
	Node* right_one = nullptr;
};

class binary_tree {
private:
	Node* root = nullptr;
	int unique_masks = 0;
public:

	void set_root() {
		Node* root = new Node();
		this->root = root;
	}

	Node* get_root() {
		return this->root;
	}

	void all_unique_masks(Node* root) {
		if (root->left_zero == nullptr && root->right_one == nullptr) {
			this->unique_masks += 1;
			return;
		}

		if(root->left_zero != nullptr) all_unique_masks(root->left_zero);
		if(root->right_one != nullptr) all_unique_masks(root->right_one);
	}


	int get_unique_masks() {
		return this->unique_masks;
	}

	void find_masks(int n, Node* root) {
		if (n == 0) {
			return;
		}
		int binary = n % 2;

		if (binary == 0) {
			if (root->left_zero == nullptr) {
				Node* new_element = new Node();
				root->left_zero = new_element;
			}
			find_masks(n / 2, root->left_zero);
		}
		else {
			if (root->left_zero == nullptr) {
				Node* new_element = new Node();
				root->left_zero = new_element;
			}
			find_masks(n / 2, root->left_zero);

			if (root->right_one == nullptr) {
				Node* new_element = new Node();
				root->right_one = new_element;
			}
			find_masks(n / 2, root->right_one);
		}

	}
};

int main() {
	int N = 0;
	int temp = 0;
	binary_tree masks;
	masks.set_root();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		masks.find_masks(temp, masks.get_root());
	}

	masks.all_unique_masks(masks.get_root());

	cout << masks.get_unique_masks();

	return 0;
}



