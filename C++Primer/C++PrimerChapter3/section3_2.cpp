//
//  section3_2.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/15/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

void exercise3_2();
void exercise3_4();
void exercise3_5();
void myRangeForLoop();
void exercise3_6();
void exercise3_7();
void exercise3_8();
void exercise3_10();

int main(){
    //uncomment below functions to view their results (some require input)//
    //exercise3_2();
    //exercise3_4();
    //exercise3_5();
    //myRangeForLoop();
    //exercise3_6();
    //exercise3_7();
    //exercise3_8();
    //exercise3_10();
    return 0;
}

void exercise3_2(){
    const string stop = "STOP!";
    string line;
    string runState= "Line Read";
    if(runState != "No Read"){
        while (getline(cin, line) && runState == "Line Read"){
            cout << line << endl;
            if(line == stop){
                runState = "Word Read";
            }
        }
        while (cin >> line && runState == "Word Read"){
            cout << line << endl;
            if(line == stop){
                runState = "No Read";
            }
        }
    }
}

void exercise3_4(){
    string a = "ABC";
    string b = "ABCD";
    string c = "ABC";
    
    if(a == c){
        cout << "A is equal to C" << endl;
    }
    if(a != b){
        bool strCheck = b > a;
        cout << strCheck << endl; // will return "1" for true b is greater than a
    }
    if (a.size() == c.size()){
        cout << "a is the same size as c" << endl;
        bool sizeCheck = b.size() > a.size();
        cout << sizeCheck << endl;
    }
}

void exercise3_5(){
    string text;
    string fullText;
    bool readState = true;
    while (readState){
        if (cin >> text){
            if (text == "QUIT"){
                readState = false;
            } else {
                fullText += (text + " ");
            }
        }
    }
    cout << fullText << endl;
}

// when dealing with every index inside an array Range For loops work great
// SYNTAX: for(declaration : expresion) {statement}
void myRangeForLoop(){
    string c = "Pizza is yummy";
    for (auto c : c){
        cout << c;
    }
    cout << endl;
    
    //Playing with decltype and reference
    decltype(c) &r = c;
    cout << r << endl;
    
    //using a reference in the for loop
    for (auto &ref : c){
        ref = toupper(ref); // making all characters upper case
    }
    cout << c << endl;
}

//Use a range "for" to change all characters in a string to "X"
void exercise3_6(){
    string myString = "Something i will convert to Xs, all spaces will be lowecase though for added fun";
    for (auto &ref : myString){
        if(isspace(ref)){
            ref = 'x';
        } else {
            ref = 'X';
        }
    }
    cout << myString << endl;
}

//What would happen if you define the loop control variable in the previous exercise as type char?
//appears to work fine as long as you dont try to treat the control variable like a string. It should only be holding 1 char at a time for the iteration
void exercise3_7(){
    string myString = "Random text for exercise";
    for(char control : myString){
        cout << control;
    }
    cout << endl;
}

void exercise3_8(){
    string myString = "Something i will convert to Xs, all spaces will be lowecase though for added fun";
    string myWhileString = myString;
    string myForString = myString;
    cout << "Initial String:\n" << myString << endl;
    
    //range for
    cout << "Range For Loop:" << endl;
    for (auto &ref : myString){
        if(isspace(ref)){
            ref = 'x';
        } else {
            ref = 'X';
        }
    }
    cout << myString << endl;
    
    //while
    cout << "While Loop:" << endl;
    int whileLoopIterator = 0;
    while(whileLoopIterator < myWhileString.size()){
        auto &ref = myWhileString[whileLoopIterator];
        if(isspace(ref)){
            ref = 'x';
        } else {
            ref = 'X';
        }
        whileLoopIterator++;
    }
    cout << myWhileString << endl;
    
    //regular for loop
    cout << "Regular For Loop:" << endl;
    for (int i = 0; i < myForString.size(); i++){
        auto &ref = myForString[i];
        if(isspace(ref)){
            ref = 'x';
        } else {
            ref = 'X';
        }
    }
    cout << myForString << endl;
    
    //Honestly I like how clean the range for loop is.
}

//Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
void exercise3_10(){
    
    string myString = "This is a string. The date is 11-18-18";
    cout << "String with punctuation: \n" << myString << endl;
    string newString = "";
    
    //creating new string without punctuation
    for(auto control : myString){
        if(!ispunct(control)){
            newString += control;
        }
    }
    cout << newString << endl;
}
    
