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
#include <assert.h>

using namespace std;

template<class T>
class MinHeap {
private:
	vector<T> heap;

	void heapifyUp(int index) {
		int parentIndex = parent(index);

		if (index == 0 || heap[index] > heap[parentIndex]) {
			return;
		}
		swap(heap[index], heap[parentIndex]);

		heapifyUp(parentIndex);
	}
	void heapifyDown(int index) {
		int selChild = -1;
		int leftIndex = left(index);
		if (leftIndex == -1) {
			return;
		}
		selChild = leftIndex;
		int rightIndex = right(index);
		if(rightIndex != -1 && heap[rightIndex] < heap[selChild]) {
			selChild = rightIndex;
		}
		swap(heap[index], heap[selChild]);
		heapifyDown(selChild);
	}
	int parent(int node) {
		return (node == 0) ? -1 : (node - 1) / 2;
	}
	int left(int node) {
		return (node >= size()) ? -1 : node * 2 + 1;
	}
	int right(int node) {
		return (node >= size()) ? -1 : node * 2 + 2;
	}
public:
	T top() {
		if (heap.size() == 0) {
			assert(false);
		}
		return heap.front();
	}
	void push(T data) {
		heap.push_back(data);
		heapifyUp(heap.size() - 1);
	}
	void pop() {
		if (heap.size()) {
			heap[0] = heap.back();
			heap.pop_back();
			heapifyDown(0);
		}
	}
	void print() {
		for (int i = 0; i < (int)heap.size(); i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	int size() {
		return heap.size();
	}
};

int main() {

	MinHeap<int> h;
	h.push(5);
	h.push(4);
	h.push(3);
	h.push(2);
	h.push(1);

	cout << h.top();
	h.pop();
	cout << h.top();
	h.pop();
	cout << h.top();

	return 0;
}
//By : mohamed waleed
