#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class List {
public:
    Node* head, * tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void add_in_front(int data) {
        Node* newHead = new Node(data, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void remove_front() {
        if (head == nullptr) {
            throw "No element!";
        }
        head = head->next;
        tail = nullptr;
    }

    void pop_back() {
        Node* current = head;
        Node* previous = nullptr;

        while (current != tail) {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }

    void delete_element_from_possition(int position) {
        if (position == 0) {
            remove_front();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                previous = current;
                current = current->next;
            }
            else {
                throw "Invalid position";
            }
        }

        previous->next = current->next;
        if (tail == current) {
            tail = previous;
        }
        delete current;
    }

    int index_of_element_if_in_the_list(int data) {
        Node* current = head;
        int counter = 0;
        while (current != nullptr) {
            if (current->data == data) {
                return counter;
            }
            counter++;
            current = current->next;
        }
        return -1;
    }

    void print() {
        Node* i = head;
        while (i != nullptr) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << "\n";
    }

};


int main() {

    List* list = new List();
    int list_capacity = 0;
    int requests_ = 0;

    cin >> requests_ >> list_capacity;

    vector<int> requests;
    for (int i = 0; i < requests_; i++) {
        int temp;
        cin >> temp;
        requests.push_back(temp);
    }



    for (int i = 0; i < requests_; i++) {
        if (i == 0) {
            list->add_in_front(requests[i]);
            cout << "false" << "\n";
            list_capacity--;
            //list->print();
            continue;
        }
        int index = list->index_of_element_if_in_the_list(requests[i]);
        if (index == -1) {
            if (list_capacity == 0) {
                list->pop_back();
            }
            else {
                list_capacity--;
            }
            list->add_in_front(requests[i]);
            cout << "false" << "\n";
        }
        else {
            if (list_capacity == 0) {
                if (index == 2) {
                    list->pop_back();
                    list->add_in_front(requests[i]);
                    cout << "true" << "\n";
                }
                else {
                    list->delete_element_from_possition(index);
                    list->add_in_front(requests[i]);
                    cout << "true" << "\n";
                }
            }
            else {
                list_capacity--;
            }
        }
        // list->print();
    }

    return 0;
}
