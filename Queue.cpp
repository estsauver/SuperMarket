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

    string temporaryName;
    int temporaryArrivalTime;
    int temporaryItems;
    int numberOfItems=0;
    
    ifstream inFile;
    int successfulOpen = openFileForReading(fileName, inFile);
    //cout<<successfulOpen;
    if (successfulOpen==1)
        while (!atEndOfFile(inFile)) {
            temporaryName = getToken(inFile);
            temporaryItems = getInt(inFile);
            temporaryArrivalTime = getInt(inFile);
            //cout << temporaryName << temporaryItems << temporaryArrivalTime <<" "<< numberOfItems<<endl;

            customer * temporaryCustomer = new customer(temporaryName, temporaryArrivalTime, temporaryItems);
            add(temporaryCustomer);
        }
    else{
        cout<<"Failure to read";
    }
    
    
    for (int i = 0; i<numberOfItems; i++) {
        add(&temporaryCustomerHolder.at(i));
        
    };
    comp11::atEndOfFile(inFile);
}

int Queue::getPeopleInQueue(){
    return numberInQueue;
}

customer * Queue::getFront(){
    /*if (isEmpty()) {
    }*/
    return front;
}


customer * Queue::remove() {
    customer * removedCustomer = front;
    if (front==NULL){
        throw "NotEmpty";
    }
    
    front = front->getNext();
    numberInQueue--;
    return removedCustomer;

}

void Queue::add(customer * newCustomer){
    if(isEmpty()){
        front = newCustomer;
        front->setNext(NULL);
    }else{ 
        back->setNext(newCustomer);
    }
    back = newCustomer;

    
    numberInQueue++;
        
    return;
}

int Queue::isEmpty(){
    if (front==NULL)
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
        string nameCurrentName = currentNode->getName();
        int totalWait = (currentNode->getStartCheckoutTime()-currentNode->getArrivalTime());
        cout<<nameCurrentName<<" "<<totalWait<<endl;
        currentNode = currentNode->getNext();
    }
    

}
