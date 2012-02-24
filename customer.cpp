//
//  customer.cpp
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "customer.h"


customer::customer(string newName, int newArrivalTime, int newItems)
{
    name = newName;
    arrivalTime = newArrivalTime;
    items = newItems;
    next = NULL;
    startCheckoutTime = 0;
    
}
#pragma mark Getter/Setter Methods
string customer::getName(){
    return name;
}
customer * customer::getNext() {
    return next;
}

void customer::setNext(customer * newNext){
    next = newNext;
}


int customer::getArrivalTime(){
    return arrivalTime;
}


int customer::getItems(){
    return items;
}
 

int customer::getStartCheckoutTime(){
    return startCheckoutTime;
}

void customer::setStartCheckoutTime(int newStartTime){
    startCheckoutTime = newStartTime;
}

