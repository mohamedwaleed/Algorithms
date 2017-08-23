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
class Queue {
private:
	Node<T> *head;
	Node<T> *tail;
	int queueSize;
public:
	Queue() {
		this->queueSize = 0;
		this->head = NULL;
		this->tail = NULL;
	}
	void push(T data) {
		Node<T> *n = new Node<T>(data);
		queueSize++;
		if (head == NULL) {
			head = tail = n;
			return;
		}
		tail->setNext(n);
		tail = n;
	}
	T pop() {
		T returnedData;
		if (queueSize <= 0) {
			return returnedData;
		}
		Node<T> *tmpHead = head;
		returnedData = tmpHead->getData();
		head = head->getNext();
		delete tmpHead;
		queueSize--;
		return returnedData;
	}
	bool isEmpty() {
		return queueSize == 0;
	}
	int size() {
		return queueSize;
	}
};

int main() {

	Queue<int> q;
	q.push(5);
	q.push(4);
	q.push(3);
	q.push(2);

	while (!q.isEmpty()) {
		int e = q.pop();
		cout << e << " ";
	}
	q.push(7);
	q.push(8);

	while (!q.isEmpty()) {
		int e = q.pop();
		cout << e << " ";
	}
	return 0;
}
//By : mohamed waleed
