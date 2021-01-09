/*
 * Employee.hpp
 *
 *  Created on: Jun 11, 2019
 *      Author: ThanhLH
 */
#include <string>
#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_
using namespace std;
class Employee {
public:
	string m_name;
	string m_position;
	string m_dateOfBirth;
	float m_level = 0;
	void printEmployee();
	Employee(string name, string position, string dateOfBirth, float level);
	Employee();
};



#endif /* EMPLOYEE_HPP_ */
