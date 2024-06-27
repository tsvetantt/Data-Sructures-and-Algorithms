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
    long long int line = 0;
    Node* left = nullptr, * right = nullptr;

    Node(long long int data,long long int line) {
        this->data = data;
        this->line = line;
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
        Node* root_ = new Node(data,0);
        this->root = root_;
    }

    Node* get_root() {
        return this->root;
    }

    void insert(long long int current_instruction, vector<instruction> &instructions, Node* current,long long int line) {
        instruction cur_ins = instructions[current_instruction];
                              
      
        //for left side
        if (cur_ins.left_side != -1 ) {  
            Node* left_ = new Node(instructions[cur_ins.left_side].index, line - 1);
            current->left = left_;
            insert(cur_ins.left_side, instructions, current->left, line - 1);
        }
   
       
        
        //for right side
        if (cur_ins.right_side != -1) {
            Node* right_ = new Node(instructions[cur_ins.right_side].index, line + 1);
            current->right = right_;
            insert(cur_ins.right_side, instructions, current->right, line + 1);
        }
       
    }

    Node* most_left_el() {
        Node* current = this->root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    Node* most_right_el() {
        Node* current = this->root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    void sum_lines(Node* node,vector<long long int>& sums, long long int diff) {

        Node* current = node;
        if (current == nullptr) {
            return;
        }
        
        sum_lines(current->left, sums, diff);
        sums[current->line + diff] += current->data;
        sum_lines(current->right, sums, diff);

    }
};





int main() {
    long long int index = 0, left = 0, right = 0;
    long long int N = 0;
    cin >> N;

    vector<instruction> instructions;
    for (long long int i = 0; i < N; i++) {
        cin >> index >> left >> right;
        instructions.push_back(instruction(index, left, right));
    }

    BST snowboard;
    snowboard.set_root(instructions[0].index);
    snowboard.insert(0, instructions,snowboard.get_root(),0);
    
    int range = abs(snowboard.most_left_el()->line) + abs(snowboard.most_right_el()->line) + 1;
    
    vector<long long int> sums(range,0);

    snowboard.sum_lines(snowboard.get_root(), sums, abs(snowboard.most_left_el()->line));

    for (long long int i = 0; i < range; i++) {
        cout << sums[i] << " ";
    }

    return 0;
}
