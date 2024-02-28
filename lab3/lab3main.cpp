//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the main class of the program
#include <iostream>
#include "currency.h"
#include "krone.h"
#include "LinkNode.h"
#include "queue.h"
#include "SinglyLinkedList.h"
#include "stack.h"

using namespace std;

int main()
{
    cout << "Welcome to the Lab3, demonstration of linked list data structures singly linked list, stack and queue. Made by Begench Gurbanov and Arman Dagbashyan.\n\n";
    Krone array[20] = { 57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21, 345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00};
    SinglyLinkedList listSLL;
    cout << "Demonstration of Singly Linked List" << endl;
    int j = 0;
    for(int i = 6; i >= 0; i--) {
        listSLL.addCurrency((&array[i]), j);
        j++;
    }
    Krone test1 = 44.56;
    Krone test2 = 87.43;
    cout << listSLL.findCurrency(&test2) << endl;
    cout << listSLL.findCurrency(&test1) << endl;
    Krone test3 = 111.22;
    listSLL.removeCurrency(&test3);
    listSLL.removeCurrency(2);
    listSLL.printList();
    for (int i = 8; i < 12; i++) {
        listSLL.addCurrency((&array[i]), (i % 5));
    }
    listSLL.removeCurrency((listSLL.countCurrency() % 6));
    listSLL.removeCurrency((listSLL.countCurrency() / 7));
    listSLL.printList();
    
    Stack listS;
    cout << "Demonstration of Stack" << endl;
    for (int i = 13; i < 20; i++) {
        listS.push(&array[i]);
    }
    cout << "the top of the stack ";
    listS.peek()->print();
    cout << endl;
    for (int i = 0; i < 3; i++) {
        listS.pop();
    }
    listS.printStack();
    for (int i = 0; i < 5; i++) {
        listS.push(&array[i]);
    }
    
    listS.pop();
    listS.pop();
    listS.printStack();
    
    
    Queue listQ;
    cout << "Demonstration of Queue" << endl;
    for (int i = 5; i <= 17; i += 2) {
        listQ.enqueue(&array[i]);
    }
    listQ.printQueue();
    cout << "the front of the queue ";
    listQ.peekFront()->print();
    cout << endl;
    cout << "the rear of the queue ";
    listQ.peekRear()->print();
    cout << endl;
    listQ.dequeue();
    listQ.dequeue();
    for (int i = 10; i < 15; i++) {
        listQ.enqueue(&array[i]);
    }
    for (int i = 0; i < 3; i++) {
        listQ.dequeue();
    }
    listQ.printQueue();
    
}
