// 조화로운 세상 문제. () [] 짝 맞추는 문제. 스택이용
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
	StackType<char> st;
	string s;
	while (1) {
		st.MakeEmpty();
		getline(cin, s);
		if (s == ".")
			break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '('|| s[i] == ')' || s[i] == '[' || s[i] == ']') {
				if (st.size() == 0) {
					st.push(s[i]); // 처음들어올때 일단 넣는다.
				}
				else {
					if (s[i] == ')' && st.top() == '(') { // 근데 굳이 처음넣는거 안해도 될듯
						st.pop();
					}
					else if (s[i] == ']' && st.top() == '[') {
						st.pop();
					}
					else
						st.push(s[i]);
				}
			}
		}
		if (st.size() == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
