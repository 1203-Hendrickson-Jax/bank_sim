/*
Created by: Nicholas Katsaros
Date: 10/13/2023
Purpose: Header file for Customer class
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <fstream>

using namespace std;

class Customer{
    int arrivalTime;
    int transactionTime;

    public:
        Customer();
        Customer(int, int);
        Customer(Customer&);
        int getArrivalTime() const;
        void setArrivalTime(int);
        int getTransactionTime();
        void setTransactionTime(int);
};

#endif