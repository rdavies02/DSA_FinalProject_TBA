#pragma once
#ifndef __QUEUE_LIST_CLASS_H__
#define __QUEUE_LIST_CLASS_H__

/**
	QueueList: Implementation of a queue using a linked list
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
