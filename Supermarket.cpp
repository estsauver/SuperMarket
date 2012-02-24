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
        
        while (incomingCustomers.getPeopleInQueue()>0||register1.getPeopleInQueue()>0){
                while(incomingCustomers.getPeopleInQueue()>0 && time > (incomingCustomers.getFront()->getArrivalTime())){
                    customer * tempCustomer = incomingCustomers.remove();
                    register1.add(tempCustomer);
                    if (register1.getPeopleInQueue()>0){
                        if (register1.getFront()->getStartCheckoutTime()==0)  {
                            register1.getFront()->setStartCheckoutTime((time+1));
                        }
                    }
                }
            
                while(register1.getPeopleInQueue()>0&&(time>(register1.getFront()->getStartCheckoutTime()+ register1.getFront()->getItems()))){
                    if (register1.getPeopleInQueue()>0){
                        if (register1.getFront()->getStartCheckoutTime()==0)  {
                            register1.getFront()->setStartCheckoutTime(time);
                        }
                        else{
                            customer * tempCustomer = register1.remove();
                            outgoingCustomers.add(tempCustomer);
                        }
                    }
                }
            time++;

        }
            
    }
    else if(typeOfStore == 2){
        time = 0;
        while (incomingCustomers.getPeopleInQueue()>0||!allRegistersEmpty()){
            while(incomingCustomers.getPeopleInQueue()>0 && time > (incomingCustomers.getFront()->getArrivalTime())){
                customer * tempCustomer = incomingCustomers.remove();
                bool isExpress =true;
                Queue * tempRegister = shortestRegister(isExpress);
                tempRegister->add(tempCustomer);
                if (tempRegister->getPeopleInQueue()>0){
                    if (tempRegister->getFront()->getStartCheckoutTime()==0)  {
                        tempRegister->getFront()->setStartCheckoutTime(time);
                    }
                }
            }
        
        
            registerProcess(&register1);
            registerProcess(&register2);
            registerProcess(&register3);
            registerProcess(&register4);
            
            time++;
            
        }
    }
    else if(typeOfStore == 3){
        while (incomingCustomers.getPeopleInQueue()>0||!allRegistersEmpty()){
            while(incomingCustomers.getPeopleInQueue()>0 && time > (incomingCustomers.getFront()->getArrivalTime())){
                customer * tempCustomer = incomingCustomers.remove();
                bool isExpress = false;
                if (tempCustomer->getItems()<6) {
                    isExpress = true;
                }
                Queue * tempRegister = shortestRegister(isExpress);
                tempRegister->add(tempCustomer);
                if (tempRegister->getPeopleInQueue()>0){
                    if (tempRegister->getFront()->getStartCheckoutTime()==0)  {
                        tempRegister->getFront()->setStartCheckoutTime(time);
                    }
                }
            }
            registerProcess(&register1);
            registerProcess(&register2);
            registerProcess(&register3);
            registerProcess(&register4);
            
            
            
            time++;
            
        }
    }
    else if(typeOfStore == 4){
        while (incomingCustomers.getPeopleInQueue()>0||!allRegistersEmpty()){
            while(incomingCustomers.getPeopleInQueue()>0 && time > (incomingCustomers.getFront()->getArrivalTime())&&shortestRegister(true)->getPeopleInQueue()==0){
                
                customer * tempCustomer = incomingCustomers.remove();
                bool isExpress = true;
                Queue * tempRegister = shortestRegister(isExpress);
                tempRegister->add(tempCustomer);
                if (tempRegister->getPeopleInQueue()>0){
                    if (tempRegister->getFront()->getStartCheckoutTime()==0)  {
                        tempRegister->getFront()->setStartCheckoutTime(time);
                    }
                }
            }
            
            
            
            registerProcess(&register1);
            registerProcess(&register2);
            registerProcess(&register3);
            registerProcess(&register4);
            
            time++;
            
        }
    }
    
    outgoingCustomers.printQueue();

};

Queue * Supermarket::shortestRegister(bool isExpressEligible){
    if (register1.getPeopleInQueue()<= register2.getPeopleInQueue() && register1.getPeopleInQueue()<=register3.getPeopleInQueue() && register1.getPeopleInQueue()<=register4.getPeopleInQueue()){
        return &register1;
    }
    else if (register2.getPeopleInQueue()<=register3.getPeopleInQueue() && register2.getPeopleInQueue()<=register4.getPeopleInQueue()){
        return &register2;
    }
    else if (register3.getPeopleInQueue()<=register4.getPeopleInQueue()|| !isExpressEligible ){

        return &register3;
    }
    else {
        return &register4;
    }
}

bool Supermarket::allRegistersEmpty(){
    if (register1.isEmpty()&&register2.isEmpty()&&register3.isEmpty()&&register4.isEmpty()){
        return true;
    }
    else return false;
    
}

void Supermarket::registerProcess(Queue * registerX){
    while(registerX->getPeopleInQueue()>0&&(time>(registerX->getFront()->getStartCheckoutTime()+ registerX->getFront()->getItems()))){
        if (registerX->getPeopleInQueue()>0){
            if (registerX->getFront()->getStartCheckoutTime()==0)  {
                registerX->getFront()->setStartCheckoutTime(time);
            }
            else{
                customer * tempCustomer = registerX->remove();
                cout<<tempCustomer->getName()<<" "<<(tempCustomer->getStartCheckoutTime()-tempCustomer->getArrivalTime())<<endl;
                outgoingCustomers.add(tempCustomer);
            }
        }
    }
}