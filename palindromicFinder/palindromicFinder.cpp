//
//  palindromicFinder.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/11/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//
//  --- CHALLANGE ---
//  "Find the largest palindrome made from the product of two 3-digit numbers."


#include <stdio.h>
#include <iostream>
#include <cmath>

int reversifyThatThang(int number);
void palindromicFinder();


int main(){
    palindromicFinder();
}



void palindromicFinder(){
    
    
    // "iterationCeiling" will be the  ceiling of the range for any palindromic value
    int iterationCeiling = 999*999;
    // "iterationFloor" will stop the loop before is goes below the product of 2 three digit values
    int iterationFloor = 100*100;
    // "palidronicFound" played around with a state flag for a secondary loop conditional
    bool palindronicFound = false;
    // "reversedNumber" defining a variable to hold the reversed number
    int reversedNumber = 0;
    
    
    //Starting from the ceiling and checking to see if every number down is palindromic
    for (int i = iterationCeiling; i > iterationFloor; i--){
        int numCheck = i;
        reversedNumber = reversifyThatThang(numCheck);
        if(reversedNumber == numCheck){
            palindronicFound = true;
        }
        //a series of checks to see if our value falls within specificied criteria
        if(palindronicFound){
            for(int j = 999; j > 99; j--){
                double modCheck = reversedNumber%j;
                if (!modCheck){
                    bool numOne = 999 > j  && j > 111;
                    bool numTwo = 999 > (reversedNumber/j) && (reversedNumber/j) > 111;
                    if (numOne && numTwo){
                        int printNumOne = j;
                        int printNumTwo = reversedNumber/j;
                        std::cout << "Largest palindroic: " << reversedNumber << std::endl;
                        std::cout << "The product of " << printNumOne << " and "
                        << printNumTwo << " is " << reversedNumber << std::endl;
                        break;
                    }
                    // if valid multiples are not found then restesting the state flag and starting from
                    // original loop
                } else if (j == 100 && modCheck){
                    palindronicFound = false;
                }
            }
        }
    }
}


// function used for reversing a number under 7 digits long.
int reversifyThatThang(int number){
    
    
    // "whileLoopIterator" will be the variable that will resolve the while loop below
    int whileLoopIterator = number;
    // array "a" will never need to store more than 6 digits, but i put zero anyways
    int a[7];
    // "i" stores the length of the number we are reversing
    int i = 0;
    // "reversedNumber" will be used to store our reversed number later on
    int reversedNumber = 0;
    
    
    // step 1 is recording the numbers in reverse order
    while (whileLoopIterator > 0){
        int rightMostNumber = whileLoopIterator % 10;
        whileLoopIterator /= 10;
        a[i]= rightMostNumber;
        i++;
    }
    
    
    //copying "i" since it cannot be modified (need "i" to resolve the for loop condition)
    int k = i;
    
    
    //step 2 using what the while loop put in my array to create a reversed number
    for(int j = 0; j<i; j++){
        if(k > 0){
            reversedNumber = reversedNumber + ((pow(10,k-1)) * a[j]);
            k--;
        } else {
            reversedNumber += a[j];
        }
    }
    
    
    return reversedNumber;
}
