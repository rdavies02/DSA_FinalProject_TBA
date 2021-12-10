#ifndef __QUEUE_LIST_CLASS_H__
#define __QUEUE_LIST_CLASS_H__

/**
QueueList: Implementation of a queue using a linked list
Author: Rhys Davies (Modified: 12-9-2021)
	Basic structure of a queue: elemnets are inserted at 
	the back of the queue, follows a first in first out structure

	This implementation utilizes a linked list to store elements
	a benefit to using a linked list is more control over 
	allocated memory and easier garbage collection over an array 
	implementation. this implementation includes an dequeue_back 
	function, this dequeues the element at the back of the queue
	this is not really that helpful because it operates in O(n).
*/
template<class Type>
class QueueList {
private:
	struct Node {
		Type data;
		Node* next;
	};

	int capacity;
	int currentSize;
	Node* head;
	Node* tail;

public:
	// constructor to initialize the queue and set the capacity
	QueueList(int c);
	// destructor to free all allocated memory
	~QueueList();
	// insert to the queue
	bool enqueue(const Type addData);
	// remove from the queue
	Type dequeue();
	// remove from the back of the queue
	Type dequeue_back();
	// look at the front of the queue
	Type peek();
	// check if the queue is empty
	bool isEmpty();
	// check if the queue is full (reached the max capacity)
	bool isFull();
	// get the current size
	int size();
	// print the contents of the queue
	void displayQueue();
};

#endif // !__QUEUE_LIST_CLASS_H__