//Author: Jax Hendrickson
//Date: 10/13/2023
//Purpose: source file for the arrayqueue class, one of our data structures. 
#include "arrayqueue.h"
template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : capacity(10), data(new ItemType[10]), frontIndex(0), rearIndex(-1), count(0){ 
}
template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue(int capacity) {
    this->capacity = capacity;
    data = new ItemType[capacity];
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}
template <class ItemType>
ArrayQueue<ItemType>::~ArrayQueue(){
    delete[] data;
}
template <class ItemType>
bool ArrayQueue <ItemType>::isEmpty() const{
    return count == 0;
}
template <class ItemType>
bool ArrayQueue <ItemType>::enqueue(const ItemType& newEntry){
    if (count >= capacity){
        return false;
    }
    rearIndex = (rearIndex+1) % capacity;
    data[rearIndex] = newEntry;
    count++;
    return true;
}
template <class ItemType>
bool ArrayQueue <ItemType>::dequeue() {
    if (isEmpty()){
        return false;
    }
    frontIndex = (frontIndex+1) % capacity;
    count--;
    return true;
}
template <class ItemType>
ItemType ArrayQueue <ItemType>::peekFront() const{
    if (isEmpty()){
        throw invalid_argument("Queue is empty.");
    }
    return data[frontIndex];
}
//For this class there isn't an overload operator, since it's on a first come first serve basis.