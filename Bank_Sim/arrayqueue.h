//Author: Jax Hendrickson
//Purpose: Header file for the arrayqueue class, one of our data structures. 

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "queue.h"
using namespace std;
template <class ItemType>
class ArrayQueue : public QueueInterface<ItemType>{
private:
    ItemType* data;
    int capacity, frontIndex, rearIndex, count;
public: 
    bool isEmpty() const override; 
    bool enqueue(const ItemType& newEntry) override; 
    bool dequeue() override; 
    ItemType peekFront() const override; 
    ArrayQueue(int capacity);
    ~ArrayQueue();
    ArrayQueue();
    //For this class there isn't an overload operator, since it's on a first come first serve basis.
};
#endif
