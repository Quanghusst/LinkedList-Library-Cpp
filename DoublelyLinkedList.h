#pragma once 

#include <initializer_list>
using namespace std;
template <class TValue> 
class Node{
public:
	TValue info;
	Node * next;
	Node * prev;
public:
	Node (TValue info) : info(info), next(nullptr), prev(nullptr){} 
};
template <class TValue>
class DLinkedList{
	typedef Node<TValue>* PNode;
	PNode head; 
public:
	DLinkedList() : head(nullptr) {}
	DLinkedList(initializer_list<TValue> values) : head(nullptr) {
		for(const TValue& x : values)
			pushBack(x);
	}
	~DLinkedList(){clear();}
	void clear(){
		PNode tmp;
		while (head != nullptr)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		
	}
	bool isEmpty () const { return head == nullptr;}
	int size () const {
		PNode current = head;
		int count = 0;
		while (current != nullptr)
		{
			count++;
			current = current->next;
		}
		return count;
	}
	void pushFront (TValue value){
		PNode new_node = new Node<TValue>(value);
		if(isEmpty()) {head = new_node;return;}
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	void pushBack (TValue value){
		PNode new_node = new Node<TValue>(value);
		if(isEmpty()) {head = new_node;return;}
		PNode current = head;
		while (current->next != nullptr)	current = current->next;
		new_node->prev = current;
		current->next = new_node;
		
	}
	void remove(unsigned const int& index) {
		if(isEmpty())	cout << "list is empty!" << endl;
		else if(index < 0 || index >= size() )	cout << "index not found!" << endl;
		else{
			if(index == 0) {
				PNode tmp = head;
				head = head->next;
				delete tmp;
			}else{
				PNode current = head;			
				for (int i = 0; i < index; i++)
					current = current->next;
				current->prev->next = current->next;
				if(current->next != nullptr) // cho trường hợp xoá ở cuối 
					current->next->prev = current->prev;
				delete current;
			}
		}
    }
	PNode getNodeAt(unsigned const int& index) const {
		if(isEmpty())	cout << "list is empty!" << endl;
		else{
			PNode current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current;
		}
		return nullptr;
	}
	void insertAfter(PNode current_node, TValue value){
		if(isEmpty())	cout << "list is empty!" << endl;
		else if(current_node == nullptr) cout << "node not found!" << endl;
		else{
			PNode new_node = new Node<TValue>(value);
			new_node->prev = current_node;
			if(current_node->next != nullptr) // trường hợp thêm ở cuối
			{
				new_node->next = current_node->next;
				current_node->next->prev = new_node;
			}
			current_node->next = new_node;
		}
	}
	void insertBefore(PNode current_node, TValue value){
		if(isEmpty())	cout << "list is empty!" << endl;
		else if(current_node == nullptr) cout << "node not found!" << endl;
		else{
			PNode new_node = new Node<TValue>(value);
			new_node->next = current_node;
			if(current_node->prev != nullptr) // trường hợp thêm ở đầu
			{
				new_node->prev = current_node->prev;
				current_node->prev->next = new_node;
			}else{
				head = new_node;
			}
			current_node->prev = new_node;
		}
	}
public:
	friend ostream &operator << (ostream &out, const DLinkedList &H){
		if(H.isEmpty())	cout << "list is empty!";
		else{
			PNode current = H.head;
			while (current != nullptr)
			{
				out << current->info << '\t';
				current = current->next;
			}
		}
		return out;
	}
	TValue& operator[] (int index){
		PNode current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->info;
	}
};