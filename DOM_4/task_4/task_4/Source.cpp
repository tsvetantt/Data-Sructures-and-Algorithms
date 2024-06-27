#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

struct node {
    int data;
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

    void push_front(int& data) {
        node* new_element = new node(data);
        if (head == nullptr && tail == nullptr){
            head = new_element;
            tail = new_element;
        }
        else if(head != nullptr) {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
        }
    }

    void pop_back() {
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

    void pop_front() {
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            head->next->prev = nullptr;
            node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    void delete_element(node* element_to_delete) {
        if (element_to_delete == head) {
            pop_front();
            return;
        }
        if (element_to_delete == tail) {
            pop_back();
            return;
        }
        else {
            element_to_delete->prev->next = element_to_delete->next;
            element_to_delete->next->prev = element_to_delete->prev;
            delete element_to_delete;
            return;
        }
    }

    int get_tail_data() {
        return tail->data;
    }

    node* get_head() {
        return head;
    }
    void print() {
        node* iter = head;
        while (iter != nullptr)
        {
            std::cout << iter->data<<" ";
            iter = iter->next;
        }
    }
};


int main() {
    long long int requests_amount = 0, packet_capacity = 0;
    cin >> requests_amount >> packet_capacity;

    LinkedList packet;
    vector<node*> pointers_to_packet(100001);
    vector<int> numbers;

    for (long long int i = 0; i < requests_amount; i++) {
        int temp;
        cin >> temp;
   		numbers.push_back(temp);
    }


    for (long long int i = 0; i < requests_amount; i++) {

        if (pointers_to_packet[numbers[i]] == nullptr) {
            if (packet_capacity == 0) {                                   //when packet_capacity == 0, packet is full
                pointers_to_packet[packet.get_tail_data()] = nullptr;
                packet.pop_back();
                packet.push_front(numbers[i]);
                pointers_to_packet[numbers[i]] = packet.get_head();
            }
            else {
                packet.push_front(numbers[i]);
                pointers_to_packet[numbers[i]] = packet.get_head();
                --packet_capacity;
            }
            cout << "false" << "\n";
        }
        else {
            packet.delete_element(pointers_to_packet[numbers[i]]);
            pointers_to_packet[numbers[i]] = nullptr;
            packet.push_front(numbers[i]);
            pointers_to_packet[numbers[i]] = packet.get_head();
            cout << "true" << "\n";
        }
    }
        //packet.print();

    return 0;
}