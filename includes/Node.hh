#include <iostream>

template<class T> class Node {
	T data;
	Node<T>* next;
	
	public:
	Node() {
	    next = nullptr;
	}

	~Node() {

	}
	
	void print() {	
	    std::cout << data << std::endl;
	}
	
	void setData(T data) {
	    this->data = data;
	}
	
	void setNext(Node<T> *next) {
	    this->next = next;
	}
	
	T getData() {
	    return data;
	}
	
	Node<T>* getNext() {
	    return next;
	}	
};
