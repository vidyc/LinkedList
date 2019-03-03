#include "Node.hh"
#include <iostream>

template<typename T> class LinkedList {
	private: 
	Node<T> *head, *tail;
	unsigned int size;
	public:
	LinkedList() {
	    head = nullptr;
	    tail = nullptr;
	    size = 0;
	}
	~LinkedList() {}
	
	//metodos basicos
	void insert_top(T data);
	void insert_bottom(T data);
	void insert(T data, int pos);
	void delete_top();
	void delete_bottom();
	void delete_pos(int pos);
	void print();
	T getHead();
	T getTail();
	T get(int pos);
	int getSize();
};
#include "../src/LinkedList.tpp"
