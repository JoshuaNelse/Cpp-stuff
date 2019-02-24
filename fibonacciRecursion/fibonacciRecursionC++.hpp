//
//  fibonacciRecursionC++.hpp
//  BitBucketProject
//
//  Created by josh shaver on 10/31/18.
//

#ifndef fibonacciRecursionC___hpp
#define fibonacciRecursionC___hpp

#include <stdio.h>
#include <iostream>
using namespace std;

void recursionSequence(int n, int x[], int iteration){
    if (n <= 0){ //This will prove true when the recursion has ended, and will print finished result.
        int x_arraySize = iteration + 2; //since x[0] and x[1] already exist at iteration 0.
        for (int i=0; i < x_arraySize; i++){
            cout << x[i] << endl;
        }
    } else {
        int nextArrayValue = x[iteration] + x[iteration +1];
        x[iteration+2] = nextArrayValue;
        n--;
        iteration++;
        recursionSequence(n,x,iteration);
    }
}

void printFibonacciSeries (){
    int seriesLength;
    cout << "Enter the request length of the Fibonacci series you wish to print!" << endl;
    cin >> seriesLength;
    cout << "Printing sequence . . ." << endl;
    int x[seriesLength]; //allocating space for an array of requested size.
    int iteration = 0; // using this for a simple "tracker/counter" of sorts.
    int n = seriesLength -2;
    x[0] = 0;
    x[1] = 1;
    recursionSequence(n,x,iteration);
}

#endif /* fibonacciRecursionC___hpp */
