//
//  Supermarket.h
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//
#include "Queue.h"
#ifndef SuperMarketSimulator_Supermarket_h
#define SuperMarketSimulator_Supermarket_h

class Supermarket {
    Queue incomingCustomers;
    Queue register1;
    Queue register2;
    Queue register3;
    Queue register4;
    int typeOfStore;
    int time;
    Queue outgoingCustomers;
public:
    Supermarket(int typeOfStore, string incomingCustomersFileName);
    int getTypeOfStore();
    Queue * getOutgoingCustomers();
};

#endif
