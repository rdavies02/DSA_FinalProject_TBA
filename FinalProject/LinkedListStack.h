#ifndef __LINKED_LIST_STACK_CLASS__
#define __LINKED_LIST_STACK_CLASS__

template<class Type>
class LinkedListStack {

private:
	// Node structure definition
	struct Node {
		Type data;
		Node* next;
		~Node();
	};
	
	Node* head;  // to point at the first node
	Node* tail;  // to pint at the last node
	int capacity; // capacity of the stack
	int size;     // to keep track of the stack size
public:
	// constructor to initialize the instantiated object
	LinkedListStack(int cap);
	// destructor to free any allocated space
	~LinkedListStack();
	// function to insert the given string at the beginning of the list
	bool push(Type addData);
	// function delete the first node in the list
	Type pop();
	// isEmpty function checks if the stack is empty
	bool isEmpty();
	// isFull function checks if the stack is full
	bool isFull();
	// function to return the number of the nodes in the list
	int getSize();
	// function to display the contents of the list
	void displayList();

}; // class LinkedList


#endif // !__LINKED_LIST_STACK_CLASS__


