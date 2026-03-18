//Author: Jax Hendrickson
//Date: 10/13/2023
//Purpose: Source file for the priorityqueue class, one of our data structures. 
#include "priorityqueue.h"
template <class ItemType> 
PriorityQueue<ItemType>::PriorityQueue() : capacity(10), data(new ItemType[10]), count(0){ 
}
template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const{
    return count == 0;
}
template <class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry){
    if (count >= capacity){
        return false;
    }
    int insertIndex = count;
    while (insertIndex > 0 && newEntry.getArrivalTime() < data[insertIndex-1].getArrivalTime()){ //small issue here? may have to add an && to make sure the priority of the current customer is larger than the next customer. 
        data[insertIndex] = data [insertIndex-1];
        insertIndex--;
    }
    data[insertIndex] = newEntry;
    count++;
    return true;
}
template <class ItemType>
bool PriorityQueue<ItemType>::dequeue(){
    if (isEmpty()){
        return false;
    }
    for (int i = 0; i < count-1; i++){
        data [i] = data [i+1];
    }
    count--;
    return true;
}
template <class ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const{
    if (isEmpty()){
        throw invalid_argument("Queue is empty.");
    }
    return data [0];
}
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int capacity){
    this->capacity = capacity;
    data = new ItemType[capacity];
    count = 0;
}
template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue(){
    delete[] data;
}
template <class ItemType>
bool PriorityQueue<ItemType>::operator<(const Customer& other) const{ //I'm going to keep this overload operator here, but I won't be implementing it. I know it should be in the enqueue function, but I can't get it to work as intended, and I don't want to mess with the code too much this close to the deadline. 
    return this->arrivalTime < other.arrivalTime;
}