#pragma once
#include <iostream>
# include "NodeP.h"
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

template <typename T>
class priQ {
private:
	//Node<T>* backPtr;
	NodeP<T>* frontPtr;

public:
	priQ();
	void insert(T item, double priority);
	void Delete(T& abc);
	void show(); //print queue 
	void peek(T& d);
	//bool isEmpty() const;
};




template <typename T>
priQ<T>::priQ() {
	frontPtr = nullptr;
};

template <typename T>
void priQ<T>::insert(T item, double pri) {
	NodeP <T>* A = new NodeP<T>();
	NodeP <T>* B;
	//A = new Node;
	A->setItem(item);
	A->setpriority(pri);
	if (frontPtr == NULL || pri > frontPtr->getpriority())
	{
		A->setNext(frontPtr);
		frontPtr = A;
	}
	else
	{
		B = frontPtr;
		while (B->getNext() != NULL &&
			B->getNext()->getpriority() >= pri) {
			B = B->getNext();
		}
		A->setNext(B->getNext());
		B->setNext(A);
	}
}

template <typename T>
void priQ<T>::Delete(T& abc) {
	//Node <T>* A;
	if (frontPtr != nullptr) {
		abc = frontPtr->getItem();
		//A = frontPtr;
		frontPtr = frontPtr->getNext();
		//return A->getItem();
		//delete A;
		//A = nullptr;
	}
}

template <typename T>
void priQ<T>::peek(T& abc) {
	//Node <T>* A;
	if (frontPtr != nullptr) {
		abc = frontPtr->getItem();
		//A = frontPtr;
	
		//return A->getItem();
		//delete A;
		//A = nullptr;
	}
}


template <typename T>
void priQ<T>::show() {
	NodeP <T>* A;
	A = frontPtr;
	if (frontPtr == nullptr) { cout << "Queue is empty\n"; }
	else
	{
		cout << "Queue is :\n";
		cout << "Priority Item\n";
		while (A != NULL)
		{
			cout << A->getpriority() << " " << A->getItem() << endl;
			A = A->getNext();
		}
	}

}