/*
Names: Nicholas Katsaros and Jax Hendrickson
Date: 10/13/2023
Purpose: To simulate a line in a bank using two methods of data storage: array and priority queue, and to collect statistics based on the data recorded. 
*/

#include "customer.h"
#include "priorityqueue.cpp"
#include "arrayqueue.cpp"
#include <iostream>

#define INPUT "input.txt"

void arrivalEvent(ArrayQueue<Customer>&, PriorityQueue<Customer>&, int, int&, int&);
void departureEvent(PriorityQueue<Customer>&, int, int&, int&, int&);
void increment(ArrayQueue<Customer>&, PriorityQueue<Customer>&, int&, int&, int&);
int main(){
    //File IO
    ifstream inputData(INPUT);
    if (!inputData.is_open()){
        cout << "File could not be opened" << endl;
        return 0;
    }
    int temp, count = 0;
    Customer tempCus;
    ArrayQueue<Customer> lineData;
    while (inputData >> temp){
        tempCus.setArrivalTime(temp);
        inputData >> temp;
        tempCus.setTransactionTime(temp);
        lineData.enqueue(tempCus);
        count++;
    }
    //lineData shold now contain all arrival and transaction times, stored in customer objects
    //lineData holds people who will be in the bank; it's like people waiting outside

    int currentTime = 0; //This tracks the amount of simulated time that has passed
    int waitTime = 0; //This tracks the total amount of time customers have spent waiting
    int remainingTransactionTime, transactionStartTime; 
    //waitTime += currentTime - line.peek().getArrivalTime(); should increment waitTime
    //Use that command whenever a customer leaves, after line.dequeue();

    PriorityQueue<Customer> line;

    cout << "Simulation Begins" << endl;
    //Simulation loop
    while (!lineData.isEmpty() || !line.isEmpty()){
        //Incrementation
        increment(lineData, line, currentTime, transactionStartTime, remainingTransactionTime);

        //Event processing
        if (!lineData.isEmpty()){
            if ((currentTime == lineData.peekFront().getArrivalTime())){ //Arrival event/test can only be used after !lineData.isEmpty()
                arrivalEvent(lineData, line, currentTime, transactionStartTime, remainingTransactionTime);
            } else if (!line.isEmpty()){
                departureEvent(line, currentTime, transactionStartTime, remainingTransactionTime, waitTime);
            }
        } else if (!line.isEmpty()){
            if (remainingTransactionTime == 0) { //Departure event/test can only be used after !line.isEmpty()
                departureEvent(line, currentTime, transactionStartTime, remainingTransactionTime, waitTime);
            }
        }
    }

    //Final calculation
    cout << endl << "Final statistics: " << endl;
    cout << "   Total number of people processed: " << count << endl;
    cout << "   Average amount of time spent waiting: " << ((float)waitTime)/count << endl;

    return 0;
}


void arrivalEvent(ArrayQueue<Customer>& lineData, PriorityQueue<Customer>& line, int current, int& start, int& remaining ){
    if(line.isEmpty()){
        line.enqueue(lineData.peekFront());
        start = current;
        remaining = line.peekFront().getTransactionTime();
    } else {
        line.enqueue(lineData.peekFront());
        remaining = line.peekFront().getTransactionTime() - (current - start);
    }
    lineData.dequeue();
    cout << "Processing an arrival event at time: " << current << endl;
}

void departureEvent(PriorityQueue<Customer>& line, int current, int& start, int& remaining, int& wait){
    line.dequeue();
        if (!line.isEmpty()){
            wait += current - line.peekFront().getArrivalTime();
            start = current;
            remaining = line.peekFront().getTransactionTime();
        }
        cout << "Processing a departure event at time: " << current << endl;
}

void increment(ArrayQueue<Customer>& lineData, PriorityQueue<Customer>& line, int& current, int& start, int& remaining){
    if (!lineData.isEmpty()){
        if (line.isEmpty()){ //Increment to the next arrival event
            current = lineData.peekFront().getArrivalTime();
            start = current;
            remaining = lineData.peekFront().getTransactionTime();
        } else if ((remaining + current) >= lineData.peekFront().getArrivalTime()){ //Increment current time to next arrival event
            current = lineData.peekFront().getArrivalTime();
            remaining = line.peekFront().getTransactionTime() - (current - start);
        } else { //Increment to the next departure event
            current += remaining;
            start = current;
            remaining = 0;
        }
    } else if (!line.isEmpty()){ //Increment to the next departure event
        current += remaining;
        start = current;
        remaining = 0;
    }
}