//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//#include <cmath>
//using namespace std;
//
//
//struct node {
//	int data;
//	node* next = nullptr;
//	node* prev = nullptr;
//
//	node(int data) {
//		this->data = data;
//	}
//};
//
//class linkedList {
//public:
//	node* head;
//	node* tail;
//
//	linkedList() {
//		head = nullptr;
//		tail = nullptr;
//	}
//
//	int get_tail() {
//		return tail->data;
//	}
//	void pop_back() {
//		if (head == tail) {
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//		}
//		else {
//			tail->prev->next = nullptr;
//			node* to_delete = tail;
//			tail = tail->prev;
//
//			delete to_delete;
//		}
//	}
//	void pop_front() {
//		if (head == tail) {
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//		}
//		else {
//			head->next->prev = nullptr;
//			node* to_delete = head;
//			head = head->next;
//
//			delete to_delete;
//		}
//	}
//	void delete_element(node* element_to_delete) {
//		if (element_to_delete == head) {
//			pop_front();
//			return;
//		}
//		if (element_to_delete == tail) {
//			pop_back();
//			return;
//		}
//		else {
//			node* temp = element_to_delete;
//			element_to_delete->prev->next = element_to_delete->next;
//			element_to_delete->next->prev = element_to_delete->prev;
//			delete temp;
//		}
//	}
//	void push_front(int& data) {
//		node* new_element = new node(data);
//		if (head == nullptr && tail == nullptr) {
//			head = new_element;
//			tail = new_element;
//		}
//		else {
//			new_element->next = head;
//			new_element->next->prev = new_element;
//			head = new_element;
//		}
//	}
//	void print() {
//		node* current = head;
//		while (current != nullptr) {
//			cout << current->data << " ";
//			current = current->next;
//		}
//	}
//
//	~linkedList() {
//		node* current = head;
//		while (current != nullptr) {
//			node* to_delete = current;
//			current = current->next;
//			delete to_delete;
//		}
//		head = nullptr;
//		tail = nullptr;
//	}
//
//};
//
//int main() {
//	linkedList packet;
//	int requests_amount = 0;
//	int list_size = 0;
//	cin >> requests_amount >> list_size;
//
//	vector<node*> check_arr(100000);
//	vector<int> numbers;
//
//	for (int i = 0; i < requests_amount; i++) {
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//	}
//
//	for (int i = 0; i < requests_amount; i++) {
//		if (check_arr[numbers[i] - 1] == nullptr) {
//			if (list_size == 0) {
//				check_arr[packet.get_tail() - 1] = nullptr;
//				packet.pop_back();
//				packet.push_front(numbers[i]);
//				check_arr[numbers[i] - 1] = packet.head;
//			}
//			else {
//				packet.push_front(numbers[i]);
//				check_arr[numbers[i] - 1] = packet.head;
//				list_size -= 1;
//			}
//			cout << "false" << "\n";
//		}
//		else if (check_arr[numbers[i] - 1] != nullptr) {
//			if (list_size == 0) {
//				packet.delete_element(check_arr[numbers[i] - 1]);
//				packet.push_front(numbers[i]);
//				check_arr[numbers[i] - 1] = packet.head;
//			}
//			else {
//				node* to_delete = check_arr[numbers[i] - 1];
//				check_arr[numbers[i] - 1] = nullptr;
//				packet.delete_element(to_delete);
//				packet.push_front(numbers[i]);
//				check_arr[numbers[i] - 1] = packet.head;
//				list_size -= 1;
//			}
//			cout << "true" << "\n";
//		}
//	}
//	return 0;
//}
//
