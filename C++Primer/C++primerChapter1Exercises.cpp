//
//  main.cpp
//  Play_ground
//
//  Created by josh shaver on 10/28/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

// excersice sections from C++ primer 5th edition
#include <iostream>
#include "C++primerChapter1Exercises.hpp"
using namespace std;

int main () {
    const string favoriteFood[5] = {"Pizza","Hot Chicken","Fajitas","Ice cream","Water"};
    string line = "--------------------------------------";
    string stringOfFavorites;
    for (int i=1; i<=5; i++){
        stringOfFavorites += to_string(i) + ".) " + string(favoriteFood[i]) + "\n";
    }
    cout << stringOfFavorites << endl;
    cout << line << endl;
    //exercise section 1.4.1
    //exercise 1.9
    
    int sum = 0, value =50;
    while (value <= 100){
        sum += value;
        ++value;
    }
    cout << "Grabbing the sum of every whole number int from 50 - 100 \n" << sum << endl;
    cout << line << endl;
    
    
    /*
     *  This one was fun because i had to figure something out for the edge case of some entering the greater value first. I simply sort  the variable
     *  before looping and handing off values to the array for printing
     *
     *  --- performed a fix ---
     * int itterator = range1 +1; //I did that to compensate for the range1 var being the reference to start counting. for some reason
     *                              This caused the array to be 1 value short and the array would print some odd values
     *                              * i am assuming this affected the "arrayLength_integersInRange = range2 - range1"
     *
     *  == Added the compensational "+1" inside the while loop to fix this ==
     *  integersInRange[arrayIndexer_integersInRange] = itterator + 1;
     *
     *  ==Re sorted these three lines to resolve this in a cleaner fassion ==
     *    ++itterator;
     *    ++arrayIndexer_integersInRange;
     *    integersInRange[arrayIndexer_integersInRange] = itterator;
     *
     *
     * exercise 1.11
     */
    cout << "Enter two numbers to pull every integer between those two values";
    int range1, range2;
    cin >> range1 >> range2;
    
    //Ordering the user's data input by integer value (least to greatest)
    if (range2 < range1){
        int swappingVar = range2;
        range2 = range1;
        range1 = swappingVar;
    }
    int itterator = range1;
    int arrayLength_integersInRange = range2 - range1;
    int integersInRange[arrayLength_integersInRange];
    int arrayIndexer_integersInRange = 0;
    while (itterator < range2){
        ++itterator;
        ++arrayIndexer_integersInRange;
        integersInRange[arrayIndexer_integersInRange] = itterator;
    }
    cout << "Showing all whole int values between selected value " << range1 << " and " << range2 << endl;
    for (int q = 0; q < arrayLength_integersInRange; q++){
        cout << integersInRange[q] << endl;
    }
    return 0;
}
