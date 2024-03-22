#pragma once

template <class TValue>
class Node {
public:
	TValue info;
	Node * next;
public:
	Node (TValue info){next = nullptr;this->info = info;}
};
template <class TValue>
class LinkedList{
	typedef Node<TValue> * PNode;
	PNode head;
public:
	LinkedList (){
		head = nullptr;
	}
	~LinkedList (){
		while (head != nullptr)
		{
			PNode tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	bool isEmpty () const {return head == nullptr;}
	int size () const {
		int count = 0;
		PNode current = head;
		while (current != 0)
		{
			current = current->next;
			count++;
		}
		return count;
	}
	void pushFront(TValue value){
		PNode new_node = new Node(value);
		new_node->next = head;
		head = new_node;
	}
	void pushBack(TValue value){
		PNode new_node = new Node(value);
		PNode current = head;
		if (isEmpty())
		{
			head = new_node;
			return;
		}
		
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	void insertAfter(int index, TValue value){
		PNode new_node = new Node(value);
		PNode current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
	void insertBefore(int index, TValue value){
		PNode new_node = new Node(value);
		PNode current = head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
	void deleteAt(int index){
		if (index >= size() || index < 0)
		{
			return;
		}
		if (index == 0)
		{
			PNode temp = head;
			head = head->next;
			delete temp;
			return;
		}
		PNode current = head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		PNode tmp = current;
		current->next = current->next->next;
		delete tmp;
	}
	void Traverse() const {
		PNode current = head;
		while (current != nullptr)
		{
			std::cout << current->info << '\t';
			current = current->next;
		}
		std::cout << std::endl;
	}
	TValue& operator[] (int index){
		if (index >= size() || index < 0)
		{
			exit(1);
		}
		
		PNode current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->info;
	}
};