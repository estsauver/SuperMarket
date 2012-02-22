//
//  Customer.h
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//
#include <iostream>
#ifndef SuperMarketSimulator_customer_h
#define SuperMarketSimulator_customer_h
using namespace std;


class customer { 
    string name;
    int arrivalTime;
    int items;
    int startCheckoutTime;
    customer * next;
public:
    customer(string newName, int newArrivalTime, int newItems);
    string getName();
    customer * getNext();
    void setNext(customer * newNext);
    int getArrivalTime();
    int getItems();
    void setStartCheckoutTime(int newStartTime);
    int getStartCheckoutTime();
       
};

#endif
