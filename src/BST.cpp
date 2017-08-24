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
	Node<T> *right;
	Node<T> *left;
	Node<T> *parent;
public:
	Node(T data) {
		this->right = NULL;
		this->left = NULL;
		this->parent = NULL;
		this->data = data;
	}

	Node<T> *getRight() {
		return this->right;
	}
	Node<T> *getLeft() {
		return this->left;
	}
	Node<T> *getParent() {
		return this->parent;
	}
	T getData() {
		return this->data;
	}
	void setRight(Node<T> *right) {
		this->right = right;
	}
	void setLeft(Node<T> *left) {
		this->left = left;
	}
	void setData(T data) {
		this->data = data;
	}
	void setParent(Node<T>* parent) {
		this->parent = parent;
	}
};

template<class T>
class BST {
private:
	Node<T> *root;

	Node<T> *search(T data) {
		Node<T> *current = root;

		while (current != NULL) {
			if (data > current->getData()) {
				current = current->getRight();
			} else if (data < current->getData()) {
				current = current->getLeft();
			} else {
				return current;
			}
		}
		return NULL;
	}

	T getMinumum(Node<T> *treeRoot) {
		Node<T> *current = treeRoot;

		while (current->getLeft() != NULL) {
			current = current->getLeft();
		}
		return current->getData();
	}
	T getMaximum(Node<T> *treeRoot) {

		Node<T> *current = treeRoot;

		while (current->getRight() != NULL) {
			current = current->getRight();
		}
		return current->getData();
	}
public:
	BST() {
		this->root = NULL;
	}
	void insert(T data) {

		Node<T> *n = new Node<T>(data);
		if (root == NULL) {
			root = n;
			return;
		}
		Node<T> *current = root;

		while (current != NULL) {
			if (data > current->getData()) {
				if (current->getRight() == NULL) {
					current->setRight(n);
					n->setParent(current);
					return;
				}
				current = current->getRight();
			} else {
				if (current->getLeft() == NULL) {
					current->setLeft(n);
					n->setParent(current);
					return;
				}
				current = current->getLeft();
			}
		}

	}

	T successor(T data) {
		Node<T> *dataNode = search(data);
		if (dataNode->getRight() != NULL) {
			T successorData = getMinumum(dataNode->getRight());
			return successorData;
		}
		Node<T> *current = dataNode;
		while (current != NULL && current->getParent()->getRight() == current) {
			current = current->getParent();
		}
		return current->getParent()->getData();
	}
	T predeccessor(T data) {
		Node<T> *dataNode = search(data);
		if (dataNode->getLeft() != NULL) {
			T predeccessorData = getMaximum(dataNode->getLeft());
			return predeccessorData;
		}
		Node<T> *current = dataNode;
		while (current != NULL && current->getParent()->getLeft() == current) {
			current = current->getParent();
		}
		return current->getParent()->getData();
	}

	bool isExist(T data) {
		Node<T> *current = root;

		while (current != NULL) {
			if (data > current->getData()) {
				current = current->getRight();
			} else if (data < current->getData()) {
				current = current->getLeft();
			} else {
				return true;
			}
		}
		return false;
	}

	T remove(T data) {
		Node<T> *dataNode = search(data);
		Node<T> *deletedNode = NULL;
		if (dataNode->getRight() == NULL || dataNode->getLeft() == NULL) {
			deletedNode = dataNode;
		} else {
			deletedNode = search(successor(data));
		}
		Node<T> *next = NULL;
		if (deletedNode->getLeft() != NULL) {
			next = deletedNode->getLeft();
		} else {
			next = deletedNode->getRight();
		}

		if (next != NULL) {
			next->setParent(deletedNode->getParent());
		}

		// if the deleted node is root so the parent will be null
		if (deletedNode->getParent() == NULL) {
			root = next;
		} else if (deletedNode == deletedNode->getParent()->getLeft()) {
			deletedNode->getParent()->setLeft(next);
		} else if (deletedNode == deletedNode->getParent()->getRight()) {
			deletedNode->getParent()->setRight(next);
		}
		if (deletedNode != dataNode) {
			dataNode->setData(deletedNode->getData());
		}
		T deletedData = deletedNode->getData();
		delete deletedNode;
		return deletedData;
	}
	void __display__(Node<T> *root) {
		if (root == NULL) {
			return;
		}
		__display__(root->getLeft());
		cout << root->getData() << " ";
		__display__(root->getRight());
	}
	void display() {
		__display__(root);
	}

};

int main() {

	BST<int> t;

	t.insert(12);
	t.insert(5);
	t.insert(18);
	t.insert(2);
	t.insert(9);
	t.insert(15);
	t.insert(19);
	t.insert(1);
	t.insert(3);
	t.insert(13);
	t.insert(17);

	t.remove(12);
	t.display();

	cout << endl;
	cout << endl << t.successor(9);
	cout << endl;
	cout << endl << t.predeccessor(15);
	return 0;
}
//By : mohamed waleed
