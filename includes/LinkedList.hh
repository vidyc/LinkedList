#include "Node.hh"
#include <iostream>

template<class T> class LinkedList {
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
	
	/*
	//metodos sofisticados
	void swap(Node<T> *n1, Node<T> *n2) {
		Node<T> *temp = n1;
		n1 = n2;
		n2 = n1;
	}

	void sort() {
		sort(head);
	}

	private:
	void sort(Node<T> *head) {
		if (head->getNext() != nullptr) {
			Node<T> *temp = head->getNext();
			sort(temp);
			if (temp->getData() < head->getData()) {
				swap(temp, head);
				sort(head);
			}
		}
	}*/

};

template<class T>
void LinkedList<T>::insert_top(T data) {
	Node<T> *temp = new Node<T>;
	temp->setData(data);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		temp->setNext(head);
		head = temp;
	}
	size++;
}

template<class T>
void LinkedList<T>::insert_bottom(T data) {
	Node<T> *temp = new Node<T>;
	temp->setData(data);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->setNext(temp);
		tail = temp;
	}
	size++;
}

template<class T>
void LinkedList<T>::insert(T data, int pos) {
	if (pos > 0 and pos < size) {
		Node<T> *pre = new Node<T>, *curr = new Node<T>, *temp = new Node<T>;
		curr = head;
		pre = head;
		for (int i = 0; i < pos; i++) {
			pre = curr;
			curr = curr->getNext();
		}
		temp->setData(data);
		temp->setNext(curr);
		pre->setNext(temp);
		size++;
	}
	else if (pos == 0) insert_top(data);
	else if (pos == size) insert_bottom(data);
	else std::cout << "index not valid" << std::endl;
}

template<class T>
void LinkedList<T>::delete_top() {
	if (size > 0) {
		Node<T> *temp = new Node<T>;
		temp = head;
		head = head->getNext();
		delete temp;
		temp = nullptr;
		size--;
	}
}

template<class T>
void LinkedList<T>::delete_bottom() {
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else {
		Node<T> *prev = new Node<T>, *curr = new Node<T>;
		curr = head;
		while (curr->getNext() != nullptr) {
			prev = curr;
			curr = curr->getNext();
		}
		tail = prev;
		prev->setNext(nullptr);
		delete curr;
		curr = nullptr;
		size--;
	}
}

template<class T>
void LinkedList<T>::delete_pos(int pos) {
	if (size > 0 and pos > 0 and pos < size - 1) {
		Node<T> *prev = new Node <T>, *curr = new Node<T>;
		curr = head;
		for (int i = 0; i < pos; i++) {
			prev = curr;
			curr = curr->getNext();
		}
		prev->setNext(curr->getNext());
		delete curr;
		curr = nullptr;
		size--;
	}
	else if (pos == 0) delete_top();
	else if (pos == size - 1) delete_bottom();
	else std::cout << "index not valid" << std::endl;
}

template<class T>
void LinkedList<T>::print() {
	Node<T> *temp = head;
	while (temp != nullptr) {
		temp->print();
		temp = temp->getNext();
	}
	std::cout << std::endl;
}
int getSize() { return size; }

template<class T>
T LinkedList<T>::getHead() {
	if (size <= 0) throw std::logic_error("List is empty!");
	return head->getData();
}

template<class T>
T LinkedList<T>::getTail() {
	if (size <= 0) throw std::logic_error("List is empty!");
	return tail->getData();
}

template<class T>
T LinkedList<T>::get(int pos) {
	if (pos >= 0 and pos < size) {
		Node<T> *temp = new Node<T>;
		temp = head;
		for (int i = 0; i < pos; i++) {
			temp = temp->getNext();
		}
		return temp->getData();
	}
	else throw std::invalid_argument("Invalid index!");
}

