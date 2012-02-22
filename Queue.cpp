//
//  Queue.cpp
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#include "comp11io.h"
#include <vector>
#include <fstream>
#include <string>
Queue::Queue() {

    front = NULL;
    back = NULL;
    numberInQueue = 0;
}

void Queue::queueFromFile(string fileName){

    vector<customer> temporaryCustomerHolder;
    customer * backOfLine = NULL;
    string temporaryName;
    int temporaryArrivalTime;
    int temporaryItems;
    int numberOfItems=0;
    
    ifstream inFile;
    int successfulOpen = openFileForReading(fileName, inFile);
    cout<<successfulOpen;
    if (successfulOpen==1)
        while (!atEndOfFile(inFile)) {
            temporaryName = getToken(inFile);
            temporaryItems = getInt(inFile);
            temporaryArrivalTime = getInt(inFile);
            //cout << temporaryName << temporaryItems << temporaryArrivalTime <<" "<< numberOfItems<<endl;
            
            customer temporaryCustomer = customer(temporaryName, temporaryArrivalTime, temporaryItems);
            temporaryCustomer.setNext(backOfLine);
            temporaryCustomerHolder.push_back(temporaryCustomer);
            numberOfItems++;
        }
    else{cout<<"Failure to read";}
    
    
    for (int i = 0; i<numberOfItems; i++) {
        add(&temporaryCustomerHolder.at(i));
        
    };
}

int Queue::getPeopleInQueue(){
    return numberInQueue;
}

customer * Queue::getFront(){
    /*if (isEmpty()) {
    }*/
    return front;
}


void Queue::remove() {
    if (front==NULL){
        back = NULL;
    }
    front = front->getNext();
    numberInQueue--;
    
}

void Queue::add(customer * newCustomer){
    if(isEmpty()){
        front = newCustomer;
        back = newCustomer;
    }
    back->setNext(newCustomer);
    back = newCustomer;
    back->setNext(NULL);
    
    numberInQueue++;
        
    return;
}

int Queue::isEmpty(){
    if (front==NULL || back ==NULL )
    {return true;}
    else 
        return false;
    
}

void Queue::printQueue(){
    customer * currentNode = front;
    if (currentNode==NULL){
        cout<<"This Queue was empty!";
    }
    while (currentNode != NULL){
    cout<<currentNode->getName()<<(currentNode->getStartCheckoutTime() - currentNode->getArrivalTime());
    currentNode = currentNode->getNext();
    }
    

}
