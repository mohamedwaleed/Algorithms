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
	void setNext(Node<T> *next) {
		this->next = next;
	}
	Node<T> *getNext() {
		return next;
	}
	T getData() {
		return data;
	}
};

template<class T>
class LinkedList {

private:
	Node<T> *head, *tail;
public:
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

public:
	void add(T data) {
		Node<T> *n = new Node<T>(data);

		if (head == NULL) {
			head = tail = n;
		}

		tail->setNext(n);
		tail = n;
	}

	void remove(int index) {
		Node<T> *current = head, *prev = NULL;
		int i = 0;
		while (current != NULL) {
			if (i == index) {
				Node<T> *next = current->getNext();
				if (prev == NULL) {
					head = next;
				} else {
					if (next == NULL) {
						tail = prev;
					}
					prev->setNext(next);
				}
				delete current;
				break;
			}
			i++;
			prev = current;
			current = current->getNext();
		}

	}

	void print(){
		Node<T> *current = head;
		while(current != NULL){
			cout << current->getData() << " ";
			current = current->getNext();
		}
	}
};

int main() {

	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.print();

	cout << endl;
	list.remove(2);
	list.print();

	cout << endl;
	list.add(5);
	list.print();
	return 0;
}
//By : mohamed waleed
