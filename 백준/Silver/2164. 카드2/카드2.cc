#include <iostream>
#include <string>
using namespace std;


//template <class ItemType>
class QueType {
	int front;
	int rear;
	int* items;
	int maxQue;

public:
	QueType();
	void push(int item);
	int pop();
	int size();
	bool empty();
	int Front();
	int back();
};
//template <class ItemType>
QueType::QueType() {
	maxQue = 500001;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new int[500001];
}

//template <class ItemType>
void QueType::push(int item) {
	rear = (rear + 1) % maxQue;
	items[rear] = item;
}

//template <class ItemType>
int QueType::pop() {
	if (front == rear) {
		return -1;
	}
	front = (front + 1) % maxQue;
	return items[front];
}

//template <class ItemType>
int QueType::size() {
	if (front <= rear)
		return rear - front;
	else
		return maxQue - (front - rear);
}

//template <class ItemType>
bool QueType::empty() {
	return (front == rear);
}

//template <class ItemType>
int QueType::Front() {
	if (front == rear)
		return -1;
	else
		return items[(front + 1) % maxQue];
}

//template <class ItemType>
int QueType::back() {
	if (front == rear)
		return -1;
	else
		return items[rear];
}

int main() {
	QueType que;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		que.push(i);
	}
	while (que.size()!=1) {
		que.pop();
		if (que.size() == 1)
			break;
		que.push(que.Front());
		que.pop();
	}
	cout << que.Front();

}