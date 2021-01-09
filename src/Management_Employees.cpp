//============================================================================
// Name        : Management_Employees.cpp
// Author      : Thanh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "iomanip"
#include <cctype>
#include <cstring>


#include "Node.hpp"
#include "Linked_List.hpp"

using namespace std;

//path import to read file
const string path_import = "..\\resources\\employees.csv";
const string path_export = "..\\resources\\employees_export.csv";
void ClearScreen()
{
  int n;
  for (n = 0; n < 10; n++)
    printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void display()
{
	/* Here is where we clear the screen */
	ClearScreen();
	cout<<"---------------------------------------";
	cout<<"MANAGEMENT EMPLOYEES TOOL";
	cout<<"---------------------------------------\n";

	cout<<"\t1. Imprort Databases from file csv\n";
	cout<<"\t2. Sort list employees\n";
	cout<<"\t3. Add a employee\n";
	cout<<"\t4. Delete employees\n";
	cout<<"\t5. Search employees\n";
	cout<<"\t6. Export employees to file\n";
	cout<<"\t7. Exit\n";
	cout<<"Select your action:\n";
}


void displayList(Linked_List& list)
{
	/* Here is where we clear the screen */
	ClearScreen();
	cout<<"---------------------------------------";
	cout<<"MANAGEMENT EMPLOYEES TOOL";
	cout<<"---------------------------------------\n";
	list.printList();

}
string enterName() {
	string name;
	/* Here is where we clear the screen */
	ClearScreen();
	cout<<"---------------------------------------";
	cout<<"MANAGEMENT EMPLOYEES TOOL";
	cout<<"---------------------------------------\n";
	cout<<"Enter name:";
	getline(cin, name);
	return name;
}
Node * addEmployee() {
	Employee employA;
	Node * nodeA = new Node();
	/* Here is where we clear the screen */
	ClearScreen();
	cout<<"---------------------------------------";
	cout<<"MANAGEMENT EMPLOYEES TOOL";
	cout<<"---------------------------------------\n";
	cout<<"Enter name:";
	getline(cin, employA.m_name);

	cout<<"Enter position:";
	getline(cin, employA.m_position);

	cout<<"Enter date of birth:";
	getline(cin, employA.m_dateOfBirth);

	cout<<"Enter level:";
	cin>>employA.m_level;

	nodeA->m_employee = employA;

	return nodeA;

}
int input()
{
	int digit = 0;
	 cin >> digit;
	 cin.ignore();
	 if(/*isdigit(digit) && */(digit>0 && digit <8))
	 {
		 return digit;
	 }
	 return 0;
}

void backMenu()
{
	cin.ignore();
	cout<<"Please Enter to back Main Menu.....";
	cin.get();
}
void importData(Linked_List& list)
{
	//Import data into Linked_List
	cout<<"Importing databases.......\n";
	list.import_Linked_List(path_import);
	cout<<"Imported success!!! Please enter to display List....";
	cin.get();
	displayList(list);
}
void run(Linked_List& list)
{
	int yourSelect;
	int flag = 0;
	bool hasImport = false;
	do {
		display();
		yourSelect = input();
		switch (yourSelect) {
			case 1:
				if(!hasImport)
				{
					importData(list);
				}
				else
				{
					cout << "You had import database!!!";
				}
				backMenu();
				hasImport = true;
				break;
			case 2:
				//Sort by level(he so luong)
				cout<<"Sorting by level.......\n";
				list.bubbleSort();
				cout<<"Sort success!!! Please Enter to display List....";
				cin.get();
				displayList(list);
				backMenu();
				break;
			case 3:
				//Add a employee and sort
				list.addAndSort(addEmployee());
				cout<<"Add an employee success.Please Enter to display List......\n";
				cin.get();
				displayList(list);
				backMenu();
				break;
			case 4:
				//Delete a employee by name
				list.deleteNodes(enterName());
				cout<<"Delete success!!! Please Enter to display List....";
				cin.get();
				displayList(list);
				backMenu();
				break;
			case 5:
				//Search employ by name
				list.printList(enterName());
				backMenu();
				break;
			case 6:
				//export data to file .csv
				cout<<"Exporting databases.......\n";
				list.export_Linked_List(path_export);
				cout<<"Export success!!! Please Enter to display List....";
				cin.get();
				backMenu();
				break;

			default:
				flag = 1;
				break;
		}
	} while (flag == 0);

}
int main() {


	//create Obj Linked_List
	Linked_List List_Employees;

	run(List_Employees);
	return 0;
}
