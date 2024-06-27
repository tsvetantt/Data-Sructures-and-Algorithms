#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct instruction {
    long long int index = 0;
    long long int left_side = 0;
    long long int right_side = 0;

    instruction(long long int index, long long int left, long long int right) {
        this->index = index;
        this->left_side = left;
        this->right_side = right;
    }
};

struct Node {
    long long int data;
    Node* left = nullptr, * right = nullptr;

    Node(long long int data) {
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
    void set_root(long long int data) {
        Node* root_ = new Node(data);
        this->root = root_;
    }

    Node* get_root() {
        return this->root;
    }

    void insert(long long int current_instruction, vector<instruction>& instructions, Node* current) {
        instruction cur_ins = instructions[current_instruction];


        //for left side
        if (cur_ins.left_side != -1) {
            Node* left_ = new Node(instructions[cur_ins.left_side].index);
            current->left = left_;
            insert(cur_ins.left_side, instructions, current->left);
        }



        //for right side
        if (cur_ins.right_side != -1) {
            Node* right_ = new Node(instructions[cur_ins.right_side].index);
            current->right = right_;
            insert(cur_ins.right_side, instructions, current->right);
        }

    }

    bool is_valid_BST(Node* root) {
        return valid(root, 1, );
    }

    bool valid(Node* root, long long int min, long long int max) {
        if (root == nullptr) return true;
        if (root->data <= min || root->data >= max) return false;

        return valid(root->left, min, root->data) && valid(root->right, root->data, max);
    }

    ~BST() {
        this->root = nullptr;
    }
};




int main() {
    long long int index = 0, left = 0, right = 0;
    long long int N = 0, T = 0;
    cin >> T;

    vector<instruction> instructions;
    vector<int> results;
    for (int i = 0; i < T; i++) {
        cin >> N;
        
        for (long long int i = 0; i < N; i++) {
            cin >> index >> left >> right;
            instructions.push_back(instruction(index, left, right));
        }

        BST temp_tree;
        temp_tree.set_root(instructions[0].index);
        temp_tree.insert(0, instructions, temp_tree.get_root());


        if (temp_tree.is_valid_BST(temp_tree.get_root())) {
            results.push_back(1);
        }
        else {
            results.push_back(0);
        }

        instructions.clear();
    }

    for (long long int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    

    return 0;
}
