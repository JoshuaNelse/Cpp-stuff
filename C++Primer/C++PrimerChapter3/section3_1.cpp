//
//  section3_1.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/12/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using std::string; 

int main(){
    string myName = "JOSHUA";
    int mySize = sizeof(myName);
    std::cout << myName << std::endl;
    std::cout << "Size of \"JOSHUA\" in bytes: " << mySize << std::endl;
    std::cout << myName.size() << std::endl; // prints "6" for string length
    std::cout << myName.empty() << std::endl; // prints "0" for false
    myName = "";
    std::cout << myName.empty() << std::endl; // prints "1" for true
    return 0;
}





