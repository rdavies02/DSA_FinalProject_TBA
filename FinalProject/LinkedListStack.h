#ifndef __LINKED_LIST_STACK_CLASS__
#define __LINKED_LIST_STACK_CLASS__

template<class Type>
class LinkedListStack {

private:
	// Node structure definition
	struct Node {
		Type data;
		Node* next;
	};

	Node* head; // to point at the first node
	Node* tail; // to pint at the last node
	int listSize;	// to keep track of the list size
public:
	// constructor to initialize the instantiated object
	LinkedListStack();
	// destructor to free any allocated space
	~LinkedListStack();
	// function to insert the given string at the beginning of the list
	void insertAtBeginning(Type addData);
	// function delete the first node in the list
	void deleteFromBeginning();
	// function to delete a specific node that contains the given key string
	void deleteKey(Type delData);
	// function to find if a given key is in the list
	bool findKey(Type key);
	// function to return the number of the nodes in the list
	int size();
	// function to display the contents of the list
	void displayList();

}; // class LinkedList


#endif // !__LINKED_LIST_STACK_CLASS__
