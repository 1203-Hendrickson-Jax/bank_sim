//Author: Jax Hendrickson
//Purpose: The Queue interface, which the arrayqueue and priorityqueue classes will both inherit from. 
#ifndef QUEUE_INTERFACE 
#define QUEUE_INTERFACE 

template<class ItemType> 
class QueueInterface { 
public: 
    virtual bool isEmpty() const = 0; 
    virtual bool enqueue(const ItemType& newEntry) = 0; 
    virtual bool dequeue() = 0; 
    virtual ItemType peekFront() const = 0; 
    
    virtual ~QueueInterface() { };
};  
#endif
