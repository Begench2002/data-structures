//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Krone class of the program, that is derived from the Currency class
#ifndef KRONE_H
#define KRONE_H
#include <iostream>
#include <string>
#include "currency.h"

class Krone : public Currency {
private:
	std::string name = "Krone";
public:
	Krone() :Currency() {

	}
	Krone(double num) :Currency(num) {
		
	}
	Krone(const Krone& origObject) :Currency(origObject) {

	}
	/*
	* pre: 
	* post:
	*/
	void print(){//I changed this print function to make the Currency base class abstract
		double temp = (100 * getWholePart() + getFractionalPart());
		std::cout << std::fixed << std::setprecision(2) << (temp / 100);
	std::cout << " " << name;
	}
};


#endif