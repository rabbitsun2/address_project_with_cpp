#pragma once
#ifndef _NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {

	private:
		Node<T>* prev;
		T data;
		Node<T>* next;

	public:
		Node<T>* getPrev();
		T getData();
		Node<T>* getNext();

		void setPrev(Node<T>* link);
		void setData(T data);
		void setNext(Node<T>* link);

	protected:


};

template <typename T>
Node<T>* Node<T>::getPrev() {
	return prev;
}

template <typename T>
T Node<T>::getData() {
	return data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* link) {
	this->prev = link;
}

template <typename T>
void Node<T>::setData(T data) {
	this->data = data;
}

template <typename T>
void Node<T>::setNext(Node<T>* link) {
	this->next = link;
}

#endif // !_NODE_H

