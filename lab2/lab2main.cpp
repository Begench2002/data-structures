//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This program does currency operations with two distinct currencies - Krone and Soum, keeps the amount of money of the each currency and prints it out.
//this is the main function of the project, it gets the input from the console and uses that information to do proper actions, showing the use of inheritance and polymorphism

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "currency.h"
#include "krone.h"
#include "soum.h"
using namespace std;
int main()
{
    Krone wallKr;
    Soum wallSo;


    string line;
    getline(cin, line);
    while (line!="q") {
        stringstream sstr(line);
        while (sstr.good()) {
            string first;
            getline(sstr, first, ' ');
            string second;
            getline(sstr, second, ' ');
            string num;
            getline(sstr, num, ' ');
            string name;
            getline(sstr, name);

            double myNum = stod(num);
            if (first == "a") {
                if ((second == "s") && (name == "Soum")) {
                    wallSo.add(myNum);
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
                else if ((second == "k") && (name == "Krone")) {
                    wallKr.add(myNum);
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
                else {
                    cout << "Invalid addition" << endl;
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
            }
            else if (first == "s") {
                if ((second == "s") && (name == "Soum")) {
                    wallSo.subtract(myNum);
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
                else if ((second == "k") && (name == "Krone")) {
                    wallKr.subtract(myNum);
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
                else {
                    cout << "Invalid sutraction" << endl;
                    wallSo.print();
                    cout << " ";
                    wallKr.print();
                    cout << endl;
                }
            }
            else {
                cout << "invalid operation" << endl;
                wallSo.print();
                cout << " ";
                wallKr.print();
                cout << endl;
            }
        }
        getline(cin, line);
    }

    
}
