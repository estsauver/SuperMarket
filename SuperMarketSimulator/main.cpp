//
//  main.cpp
//  SuperMarketSimulator
//
//  Created by Earl St Sauver on 2/16/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "Supermarket.h"
int main (int argc, const char * argv[])
{
    int configNumber;
//    string strFilename;
//
    cout << "Enter a configuration number: " <<endl;
    cin >> configNumber;
//    cout << "Enter a filename: " <<endl;
//    cin >> strFilename;
    
    string strFilename= "/Users/estsauver/Documents/linear.data";
    Queue newTestQueue = Queue();
    newTestQueue.queueFromFile("/Users/estsauver/Documents/linear.data");
    Supermarket testMarket = Supermarket(configNumber, strFilename);
    return 0;
    
}

