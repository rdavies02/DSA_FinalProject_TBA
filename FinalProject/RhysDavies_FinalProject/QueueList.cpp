#include<iostream>
#include "QueueList.h"
using namespace std;

/**
* QueueList Default Constructor for the QueueList class.
* creates an object that stores the current list
* and accessor functions for a given queue
*/
template<typename Type>
QueueList<Type>::QueueList() {
	currentSize = 0;

	head = nullptr;
	tail = nullptr;
}

/**
* QueueList Constructor for the QueueList class.
* creates an object that stores the current list
* and accessor functions for a given queue
* @param c - int: the capacity of the queue
*/
template<typename Type>
QueueList<Type>::QueueList(int c) {
	if (c < 1) {
		throw "Invalid Queue size";
	}

	capacity = c;
	currentSize = 0;

	head = nullptr;
	tail = nullptr;
}

/**
* ~QueueList: deconstructor for the QueueList class
* deallocates all reserved memory, including
* nodes in the queue
*/
template<class Type>
QueueList<Type>::~QueueList() {
	Node* current = head;
	while (current != nullptr) {
		head = head->next;
		delete current;
		current = head;
	}

	head = nullptr;
	tail = nullptr;
}

/**
* isEmpty: check if the queue is empty or not
* @return true if queue is empty and false otherwise
*/
template<class Type>
bool QueueList<Type>::isEmpty() {
	return head == tail ? true : false;
}

/**
* isFull: check if the queue is full or not
* @return true if queue is full and false otherwise
*/
template<class Type>
bool QueueList<Type>::isFull() {
	return currentSize == capacity ? true : false;
}

/**
* enqueue: inserts an element at the back of the queue
* follows 2 major cases: if the queue is empty,
* and if the queue has elements in it
* if empty:
*	add an empty node to the queue and set the head and
* 	tail pointers to that node
* else
*	check if the queue is full, if full, return false. if not:
*	add a new node and set its next value to head
*   and set the head pointer to the new node
* @return: return true if a new node is added, false otherwise
*/
template<class Type>
bool QueueList<Type>::enqueue(const Type addData) {
	// a new node and a pointer to the new node are created
	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;

	// attaching the new node to the list
	// empty lists require updating head and tail pointers.
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		currentSize++;
		return true;
	}
	// non-empty lists require updating head pointer only
	// the order of the following statements
	// is very important, (attach then update)
	else {
		if (isFull()) {
			dequeue();
		}
		Node* temp = tail;
		temp->next = newNode;
		tail = newNode;
		currentSize++;
		return true;
	}
	return false;
}

/**
* dequeue: remove the element from the front of the queue
* @return: returns the data from the element at the front of the queue
*/
template<class Type>
Type QueueList<Type>::dequeue() {
	Node* temp = head;
	head = head->next;
	currentSize--;
	return temp->data;
}

/**
* dequeue_back: remove the element from the back of the queue
	1: set a temp variable to point at tail
	2: find the node pointing at tail in the list
	3: get the data from the temp tail
	4: delete the temp tail
	5: set tail to point at the node pointing at the tail
* @return: returns the data from the element at the back of the queue
*/
template<class Type>
Type QueueList<Type>::dequeue_back() {
	//iterate through the list to find the node just before the tail
	for (Node* curr = head; curr != nullptr; curr = curr->next) {
		if (curr->next == tail) {
			Node* temp = tail;
			curr->next = nullptr;
			tail = curr;
			Type tempVal = temp->data;
			delete temp;
			currentSize--;
			return tempVal;
		}
	}

	
}


/**
* peek shows the element at the front of the queue, does not remove the element
* @return The value of the front element
*/
template<class Type>
Type QueueList<Type>::peek() {
	if (isEmpty()) {
		throw "Queue is EMPTY ... \n";
	}
	else {
		return head->data;
	}
}

/**
* size helper function to get the current size of the queue
* @return the current size of the Queue
*/
template<class Type>
int QueueList<Type>::size() {
	return currentSize;
}

/**
* displayQueue: helper function to display the contents of the queue
* ths function is for debugging purposes only
*/
template<class Type>
void QueueList<Type>::displayQueue() {
	Node* current = head;

	while (current != nullptr) {
		cout << "(" << current->data << ") -> ";
		current = current->next;
	}
	cout << "00" << endl;
}
