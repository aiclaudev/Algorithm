#include <iostream>
#include <string>
using namespace std;

template <class ItemType>
struct NodeType {
	ItemType info;
	NodeType* next;
};

template<class ItemType>
class StackType {
	NodeType<ItemType>* topPtr;
public:
	StackType();
	StackType(const StackType& other);
	//~StackType();
	void push(ItemType item);
	void pop();
	void size();
	void empty();
	void top();
};
template <class ItemType>
StackType<ItemType>::StackType() {
	topPtr = nullptr;
}
/*
template <class ItemType>
StackType<ItemType>::~StackType() {
	NodeType<ItemType>* tmp;
	tmp = topPtr;
	while (tmp != nullptr) {
		tmp = topPtr;
		topPtr = topPtr->next;
		delete tmp;
	}
}
*/
template <class ItemType>
StackType<ItemType>::StackType(const StackType<ItemType>& other) {
	topPtr = other.topPtr;
}
template <class ItemType>
void StackType<ItemType>::push(ItemType item) {
	NodeType<ItemType>* newNode;
	newNode = new NodeType<ItemType>;
	newNode->info = item;
	newNode->next = topPtr;
	topPtr = newNode;
}
template <class ItemType>
void StackType<ItemType>::pop() {
	if (topPtr == nullptr) {
		cout << -1 << endl;
		return;
	}
	ItemType result;
	NodeType<ItemType>* tmp = topPtr;
	result = topPtr->info;
	topPtr = topPtr->next;
	delete tmp;
	cout << result << endl;
	return;
}
template <class ItemType>
void StackType<ItemType>::size() {
	int count = 0;
	NodeType<ItemType>* tmp;
	tmp = topPtr;
	while (tmp != nullptr) {
		count++;
		tmp = tmp->next;
	}
	cout << count << endl;
	return;
}
template <class ItemType>
void StackType<ItemType>::empty() {
	cout << (topPtr == nullptr) << endl;
	return;
}
template <class ItemType>
void StackType<ItemType>::top() {
	if (topPtr == nullptr)
		cout << -1 << endl;
	else
		cout << topPtr->info << endl;
}

int main() {
	StackType<int> st;
	int num;
	string command;
	int input;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> command;
		if(command == "push")
			cin >> input;
		if (command == "push") {
			st.push(input);
		}
		else if (command == "top") {
			st.top();
		}
		else if (command == "size")
			st.size();
		else if (command == "empty")
			st.empty();
		else if (command == "pop")
			st.pop();
	}
}