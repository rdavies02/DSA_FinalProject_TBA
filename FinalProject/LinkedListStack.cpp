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

// initialize head and tail pointers to NULL
template<typename Type>
LinkedListStack<Type>::LinkedListStack() {
	listSize = 0;
	head = nullptr;
	tail = nullptr;
}

// delete the entire linked list, one node at a time
// "~" : Resolution Operator
template<class Type>
LinkedListStack<Type>::~LinkedListStack() {
	//cout << "destructor is executed ..." << endl;

	Node* current = head;
	while (current != nullptr) {
		head = head->next;
		delete current;
		current = head;
	}

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
void LinkedListStack<Type>::insertAtBeginning(Type addData) {

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
	listSize++;

} // end LinkedList::insertAtBeginning

/* To delete a node from the beginning of the list, we have three cases:
	1. Empty list
	2. Single node list
	3. Non-empty list

	we need a temporary pointer to point at the first node.
*/
template<class Type>
void LinkedListStack<Type>::deleteFromBeginning() {

	// case #1: empty list
	if (head == nullptr)
		cout << "Empty list" << endl;
	else {
		Node* delPtr = head;

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
		listSize--;
	}
} // end LinkedList::deleteFromBeginning()


/* to delete a node at random location, we need two pointers: one pointer
// to mark the node to be deleted, and one pointer to mark the node before
// the node to be deleted. The two pointers will point at two consecutive nodes.

// we need to consider the following cases:
// 1. key is not found
// 2. key is found in a single node linked list
// 3. key is found at the beginning
// 4. key is the last node.
*/
template<class Type>
void LinkedListStack<Type>::deleteKey(Type delData) {

	Node* temp;
	Node* current;
	current = head;
	temp = head;
	// find the key to be deleted
	while (current != nullptr && current->data != delData) {
		temp = current;
		current = current->next;
	}

	// check if you reach the end of list without finding the key
	if (current == nullptr) {
		cout << "Key is not in the list" << endl;
	}
	// key is found
	else {
		// special case : list has a single node => update head & tail
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			temp->next = current->next;

			if (current == head) {	// first node to be deleted => update head
				head = head->next;
			}
			if (current == tail) {	// last node to be deleted => update tail
				tail = temp;
			}
		} // end else

		delete current; // to free to memory used by the deleted node

		// update the list size
		listSize--;
	}
}

// function to find if a given key is in the list
template<class Type>
bool LinkedListStack<Type>::findKey(Type key) {

	// the key is not found if the list is Empty
	if (head == nullptr) {
		return false;
	}

	Node* current;
	current = head;

	// find the key by traversing the list
	while (current != nullptr && current->data != key) {
		current = current->next;
	}
	// check if you reach the end of list without finding the key
	if (current == nullptr) { return false; }
	// key is found
	else { return true; }

}

// return the nodes count
template<class Type>
int LinkedListStack<Type>::size() {
	return listSize;
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
