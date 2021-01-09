/*
 * Linked_List.hpp
 *
 *  Created on: Jun 11, 2019
 *      Author: ThanhLH
 */
#include "Node.hpp"
#include "Employee.hpp"

#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

class Linked_List {
public:
	Node * head = nullptr;
	int numOfNodes = 0;
	void add(Node * newNode);
	void printList();
	Node * getTail();
	void swap(Node * node1, Node * node2);
	void bubbleSort();
	void addAndSort(Node *newNode);
	int deleteNode(string name);
	void deleteNodes(string name);
	void printList(string name);
	int countNode(void);
	void import_Linked_List(string path);
	void export_Linked_List(string path);

};



#endif /* LINKED_LIST_HPP_ */
