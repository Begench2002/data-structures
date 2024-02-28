//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Soum class of the program, that is derived from the Currency class
#ifndef SOUM_H
#define SOUM_H
#include <iostream>
#include <string>
#include "currency.h"

class Soum : public Currency {
private:
	std::string name = "Soum";
public:
	Soum() :Currency() {

	}
	Soum(double num) :Currency(num) {

	}
	Soum(const Soum& origObject) :Currency(origObject) {

	}
	/*
	* pre:
	* post:
	*/
	void print() {
	Currency:: print();
	std::cout << " " << name;
	}
};

#endif