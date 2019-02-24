//
//  C++chapter2exercisesJosh.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/4/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include "C++chapter2exercisesJosh.hpp"
#include <iostream>

void mortgageCalculator();
void doublePointer();
void lowLevelConst();
void pointerAndReference();

int main(){
    mortgageCalculator(); //2.2 exercise
    doublePointer();
    lowLevelConst();
    pointerAndReference();
}


void mortgageCalculator(){
    float  rate(.034); //could use float or double, since this will also be a small number i will use float here
    int principle{ 700 }; //in a real life scenerio i would always use double here, but this is a whole number so ill use "int"
    double payment{principle + (principle * rate)}; //double only makes since for the decimal, could use float though i guess
    std::cout << "--- Exercise 2.2 ---" << std::endl;
    std::cout << "Your Monthly payment will be - $" << payment << std::endl;
    
    std::string book = "0-201-78345-X";
    std::cout << book << std::endl;
}

void pointerAndReference(){
    std::cout << "\n--- Exercise 2.something ---" << std::endl;
    //int i, &ri = i; //interesting... you can initialize a pointer with a pointer
    double d, &rd{d};
    //i = 5; ri = 10;
    d = 99.9; rd = 99.8;
    // i = rd; // you can also update an int with a double, it will just truncate the value.
    int pie = 42;
    int *e = &pie;
    //std::cout << "Int values and references: " << i << " " << ri << std::endl;
    std::cout << "Double values and references: "<< d << " " << rd << std::endl;
    std::cout << "\n--- Exercise 2.18 ---" << std::endl;
    std::cout << "Pointer location: "<< e << "\nPointer value: "<< *e << std::endl;
    
    
    if (e) { //bool check to see if the pointer is null or not
        char pointerOverride;
        int newPointer = 99;
        std::cout << "Would you like to over-ride the pointer?\nType \"N\" to keep old pointer type \"Y\" to continue." << std::endl;
        std::cin >> pointerOverride;
        if (pointerOverride == 'y' || pointerOverride == 'Y'){
            *e = newPointer;
            std::cout << "New pointer location: "<< e << "\nNew pointer value: "<< *e << std::endl;
        } else if (pointerOverride == 'n' || pointerOverride == 'N') {
            std::cout << "\nNo changes were made." << std::endl;
        } else {
            std::cout << "\nInvalid input" << std::endl;
        }
    }
}


void doublePointer(){
    int varInt = 20;
    int *const pointer1 = &varInt;
    int *pointer2 = pointer1; // since this is pointing at a const for some reason it does not require a double de reference.
    int **pointer3 = &pointer2; // requires double dereference since it is a pointer pointed at another pointer object.
    
    std::cout << "--- Double Pointer ---" << std::endl;
    std::cout << **pointer3 << std::endl; //if i cout *pointer3 it cant dereference fully and never returns a int value im guessing
}

void lowLevelConst(){
    std::cout << "\n--- Exercise 2.31 ---" << std::endl;
    //low level const is when it is determine on the variable level
    //This means that the const will be taken into effect when the object is being copied over
    int i = 0;
    const int v2 = 0;
    int v1 = v2; //v1 initializes from value of v2 const
    int *p1 = &v1, &r1 = v1; //pointer is created for v1    //alias is created for v1 named r1
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    
    r1 = v2; //this works but it is simply replacing v1 with the value of v2 that it initailized with
    //p1 = p2; this does not work because *p2 is pointing to a const int and p1 is not a const pointer
    //p1 = p3; // cannot assign p3 to p1 becaust p3 is a "const int *const pointing"
    p2 = p1; //this works because the high level has const and the low level does not which is fine.
    p2 = p3; //p3 points to "i" which has no low level const. all high level constants can exist with no conflict.
    
    //After analyzing this farther it appears one primary rule applies If a low level const exist all top level const must exist.
    //otherwise if the low level variable is not a const, the complier does not care if the top level const exist or not with pointers or references.
    
    //proof
    const int constProof = 20; // << low level const (the actual variable is const)
    //int *failReference = &constProof; //top level will error since the reference is not const
    //int &failPointer = constProof;//top level will error since the pointer is not const.
    const int *pointProof = &constProof; // since low level is const these top level const are required
    const int &refProof = constProof; // same thing here, top level const with a reference instead
    
    //2.32 Exercise
    //int null = 0,
    //*p = null;
    // >> corrected to >>
    int null = 0;
    int *p = &null;
    
    std::cout << r2 << *pointProof << refProof << *p << std::endl; // just to get rid of unsused variable messgaes in IDE
}


