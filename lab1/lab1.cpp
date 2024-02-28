/*
CIS 22C Spring 2023
Begench Gurbanov
Lab 01
This program has 4 functions - main, IsArrayPrimeIter, IsPrimeRecur and IsArrayPrimeRecur.
program can identify whether all the numbers in the array are prime or not with two different methds - recursive method and iterative method
*/
#include <cmath>
#include <iostream>
using namespace std;
/*
Pseudocode of the function IsArrayPrimeIter

Pre:
non - empty array of integers numArr with number of elements size.
size - integer number that indicates the number of elements in numArr
post:
return: true or false

algorithm sets a bool variable to true
iterates through the array
checks all the numbers if they are prime or not
if there is a prime number it sets the bool variable to false
returns the bool variable
*/
bool IsArrayPrimeIter(int numArr[], int size) {
    cout << "Entering IsArrayPrimeIter" << endl;
    bool flag = true;
    for (int i = 0; i < size; i++) {
        if (numArr[i] == 0 || numArr[i] == 1) {
            flag = false;
        }
        else {
            for (int j = 2; j < sqrt(numArr[i]) + 1; j++) {
                if (numArr[i] % j == 0) {
                    flag = false;
                }
            }
        }
    }
    cout << "Leaving IsArrayPrimeIter" << endl;
    return flag;

}
/*
Pseudocode of the function IsPrimeRecur

Pre:
num - an integer number which the function will check if it is a prime or not
post:
return: true or false

algorithm checks the base cases - 0, 1, 2
algorithm dividies our number to integer i, which is set 2 at the start of the recursive program
algorithm checks whether the number i is more than square root of our number
after that it call the our recursive function again with changed integer i to i+1
returns true or false
*/
bool IsPrimeRecur(int num, int i = 2) {
    cout << "Entering IsPrimeRecur" << endl;
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % i == 0) {
        return false;
    }
    if (i > sqrt(num)) {
        return true;
    }
    cout << "Leaving IsPrimeRecur" << endl;
    return IsPrimeRecur(num, i + 1);

}
/*
Pseudocode of the function IsArrayPrimeRecur

Pre:
non - empty array of integers numArr with number of elements size.
size - integer number that indicates the number of elements in numArr
post:
return: true or false

algorithm sets a bool variable to true
iterates through the array
checks all the numbers if they are prime or not with help of the recursive function IsPrimeRecur
if there is a prime number it sets the bool variable to false
returns the bool variable
*/
bool IsArrayPrimeRecur(int numArr[], int size) {
    cout << "Entering IsArrayPrimeRecur" << endl;
    bool flag = true;
    for (int i = 0; i < size; i++) {
        if (!IsPrimeRecur(numArr[i])) {
            flag = false;
        }
    }
    cout << "Leaving IsArrayPrimeRecur" << endl;
    return flag;
}
const int SORT_MAX_SIZE = 8;
int main()
{
    int arraySize;
    //int arrayInput;
    int array[SORT_MAX_SIZE];
    cout << "Please enter your input data on one line only." << endl;
    cin >> arraySize;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }
    if (IsArrayPrimeIter(array, arraySize))
    {
        cout << "Array was found to be prime using iteration" << endl;
    }
    else
    {
        cout << "Not a Prime Array using iteration" << endl;
    }

    if (IsArrayPrimeRecur(array, arraySize))
    {
        cout << "Array was found to be prime using recursion" << endl;
    }
    else
    {
        cout << "Not a Prime Array using recursion" << endl;
    }
}

