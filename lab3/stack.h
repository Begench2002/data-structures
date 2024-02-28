//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Stack class of the program that is derived from the SinglyLinkedList class
#ifndef STACK_H
#define STACK_H
#include "currency.h"
#include "krone.h"
#include "LinkNode.h"
#include "SinglyLinkedList.h"

class Stack : private SinglyLinkedList {
public:
	void push(Currency* currency)
	{
		addCurrency(currency, 0);
	}
	Currency* pop()
	{
		if (isListEmpty())
		{
			std::cout << "Stack is empty." << std::endl;
			return nullptr;

		}
		Currency* topCurrency = getCurrency(0);
		removeCurrency(0);
		return topCurrency;
	}
	Currency* peek()
	{
		if (isListEmpty())
		{
			std::cout << "Stack is empty." << std::endl;
			return nullptr;

		}
		return getCurrency(0);
	}
	void printStack()
	{
		SinglyLinkedList::printList();
	}
private:
	using SinglyLinkedList::addCurrency;
	using SinglyLinkedList::removeCurrency;
	using SinglyLinkedList::printList;
	using SinglyLinkedList::getCurrency;
	using SinglyLinkedList::countCurrency;
	using SinglyLinkedList::findCurrency;

};
#endif

