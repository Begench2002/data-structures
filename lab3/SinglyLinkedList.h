//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the SinglyLinkedList class of the program
	#ifndef SINGLYLINKEDLIST_H
	#define SINGLYLINKEDLIST_H
	#include "LinkNode.h"
	#include "currency.h"
	#include "krone.h"
	class SinglyLinkedList {
	private:
		int count;
		LinkNode* start;
		LinkNode* end;

	public:
		SinglyLinkedList() {
			start = nullptr;
			end = nullptr;
			count = 0;
		}
		~SinglyLinkedList() {
			LinkNode* currentObject = start;
			while (currentObject != nullptr) {
				LinkNode* nextNode = currentObject->next;
				delete currentObject;
				currentObject = nextNode;
			}
		}
		LinkNode* getStart() {
			return start;
		}
		LinkNode* getEnd() {
			return end;
		}
		
		/*
		* function addCurrency(a: Currency*, index: int)
		newNode := createNode(a)

		// If the list is empty or the index is greater than or equal to the count, appends the new node at the end
		if count == 0 or index >= count then
			if count == 0 then
				start := newNode
				end := newNode
			else
				end.next := newNode
				end := newNode
			end if
		else if index == 0 then
			// Inserts the new node at the beginning of the list
			newNode.next := start
			start := newNode
		else
			// Inserts the new node at the specified index
			prevNode := getNodeAtIndex(index - 1)
			newNode.next := prevNode.next
			prevNode.next := newNode
		end if

		// Increments the count of currencies in the list
		count := count + 1
		ends function
		*/

		/*
		* pre: a - pointer to Currency object
		*	   index - integer number
		* post:
		*	  prevNode and currentObject - pointers to LinkNode class objects
		*	  count - integer
		* return:
		*/
		void addCurrency(Currency* a,  int index) {
			LinkNode* newNode = new LinkNode;
			newNode->data = a;
			newNode->next = nullptr;
			if (index >= count) {
				if (count == 0) {
					start = newNode;
					end = newNode;
				}
				else {
					end->next = newNode;
					end = newNode;
				}
			}
			else if(index == 0){
				newNode->next = start;
				start = newNode;
			}
			else {
				LinkNode* prevNode = nullptr;
				LinkNode* currentObject = start;
				int i = 0;
				while (i != index) {
					prevNode = currentObject;
					currentObject = currentObject->next;
					i++;
				}
				prevNode->next = newNode;
				newNode->next = currentObject;
			}
			count++;
		}
	
	/*
		* function removeCurrency(a: Currency*) -> Currency*
		// Initializes currentObject as the start of the list and temp as nullptr
		currentObject := start
		temp := nullptr

		// Traverses the list until currentObject reaches the end or a match is found
		while currentObject is not null do
			// Checks if the current currency matches the one to be removed
			if currentObject.data is equal to a then
				// If temp is nullptr, update the start to skip the current node
				// Otherwise, update the next pointer of temp to skip the current node
				if temp is nullptr then
					start := currentObject.next
				else
					temp.next := currentObject.next
				end if

				// Stores the removed currency object
				removedObject := currentObject.data
				// Delete the current node
				delete currentObject
				// Decrease the count of currencies in the list
				count := count - 1

				// Return the removed currency object
				return removedObject
			end if

			// Move to the next node in the list
			temp := currentObject
			currentObject := currentObject.next
		end while

		// If the currency object was not found, return nullptr
		return nullptr
	end function
	*/
	/*
	* pre: a - pointer
	* post: count - integer
	* return: removedObject - pointer of Currency object
	*/
		Currency* removeCurrency(Currency* a) {
			LinkNode* currentObject = start;
			LinkNode* temp = nullptr;

			while (currentObject != nullptr) {
				int tempWholePart = (*a).getWholePart();
				int tempFracPart = (*a).getFractionalPart();
				int currWholePart = currentObject->data->getWholePart();
				int currFracPart = currentObject->data->getFractionalPart();

				if (tempFracPart == currFracPart && tempWholePart == currWholePart) {
					if (temp == nullptr) {
						start = currentObject->next;
					}
					else {
						temp->next = currentObject->next;
					}
					Currency* removedObject = currentObject->data;
					delete currentObject;
					count--;
					return removedObject;
				}

				temp = currentObject;
				currentObject = currentObject->next;
			}
			return nullptr;
		}
	/*
	* pre: index- integer number
	* post: currentObject and prevNode
	*/

	/*
		* function removeCurrency(index: int) -> Currency*
		// Check if the index is out of bounds
		if index < 0 OR index >= count then
			return nullptr
		end if

		// Initialize currentObject as the start of the list
		currentObject := start
		// Initialize prevNode as nullptr
		prevNode := nullptr
		// Initialize currentIndex as 0
		currentIndex := 0

		// Traverse the list until currentObject reaches the desired index or the end
		while currentObject is not nullptr AND currentIndex is not equal to index do
			prevNode := currentObject
			currentObject := currentObject.next
			currentIndex := currentIndex + 1
		end while

		// Check if the currentObject is not nullptr (i.e., the desired index is found)
		if currentObject is not nullptr then
			// Update the pointers to remove the current node
			if prevNode is nullptr then
				start := currentObject.next
			else
				prevNode.next := currentObject.next
			end if

			// Check if the currentObject is the end node
			if currentObject is equal to end then
				end := prevNode
			end if

			// Store the removed currency object
			removedObject := currentObject.data
			// Delete the current node
			delete currentObject
			// Decrease the count of currencies in the list
			count := count - 1

			// Return the removed currency object
			return removedObject
		end if

		// If the desired index is not found, return nullptr
		return nullptr
	end function

	*/
	Currency* removeCurrency(int index) {
		if (index < 0 || index >= count) {
			return nullptr;
		}

		LinkNode* currentObject = start;
		LinkNode* prevNode = nullptr;
		int currentIndex = 0;

		while (currentObject != nullptr && currentIndex != index) {
			prevNode = currentObject;
			currentObject = currentObject->next;
			currentIndex++;
		}

		if (currentObject != nullptr) {
			if (prevNode == nullptr) {
				start = currentObject->next;
			}
			else {
				prevNode->next = currentObject->next;
			}

			if (currentObject == end) {
				end = prevNode;
			}

			Currency* removedObject = currentObject->data;
			delete currentObject;
			count--;

			return removedObject;
		}

		return nullptr;
	}
	/*
		* function findCurrency(a: Currency*) -> int
		// Initialize currentObject as the start of the list
		currentObject := start
		// Initialize a temporary variable to store the index
		temp := 0
		// Retrieve the whole part and fractional part of the target currency
		tempWholePart := a.getWholePart()
		tempFracPart := a.getFractionalPart()

		// Traverse the list until currentObject reaches the end
		while currentObject is not null do
			// Retrieve the whole part and fractional part of the current currency
			currWholePart := currentObject.data.getWholePart()
			currFracPart := currentObject.data.getFractionalPart()

			// Check if the current currency matches the target currency
			if tempFracPart == currFracPart AND tempWholePart == currWholePart then
				// Return the index of the match
				return temp
			end if

			// Increment the index and move to the next node
			temp := temp + 1
			currentObject := currentObject.next
		end while

		// If no match is found, return -1
		return -1
	end function
	*/
	/*
	* pre: a - pointer of CUrrency object
	* post: 
	* return: temp - integer
	*/
	int findCurrency(Currency* a)
	{
		LinkNode* currentObject = start;
		int temp = 0;
		int tempWholePart = (*a).getWholePart();
		int tempFracPart = (*a).getFractionalPart();
		while (currentObject != nullptr)
		{
			int currWholePart = currentObject->data->getWholePart();
			int currFracPart = currentObject->data->getFractionalPart();
			if ((tempFracPart == currFracPart) && (tempWholePart == currWholePart)) {
				return temp;
				break;
			}
			else {
				temp++;
				currentObject = currentObject->next;
			}
			
		}
		return -1;
	}
	/*
	* pre: index - integer
	* post:
	* return: temp - pointer to Currency object
	*/
	Currency* getCurrency(int index)
	{
		LinkNode* currentObject = start;
		for (int temp = 0; temp < index; temp++) {
			currentObject = currentObject->next;
		}
		Currency* temp = currentObject->data;
		return temp;
	}
	void printList() {
		
		LinkNode* currentObject = start;
		for (int i = 0; i < count; i++) {
			Currency* temp = currentObject->data;
			(*temp).print();
			std::cout << "	";
			currentObject = currentObject->next;
		}
		std::cout << std::endl;
	}
	bool isListEmpty() {
		if (count == 0)
		{
			return true;
		}
		else return false;
	}
	/*
	* pre:
	* post:
	* return: temp - integer
	*/
	int countCurrency() {
		LinkNode* currentObject = start;
		int temp = 0;
		while(currentObject != nullptr){
			temp++;
			currentObject = currentObject->next;
		}
		return temp;
	}
};



#endif
