/*
Created by: Nicholas Katsaros
Date: 10/13/2023
Purpose: Source file for Customer class
*/

#include "customer.h"

Customer::Customer(){
    arrivalTime = 0;
    transactionTime = 0;
}

Customer::Customer(int arrive, int transac){
    arrivalTime = arrive;
    transactionTime = transac;
}

Customer::Customer(Customer& rhs){
    arrivalTime = rhs.arrivalTime;
    transactionTime = rhs.transactionTime;
}

int Customer::getArrivalTime() const{
    return arrivalTime;
}

void Customer::setArrivalTime(int arrive){
    arrivalTime = arrive;
}

int Customer::getTransactionTime(){
    return transactionTime;
}

void Customer::setTransactionTime(int transac){
    transactionTime = transac;
}