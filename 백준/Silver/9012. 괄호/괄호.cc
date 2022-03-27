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
	void MakeEmpty();
	int size();
	bool empty();
	ItemType top();
};
template <class ItemType>
StackType<ItemType>::StackType() {
	topPtr = nullptr;
}

template <class ItemType>
void StackType<ItemType>::MakeEmpty() {
	NodeType<ItemType>* tmp;
	tmp = topPtr;
	while (topPtr != nullptr) {
		tmp = topPtr;
		topPtr = topPtr->next;//이 부분 노드가 하나 있을 때 오류날거야 
		delete tmp;
	}
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
	if (topPtr == NULL)
		return;
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
	int top;
	string s;
	for (int i = 0; i < num; i++) {
		cin >> s;
		st.MakeEmpty();
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				st.push(1);
			}
			else {
				if (st.size() == 0) {
					cout << "NO" << endl;
					break;
				}
				else {
					st.pop();
				}

			}
			if (i == s.length() - 1) {
				if (st.size() == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
}
