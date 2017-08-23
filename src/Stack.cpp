#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
class Node {
private:
	T data;
	Node<T> *next;
public:
	Node(T data) {
		this->data = data;
		this->next = NULL;
	}
	T getData() {
		return this->data;
	}
	void setData(T data) {
		this->data = data;
	}
	Node<T> *getNext() {
		return this->next;
	}
	void setNext(Node<T> *next) {
		this->next = next;
	}
};

template<class T>
class Stack {

private:
	Node<T> *top;
	int stackSize;
public:
	Stack() {
		this->top = NULL;
		this->stackSize = 0;
	}
	void push(T data) {
		Node<T> *n = new Node<T>(data);
		stackSize++;
		if (top == NULL) {
			top = n;
			return;
		}
		n->setNext(top);
		top = n;
	}
	T pop() {
		T returnedData;
		if (stackSize <= 0) {
			return returnedData;
		}
		Node<T> *oldTop = top;
		top = top->getNext();
		returnedData = oldTop->getData();
		delete oldTop;
		stackSize--;
		return returnedData;
	}
	bool isEmpty() {
		return stackSize == 0;
	}
	int size() {
		return stackSize;
	}

};

int main() {

	Stack<int> s;

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);

	s.pop();
	while (!s.isEmpty()) {
		int e = s.pop();
		cout << e << endl;
	}

	cout << endl;
	s.push(7);
	s.push(8);

	while (!s.isEmpty()) {
		int e = s.pop();
		cout << e << endl;
	}
	return 0;
}
//By : mohamed waleed
