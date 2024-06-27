#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct childs {
    long int left_child = -1;
    long int right_child = -1;
    long int number_of_child = 0;

    childs() {
        this->left_child = -1;
        this->right_child = -1;
        this->number_of_child = 0;
    }

    void add_childs(long int child) {
        if (number_of_child == 0) {
            this->left_child = child;
            this->number_of_child += 1;
        }
        else {
            this->right_child = child;
            this->number_of_child += 1;
        }
    }

    long int get_capacity() {
        return this->number_of_child;
    }
};

struct Node {
    long int data;
    Node* left = nullptr, * right = nullptr;

    Node(long int data) {
        this->data = data;
    }

    ~Node() {
        this->left = nullptr;
        this->right = nullptr;
    }
};


class BST {
private:
    Node* root;
public:
    void set_root(long int data) {
        Node* root_ = new Node(data);
        this->root = root_;
    }

    Node* get_root() {
        return this->root;
    }

    Node* set_tree(childs*& childs_arr, long int parent, Node* root) {
        if (childs_arr[parent].left_child != -1) {
            Node* left_ = new Node(childs_arr[parent].left_child);
            root->left = left_;
            set_tree(childs_arr, root->left->data, root->left);
        }
        else {
            return nullptr;
        }
        if (childs_arr[parent].right_child != -1) {
            Node* right_ = new Node(childs_arr[parent].right_child);
            root->right = right_;
            set_tree(childs_arr, root->right->data, root->right);
        }
        else {
            return nullptr;
        }

        return root;
    }

    Node* find_parent(Node* node, long int x) {

        if (node != nullptr) {
            if (node->data == x) {
                return node;
            }
            else {
                Node* found_node = new Node(0);
                found_node = find_parent(node->left, x);
                if (found_node == nullptr) {
                    found_node = find_parent(node->right, x);
                }
                return found_node;
            }
        }
        else {
            return nullptr;
        }
    }

    bool check_relationship(long int parent, long int child) {
        Node* parent_to_start = find_parent(get_root(), parent);
        if (parent_to_start == nullptr) return false;

        return check_if_child_in_parent_subarr(parent_to_start, child);
    }

    bool check_if_child_in_parent_subarr(Node* parent, long int to_find) {
        if (parent == nullptr) return false;
        if (parent->data == to_find) return true;
        return check_if_child_in_parent_subarr(parent->left, to_find) || check_if_child_in_parent_subarr(parent->right, to_find);
    }

};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long int N = 0, Q = 0;
    cin >> N;



    childs* childs_arr = new childs[1000001];

    long int parent = 0, child = 0;
    long int root = 0;
    for (long int i = 0; i < N - 1; i++) {
        if (i == 0) {
            cin >> parent >> child;
            childs_arr[parent].add_childs(child);
            root = parent;
            continue;
        }

        cin >> parent >> child;
        childs_arr[parent].add_childs(child);
    }

    BST tree;
    tree.set_root(root);
    tree.set_tree(childs_arr, root, tree.get_root());


    cin >> Q;
    long int x = 0, y = 0;
    vector<bool> check_arr;
    for (long int i = 0; i < Q; i++) {
        cin >> x >> y;
        if (x > N - 1 || y > N - 1) {
            check_arr.push_back(false);
        }
        if (tree.check_relationship(x, y)) {
            check_arr.push_back(true);
        }
        else {
            check_arr.push_back(false);
        }
    }

    for (long int i = 0; i < check_arr.size(); i++) {
        if (check_arr[i]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    delete[] childs_arr;


    return 0;
}