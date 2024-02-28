//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Queue class of the program that is derived from the SinglyLinkedList class
#ifndef QUEUE_H
#define QUEUE_H
#include "currency.h"
#include "krone.h"
#include "LinkNode.h"
#include "SinglyLinkedList.h"

class Queue : private SinglyLinkedList {
public:

    void enqueue(Currency* currency) {
        addCurrency(currency, countCurrency());
    }
    
    Currency* dequeue() {
        return removeCurrency(0);
    }
    
    Currency* peekFront() {
        return getCurrency(0);
    }

    Currency* peekRear() {
        return getCurrency(countCurrency() - 1);
    }
    
    void printQueue() {
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