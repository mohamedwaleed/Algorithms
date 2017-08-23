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
public:
	Node(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	void setRight(Node<T> *right) {
		this->right = right;
	}
	void setLeft(Node<T> *left) {
		this->left = left;
	}
	Node<T> *getRight() {
		return right;
	}
	Node<T> *getLeft() {
		return left;
	}
	T getData() {
		return data;
	}
};

template<class T>
class Tree {

private:
	Node<T> *root;
	void __add__(Node<T> *current, T data) {


		if (current == NULL) {
			if(root == NULL){
				root = new Node<T>(data);
			}
			return;
		}

		if (data < current->getData()) {
			if (current->getLeft() == NULL) {
				current->setLeft(new Node<T>(data));
			} else {
				__add__(current->getLeft(), data);
			}
		} else {
			if (current->getRight() == NULL) {
				current->setRight(new Node<T>(data));
			} else {
				__add__(current->getRight(), data);
			}
		}
	}

	void __remove__(T data) {
		Node<T> *current = root;
		if (root == NULL) {
			return;
		}
		while (current != NULL) {
			if (data > current->getData()) {
				if (current->getRight() != NULL
						&& current->getRight()->getData() == data) {

					Node<T> *currentRight = current->getRight()->getRight();
					Node<T> *currentLeft = current->getRight()->getLeft();
					delete current->getRight();
					current->setRight(currentRight);
					Node<T> *mostLeftNode = currentRight;
					while (mostLeftNode != NULL
							&& mostLeftNode->getLeft() != NULL) {
						mostLeftNode = mostLeftNode->getLeft();
					}
					if (mostLeftNode != NULL) {
						mostLeftNode->setLeft(currentLeft);
					}

					break;
				}
				current = current->getRight();
			} else if (data < current->getData()) {
				if (current->getLeft() != NULL
						&& current->getLeft()->getData() == data) {

					Node<T> *currentRight = current->getLeft()->getRight();
					Node<T> *currentLeft = current->getLeft()->getLeft();
					delete current->getLeft();
					current->setLeft(currentRight);
					Node<T> *mostLeftNode = currentRight;
					while (mostLeftNode != NULL
							&& mostLeftNode->getLeft() != NULL) {
						mostLeftNode = mostLeftNode->getLeft();
					}
					if (mostLeftNode != NULL) {
						mostLeftNode->setLeft(currentLeft);
					}

					break;
				}
				current = current->getLeft();
			} else {

				Node<T> *currentRight = current->getRight();
				Node<T> *currentLeft = current->getLeft();
				delete current;
				root = current = currentRight;
				Node<T> *mostLeftNode = currentRight;
				while (mostLeftNode != NULL && mostLeftNode->getLeft() != NULL) {
					mostLeftNode = mostLeftNode->getLeft();
				}
				if (mostLeftNode != NULL) {
					mostLeftNode->setLeft(currentLeft);
				}

				break;
			}
		}
	}
	void __print__(Node<T> *current) {
		if (current == NULL) {
			return;
		}
		cout << current->getData() << endl;
		__print__(current->getLeft());
		__print__(current->getRight());
	}

public:

	Tree() {
		root = NULL;
	}

	void add(T data) {
		__add__(root, data);
	}

	void print() {
		__print__(root);
	}
	void remove(T data) {
		__remove__(data);
	}

	int solve(Node<T> *t, int maxi) {

		if(t == NULL){
			return 0;
		}
		if(t->getData() >= maxi ){
			int l = solve(t->getLeft(), max(t->getData(), maxi));
			int r = solve(t->getRight(), max(t->getData(), maxi));
			return 1 + l + r;
		}else {
			int l = solve(t->getLeft(), max(t->getData(), maxi));
			int r = solve(t->getRight(), max(t->getData(), maxi));
			return l + r;
		}
		return 0;
	}
	int solve() {
		return solve(root, 0);
	}
};




int main() {

	Tree<int> t;
	t.add(5);
	t.add(21);
	t.add(2);
	cout << t.solve();

	return 0;
}
//By : mohamed waleed
