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
	~StackType();
	void push(ItemType item);
	void pop();
	int size();
	bool empty();
	ItemType top();
};
template <class ItemType>
StackType<ItemType>::StackType() {
	topPtr = nullptr;
}

template <class ItemType>
StackType<ItemType>::~StackType() {
	NodeType<ItemType>* tmp;
	tmp = topPtr;
	while (topPtr != nullptr) {
		tmp = topPtr;
		topPtr = topPtr->next;//이 부분 노드가 하나 있을 때 오류날거야 
		delete tmp;
	}
}

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
	return;
}
template <class ItemType>
int StackType<ItemType>::size() {
	int count = 0;
	NodeType<ItemType>* tmp;
	tmp = topPtr;
	while (tmp != nullptr) {
		count++;
		tmp = tmp->next;
	}	
	return count;
}
template <class ItemType>
bool StackType<ItemType>::empty() {
	return (topPtr == nullptr);
	
}
template <class ItemType>
ItemType StackType<ItemType>::top() {
	if (topPtr == nullptr)
		return -1;
	else
		return topPtr->info;
}

int main() {
	StackType<int> st;
	int num;
	cin >> num;
	int num2;
	for (int i = 0; i < num; i++) {
		cin >> num2;
		if (num2 == 0) {
			st.pop();
		}
		else {
			st.push(num2);
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;
}