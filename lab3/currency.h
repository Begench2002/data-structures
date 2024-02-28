//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Currency class of the program
#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <iomanip>
class Currency
{
private:

    int wholePart;
    int fractionalPart;

public:
    Currency() {
        wholePart = 0;
        fractionalPart = 0;
    } 
    Currency(double num) {
        try {
            int temp = 100 * num;
            setWholePart(temp / 100);
            setFractionalPart(temp % 100);
            if (num >= 0) {
                //std::cout << "Constructor with one double is working properly" << std::endl;
            }
            else throw (num);
        }
        catch (double myNum) {
            std::cout << "money cannot be a negative number(constructor with one double)" << std::endl;
        }
    }
    ~Currency() {}; //Destructor
    Currency(const Currency& origObject) {
        wholePart = origObject.wholePart;
        fractionalPart = origObject.fractionalPart;
    }
    /*
    pre:getters
    post:
    return: wholePart, fractionalPart
    */
    int getWholePart() {
        return wholePart;
    }
    int getFractionalPart() {
        return fractionalPart;
    }
    /*
    pre:whPart - integer number
        frPart - integer number
    post:wholePart
         fractionalPart
    */
    void setWholePart(int whPart) {
        wholePart = whPart;
    }
    void setFractionalPart(int frPart) {
        fractionalPart = frPart;
    }

    // methods
    virtual void add(double);
    virtual void subtract(double);
    virtual bool isEqual(double);
    virtual bool isGreater(double);
    virtual void print() = 0; //I changed this print class to make my Currency class abstract.
};
/*
    pre: num - double number
    post: wholePart and fractionalPart
*/
void Currency::add(double num) {
    int test = num * 100;
    int testWholePart = num;
    int testFractionalPart = test % 100;
    wholePart += testWholePart;
    fractionalPart += testFractionalPart;
}
/*
    pre: num - double number
    post: wholePart and fractionalPart
*/
void Currency::subtract(double num) {
    try {
        if (!isGreater(num)) {
            //std::cout << "Operation is doable(subtract)" << std::endl;
            int test = num * 100;
            int temp = 100 * wholePart + fractionalPart;
            int sub = temp - test;
            wholePart = sub / 100;
            fractionalPart = sub % 100;
        }
        else throw(num);
    }
    catch (double num) {
        std::cout << "Invalid subtraction" << std::endl;
    }
}
/*
* pre: num - double number
* post:
*/
bool Currency::isEqual(double num) {
    int test = num * 100;
    if (((test / 100) == wholePart) && ((test % 100) == fractionalPart)) {
        return true;
    }
    else return false;
}

/*
* pre: num - double number
* post:
*/
bool Currency::isGreater(double num) {
    int test = num * 100;
    if (((test / 100) > wholePart) || ((test / 100) == wholePart) && ((test % 100) > fractionalPart)){
        return true;
    }
    else return false;
}
#endif

