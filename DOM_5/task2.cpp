

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct node {
    long long int data;
    node* next = nullptr;
    node* prev = nullptr;

    node(int data) {
        this->data = data;
    }
};

class LinkedList {
private:
    node* head;
    node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        node* iter = head;
        while (iter != nullptr)
        {
            node* to_delete = iter;
            iter = iter->next;
            delete to_delete;
        }
        head = nullptr;
        tail = nullptr;
    }

    void push_last_element(long long int& data) {
        node* new_element = new node(data);
        if (head == nullptr && tail == nullptr) {
            head = new_element;
            tail = new_element;
        }
        else if (head != nullptr) {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
        }
    }

    void pop_first_element() {
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail->prev->next = nullptr;
            node* to_delete = tail;
            tail = tail->prev;
            delete to_delete;
        }
    }

    node* get_tail() {
        return tail;
    }

    node* get_head() {
        return head;
    }

};

int main() {
    long long int amount_of_people = 0;
    long long int size_of_subarr = 0;
    cin >> amount_of_people >> size_of_subarr;
    long long int subarr = size_of_subarr;
    long long int total = 0;

    LinkedList arr;

    if (size_of_subarr == 0) {
        for (long long int i = 0; i < amount_of_people; i++) {
            long long int temp = 0;
            cin >> temp;
            arr.push_last_element(temp);
        }
        cout << 0;
        return 0;
    }


    long long int min = 1000000001;



    for (long long int i = 0; i < amount_of_people; i++) {
        long long int temp = 0;
        cin >> temp;
        arr.push_last_element(temp);


        if (size_of_subarr == 0) {
            if (min == arr.get_tail()->data) {
                node* current = arr.get_head();
                min = current->data;
                arr.pop_first_element();
                while (current != nullptr) {
                    if (current->data <= min) {
                        min = current->data;
                    }
                    current = current->next;
                }
                total += min;
            }
            else {
                if (min >= arr.get_head()->data) {
                    min = arr.get_head()->data;
                }
                arr.pop_first_element();
                total += min;
            }
        }
        else {
            if (arr.get_head()->data <= min) {
                min = arr.get_head()->data;
            }
            if (i == (subarr - 1)) {
                total += min;
            }
            size_of_subarr--;
        }

    }

    cout << total;
    return 0;
}