//CIS 2023 Spring 
//Arman Daghbashyan and Begench Gurbanov
//This is the Hash class of the program
#ifndef HASH_S
#define HASH_H
#include "currency.h"
#include <vector>
class HashTable
{
private:
    int size;
    std::vector<Currency*> table;
    int collisions;

public:
    HashTable(int size)
        : size(size), collisions(0)
    {
        table.resize(size, nullptr);
    }

    int hashFunction(Currency* currency) const
    {
        int m = 2;
        int n = 3;
        int w = currency->getWholePart();
        int f = currency->getFractionalPart();
        int hashIndex = (((m * w) + (n * f)) % size);
        return hashIndex;
    }

    void insert(Currency* currency)
    {
        int index = hashFunction(currency);
        if (table[index] == nullptr)
        {
            table[index] = currency;
        }
        else
        {
            collisions++;
            int i = 1;
            while (true)
            {
                int newIndex = (index + i + i * i) % size;
                if (table[newIndex] == nullptr)
                {
                    table[newIndex] = currency;
                    return;
                }
                else
                {
                    i++;
                }
            }
        }
    }

    int search(Currency* currency) const
    {
        int index = hashFunction(currency);
        if (table[index] != nullptr && (table[index]->getWholePart() == currency->getWholePart()) && (table[index]->getFractionalPart() == currency->getFractionalPart()))
        {
            return index;
        }
        else
        {
            int i = 1;
            while (true)
            {
                int newIndex = (index + i + (i * i)) % size;
                if (table[newIndex] == nullptr)
                {
                    return -1;
                }
                else if ((table[newIndex]->getWholePart() == currency->getWholePart()) && (table[newIndex]->getFractionalPart() == currency->getFractionalPart()))
                {
                    return newIndex;
                }
                else
                {
                    i++;
                    newIndex = (index + i + (i * i)) % size;
                }
            }
        }
    }

    int getNumCollisions() const
    {
        return collisions;
    }

    double getLoadFactor() const
    {
        int numItems = 0;
        for (const Currency* currency : table)
        {
            if (currency != nullptr)
            {
                numItems++;
            }
        }
        return static_cast<double>(numItems) / size;
    }

    void printTable() {
        for (int i = 0; i < size; i++) {
            std::cout << i << ": ";
            if (table[i] != nullptr) {
                table[i]->print();
            }
            std::cout << std::endl;
        }
    }
};

#endif