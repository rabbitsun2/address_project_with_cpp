#pragma once
#ifndef _LINKED_LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {

private:
	Node<T>* first;
	Node<T>* current;

public:
	LinkedList();
	~LinkedList();

	void push(T data);
	T pop();
	Node<T>* getFirst();
	Node<T>* getCurrent();

protected:

};

template <typename T>
LinkedList<T>::LinkedList() {

	this->first = NULL;
	this->current = NULL;

}

template <typename T>
LinkedList<T>::~LinkedList() {

	while (this->current != NULL) {
		pop();		
	}

}

template <typename T>
void LinkedList<T>::push(T data) {

	Node<T>* pNode = first;

	pNode = new Node<T>();
	pNode->setPrev(NULL);
	pNode->setData(data);
	pNode->setNext(NULL);

	// 노드가 널일 때
	if (this->first == NULL) {

		this->first = pNode;
		this->current = pNode;

	}
	// 노드 추가
	else {
		pNode->setPrev(current);
		current->setNext(pNode);
		current = pNode;
	}

}

template <typename T>
T LinkedList<T>::pop() {

	T data = NULL;
	
	if (current != NULL){
		data = current->getData();
		Node<T>* pNode = current;
		current = current->getPrev();
		
		if (pNode != NULL) {
			delete[] pNode;
			pNode = NULL;
		}

		if (current != NULL) {
			current->setNext(NULL);
		}
		else {
			this->first = NULL;
			this->current = NULL;
		}

	}

	return data;

}

template <typename T>
Node<T>* LinkedList<T>::getFirst() {
	return this->first;
}

template <typename T>
Node<T>* LinkedList<T>::getCurrent() {
	return this->current;
}

#endif // !_LINKED_LIST_H_