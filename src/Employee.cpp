/*
 * Employee.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: ThanhLH
 */
#include <iostream>
#include "Employee.hpp"
using namespace std;

void Employee::printEmployee() {
	cout<<"Name: "<<m_name<<endl;
	cout<<"Position: "<<m_position<<endl;
	cout<<"Date of birth: "<<m_dateOfBirth<<endl;
	cout<<"Level: "<<m_level<<endl;
}
Employee::Employee(string name, string position, string dateOfBirth, float level) {
	m_name = name;
	m_position = position;
	m_dateOfBirth = dateOfBirth;
	m_level = level;
}

Employee::Employee() {

}
