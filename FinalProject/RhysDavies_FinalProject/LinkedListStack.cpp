//  Course: ECCS 2617 Data Structures and Algorithms 1
// Author: Dr. Al-Haj - Modified: Rhys Davies (12-8-2021)
// Date: October 2021
// Description:
//  - Linked List implementation using pointers
//	the implementation includes:
//		* constructor
//		* destructor
//		* insert at the beginning
//		* delete from the beginning
//		* delete a key at an arbitrary location
//		* find a key in the list
// 		* get the size of the list
//		* display list contents

#include <iostream>
#include <string>
#include "LinkedListStack.h" 

using namespace std;

/*	LinkedList class creates a single linked list abstract data type.
		LinkedList is a collection of nodes; each node has two parts: data and a pointer.
		Node is a user defined data type defined inside the class.
*/

///* 
//	~Node: Destructor definition for Node 
//*/
//template<class Type>
//inline LinkedListStack<Type>::Node::~Node() {
//	delete next;
//}

template<typename Type>
LinkedListStack<Type>::LinkedListStack(int cap) {
	if (cap < 1) {
		throw "Invalid Stack size";
	}

	// initialize head and tail pointers to NULL
	capacity = cap;
	head = nullptr;
	tail = nullptr;
}

// delete the entire linked list, one node at a time
// "~" : Resolution Operator
template<class Type>
LinkedListStack<Type>::~LinkedListStack() {
	/*Node* current = head;
	while (current != nullptr) {
		head = head->next;
		delete current;
		current = head;
	}*/
	delete head;

	head = nullptr;
	tail = nullptr;
}


/* to add a node at the beginning, we have two cases:
	1. Empty list and 2. Non-empty list.
	if the list is empty we need to update both pointers head and tail.

	The insertion process is done in two steps:
	1. create a new temporary node to hold the new data and
		create a pointer to this new node
	2. attach the new node to the list
*/
template<class Type>
bool LinkedListStack<Type>::push(Type addData) {
	
		
	if (isFull() == true) {
		return false;
	}

	// a new node and a pointer to the new node are created
	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;

	// attaching the new node to the list
	// empty lists require updating head and tail pointers.
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	// non-empty lists require updating head pointer only
	// the order of the following statements
	// is very important, (attach then update)
	else {
		newNode->next = head;
		head = newNode;
	}

	// update the list size
	size++;
	return true;
}

/* To delete a node from the beginning of the list, we have three cases:
	1. Empty list
	2. Single node list
	3. Non-empty list

	we need a temporary pointer to point at the first node.
*/
template<class Type>
Type LinkedListStack<Type>::pop() {
	// case #1: empty list
	if (head == nullptr || isEmpty())
		throw "Empty list";
	else {
		Node* delPtr = head;
		Type data = head->data;

		// case #2: list has a single node
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		// case #3: non-empty list
		else { // list has more than one node
			head = head->next;
		}

		// to free to memory used by the deleted node
		delete delPtr;

		// update the list size
		size--;
		return data;
	}
} // end LinkedList::deleteFromBeginning()

template<class Type>
bool LinkedListStack<Type>::isEmpty() {
	return (size == 0) ? true : false;
}

template<class Type>
bool LinkedListStack<Type>::isFull() {
	return (size == capacity) ? true : false;
}

// return the nodes count
template<class Type>
int LinkedListStack<Type>::getSize() {
	return size;
}

// create a temporary pointer and traverse the entire list
// do not use head pointer.
template<class Type>
void LinkedListStack<Type>::displayList() {
	Node* current = head;

	while (current != nullptr) {
		cout << "(" << current->data << ") -> ";
		current = current->next;
	}
	cout << "00" << endl;
}

template<class Type>
string LinkedListStack<Type>::to_String() {
	string temp = "[ ";
	for (Node* curr = head; curr != nullptr; curr = curr->next) {
		if (curr->next == nullptr)
			temp = temp + curr->data + ", ";
		else 
			temp = temp + curr->data + " ]";	
	}
	return temp;
}