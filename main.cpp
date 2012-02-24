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
    char strFilename[255];

    cout << "Enter a configuration number: " <<endl;
    cin >> strFilename;
    cout << "Enter a filename: " <<endl;
    cin >> configNumber;
    
    string testString= "/Users/estsauver/Documents/test.data";
    Queue newTestQueue = Queue();
    //newTestQueue.queueFromFile("/Users/estsauver/Documents/test.data");
    Supermarket testMarket = Supermarket(configNumber, strFilename);
    return 0;
    
}

