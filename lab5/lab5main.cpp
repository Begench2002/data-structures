//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the main cpp file of our projectm that runs the program and uses hash.h, currency.h and krone.h header files.
#include <iostream>
#include <string>
#include "currency.h"
#include "krone.h"
#include "hash.h"
using namespace std;
int main()
{
    Krone krone1(57.12);
    Krone krone2(23.44);
    Krone krone3(87.43);
    Krone krone4(68.99);
    Krone krone5(111.22);
    Krone krone6(44.55);
    Krone krone7(77.77);
    Krone krone8(18.36);
    Krone krone9(543.21);
    Krone krone10(20.21);
    Krone krone11(345.67);
    Krone krone12(36.18);
    Krone krone13(48.48);
    Krone krone14(101.00);
    Krone krone15(11.00);
    Krone krone16(21.00);
    Krone krone17(51.00);
    Krone krone18(1.00);
    Krone krone19(251.00);
    Krone krone20(151.00);

    HashTable hashTable(29);

    
    hashTable.insert(&krone1);
    hashTable.insert(&krone2);
    hashTable.insert(&krone3);
    hashTable.insert(&krone4);
    hashTable.insert(&krone5);
    hashTable.insert(&krone6);
    hashTable.insert(&krone7);
    hashTable.insert(&krone8);
    hashTable.insert(&krone9);
    hashTable.insert(&krone10);
    hashTable.insert(&krone11);
    hashTable.insert(&krone12);
    hashTable.insert(&krone13);
    hashTable.insert(&krone14);
    hashTable.insert(&krone15);
    hashTable.insert(&krone16);
    hashTable.insert(&krone17);
    hashTable.insert(&krone18);
    hashTable.insert(&krone19);
    hashTable.insert(&krone20);

    cout << "Number of data items loaded: " << 20 << endl;
    cout << "Load factor: " << hashTable.getLoadFactor() << endl;
    cout << "Number of collisions: " << hashTable.getNumCollisions() << endl;
    //hashTable.printTable();
    string choice;
    while (true)
    {
        double value;
        cout << "Enter a Krone value to search for (or -1 to exit): ";
        cin >> value;
        if (value == -1)
            break;

        Krone currency(value);
        int index = hashTable.search(&currency);
        if (index != -1)
        {
            cout << "Krone found at index " << index << endl;
        }
        else
        {
            cout << "Invalid Data" << endl;
        }

        cout << "Do you want to check again? (Y/N): ";
        cin >> choice;
        while (choice != "Y") {
            if (choice == "N") {
                break;
            }
            else cout << "please input Y or N" << endl;
            cin >> choice;
        }
        if (choice == "N") {
            break;
        }
    }
    cout << "Goodbye!!" << endl;
    return 0;
}
