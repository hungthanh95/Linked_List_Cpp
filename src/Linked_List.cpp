/*
 * Linked_List.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: ThanhLH
 */
#include <iostream>
#include <fstream>
#include "Linked_List.hpp"
#include "iomanip"
using namespace std;

void Linked_List::add(Node * newNode) {

	/*If head = null newNode is head */
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
	return;
}

void Linked_List::printList() {
	Node * temp = head;
	for(int i = 0 ; temp != nullptr; i++) {
		cout<<"---------------Node "<<i<<"-----------------"<<endl;
		temp->m_employee.printEmployee();
		temp = temp->next;
	}
}

Node *Linked_List::getTail(){
	Node * temp = head;
	while(temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

void Linked_List::swap(Node * node1, Node * node2) {
	Employee temp = node1->m_employee;
	node1->m_employee = node2->m_employee;
	node2->m_employee = temp;
}

void Linked_List::bubbleSort() {
	int swapped;
	Node * node1;
	Node * node2 = nullptr;

	/* Check for empty list */
	if(head == nullptr)
		return;

	do
	{
		swapped = 0;
		node1 = head;
		while(node1->next != node2)
		{
			if(node1->m_employee.m_level > node1->next->m_employee.m_level)
			{
				swap(node1, node1->next);
				swapped = 1;
			}
			node1 = node1->next;
		}
		node2 = node1;
	} while (swapped);

}

void Linked_List::addAndSort(Node * newNode) {
	add(newNode);
	bubbleSort();
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
int Linked_List::deleteNode(string name)
{
    // Store head node
    struct Node* temp = head, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->m_employee.m_name == name)
    {
        head = temp->next;   // Changed head
        free(temp);               // free old head
        return 1;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->m_employee.m_name != name)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return 0;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
    return 1;
}

void Linked_List::deleteNodes(string name) {
	int flag =1;
	while(flag) {
		flag = deleteNode(name);
	}
}

void Linked_List::printList(string name) {
	Node * temp = head;
	for(int i = 0 ; temp != nullptr; i++) {
		if (temp->m_employee.m_name == name)
		{
			cout<<"---------------Node "<<i<<"-----------------"<<endl;
			temp->m_employee.printEmployee();
		}

		temp = temp->next;
	}
}

int Linked_List::countNode(void) {
	Node * temp = head;
	int count = 0;
	while(temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

void Linked_List::import_Linked_List(string path)
{

    // Open file
//    ifstream ip("C:\\Users\\ThanhLH\\Desktop\\employees.csv");
	  ifstream ip(path);

    if(!ip.is_open()) cout <<"ERROR: File open"<<'\n';


    int idx = 0;
    string  level_str;

    while(ip.good()) {
    	Node *newNode = new Node();
    	// Read the Data from the file
    	getline(ip, newNode->m_employee.m_name, ',');
    	getline(ip, newNode->m_employee.m_position, ',');
    	getline(ip, newNode->m_employee.m_dateOfBirth, ',');
    	getline(ip, level_str, '\n');

    	/* convert value from string to float */
    	newNode->m_employee.m_level = std::stof(level_str.c_str());

    	/* assign Node to Linked List*/
    	add(newNode);
    	idx++;
    }


    numOfNodes = idx;
}


void Linked_List::export_Linked_List(string path) {
	//file pointer
	fstream fs;

	//open file
	//fs.open("C:\\Users\\ThanhLH\\Desktop\\employees_export.csv",ios::out);
	fs.open(path,ios::out);

	cout << "Export data to file csv....." << endl;

	     // Write the data
	Node * temp = head;
	fs <<left<<setw(25)<<"Ten"<<setw(25)<<"Chuc vu"<<setw(25)<<"Ngay thang nam sinh"<<setw(25)<<"He so luong"<<endl;
	for(int i = 0 ; temp != nullptr; i++) {

	     // Insert the data to file
	     fs <<left<<setw(25)<< temp->m_employee.m_name
	    		  <<setw(25)<< temp->m_employee.m_position
				  <<setw(25)<< temp->m_employee.m_dateOfBirth
				  <<setw(25)<< temp->m_employee.m_level    		<< "\n";

		temp = temp->next;
	}

	fs.close();
}

