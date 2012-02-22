//
//  Supermarket.cpp
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "Supermarket.h"

Supermarket::Supermarket(int typeOfStore, string incomingCustomersFileName){
    incomingCustomers = Queue();
    outgoingCustomers = Queue();
    register1 = Queue();
    
    
    incomingCustomers.queueFromFile(incomingCustomersFileName);
    
    
    if (typeOfStore == 1){
        time= 0;
        
        //BATURAY HELP GOES HERE
        while (incomingCustomers.getPeopleInQueue()>0||register1.getPeopleInQueue()>0){
                while(incomingCustomers.getPeopleInQueue()>0 && time > (incomingCustomers.getFront()->getArrivalTime())){
                    register1.add(incomingCustomers.getFront());
                    incomingCustomers.remove();
                }
            
            
            if (register1.getPeopleInQueue()>0){
                if (register1.getFront()->getStartCheckoutTime()==0)  {
                    register1.getFront()->setStartCheckoutTime(time);
                }
                
            
            while((time<(register1.getFront()->getStartCheckoutTime()+ register1.getFront()->getItems()))){
                outgoingCustomers.add(register1.getFront());
                register1.remove();
                }
            }
            time++;

            }
            
        }
        outgoingCustomers.printQueue();

    }
    ;
