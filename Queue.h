//
//  Queue.h
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//
#include <iostream>
#include "customer.h"
#ifndef SuperMarketSimulator_Queue_h
#define SuperMarketSimulator_Queue_h
using namespace std;

class Queue{
    customer * front;
    customer * back;
    int numberInQueue;
public:
    Queue();
    void queueFromFile(string fileName);

    void remove(); //destructive, removes elemnt from queue
    customer * getFront(); //nondestructive
    void add(customer * newCustomer);
    int isEmpty();
    int getPeopleInQueue();
    
    //I/O methods
    void printQueue();
};

#endif
