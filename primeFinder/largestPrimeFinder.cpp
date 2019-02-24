//
//  primeFinder.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/7/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include <iostream>

void primeFinderV3(long number);
bool isPrime(int i); //function thats true if an int is prime

int main(int argc, char *argv[]){
    if(argc == 2){  // this will stop people from entering more args
        long number = atol(argv[1]);
        primeFinderV3(number);
    }
    return 0;
}

// will receive input from command line //
void primeFinderV3(long number){
    const long requestedNum  = number;
    std::cout << "Finding Largest Prime for " << requestedNum << "\n"<< std::endl;
    std::cout << "--- List of Primes ---" << std::endl;
    long checkingVar = 1;
    long newNumToFindPrime = requestedNum;
    for (int i = 2; i <= newNumToFindPrime; i++){
        double rCheck = newNumToFindPrime%i;
        // While loop will check for multiple of the same prime //
        while(!rCheck){
            // isPrime() will makes sure the int is a prime int before continuing //
            if(isPrime(i)){
                newNumToFindPrime = newNumToFindPrime / i;
                checkingVar *= i;
                std::cout << i <<std::endl;
                rCheck = newNumToFindPrime%i;
                // checkingVar is for making sure that the requested number is not exceeded when taking prime value and multiplying them together //
                if(checkingVar == requestedNum){
                    std::cout << "______________________\n" << std::endl;
                    std::cout << "Largest Prime Found: " << i << "\n\n"<< std::endl;
                    break;
                }
            }
        }
    }
}

//returns true is the number is prime
bool isPrime(int i){
    for(int x = i-1; x >= 1; x--){
        double modCheck = i%x;
        if(!modCheck && x!=1){
            return false;
        }
    }
    return true;
}

