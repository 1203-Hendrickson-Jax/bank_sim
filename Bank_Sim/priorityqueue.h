//Author: Jax Hendrickson
//Date: 10/13/2023
//Purpose: Header file for the priorityqueue class, one of our data structures. 
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "queue.h"
#include "customer.h"
using namespace std;
template <class ItemType>
class PriorityQueue : public QueueInterface<ItemType>{
private:
    ItemType* data;
    int capacity, count;
public: 
    bool isEmpty() const override; 
    bool enqueue(const ItemType& newEntry) override; 
    bool dequeue() override; 
    ItemType peekFront() const override; 
    PriorityQueue(int capacity);
    ~PriorityQueue();
    PriorityQueue();
    bool operator<(const Customer& first) const;
};
#endif