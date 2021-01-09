/*
 * Node.hpp
 *
 *  Created on: Jun 11, 2019
 *      Author: ThanhLH
 */

#ifndef NODE_HPP_
#define NODE_HPP_
#include "Employee.hpp"

class Node {
public:
	Employee m_employee;
	Node * next = nullptr;

	Node();
	Node(Employee a);
};



#endif /* NODE_HPP_ */
