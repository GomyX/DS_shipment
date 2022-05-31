#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
#include "Cargo.h"
//#include"Cargo.h"
using namespace std;

template <typename T>
class LinkedList
{
protected:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	Node<T>* Tail;
public:

	LinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		if (Head) {
			R->setNext(Head);
			Head = R;
		}
		else {
			Head = R;
			Tail = R;

		}
	}

	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}


	template<typename T>
	bool search(T val) {
		Node<T>* current = this->Head;
		while (current) {
			if (current->getItem() == val) {
				return true;
			}
			current = current->getNext();
		}
		return false;
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list

	void InsertEnd(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(nullptr);
		if (Head == nullptr)
		{
			Head = R;
			return;
		}
		Node<T>* P = Head;
		while (P->getNext())
		{
			P = P->getNext();
		}
		P->setNext(R);
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list

	//[4] DeleteFirst
	//Deletes the first node in the list

	//[5] DeleteLast
	//Deletes the last node in the list

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	template<typename T>
	bool DeleteNode(T item) {
		Node<T>* current = this->Head;
		Node<T>* prev = this->Head;
		while (current) {
			if (current->getItem() == item) {
				Node<T>* next = current->getNext();
				if (current == this->Head) {
					delete this->Head;
					this->Head = nullptr;
					this->Head = next;
				}
				else {
					delete current;
					current = nullptr;
					prev->setNext(next);
				}
				return true;
			}
			else {
				prev = current;
			}
			current = current->getNext();
		}
		return false;
	}


	template<typename T>
	Node<T>* getHead() const {
		return this->Head;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	
	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	


	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
};

#endif	
