//
//  section3_3.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/18/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void myVector();
void exercise3_12();
void exercise3_13();
void exercise3_14();
void exercise3_15();
void exercise3_17();
void exercise3_18();
void exercise3_19();
void exercise3_20();

int main(){
    //myVector();
    //exercise3_12();
    //exercise3_13();
    //exercise3_14();
    //exercise3_15();
    //exercise3_17();
    //exercise3_18();
    //exercise3_19();
    exercise3_20();
    return 0;
}

void myVector(){
    vector<int> firstVector{
        1,
        2,
        3
    };
    cout << firstVector[2] << endl;
}

//Which, if any, of the following vector definitions are in error?
void exercise3_12(){
    vector<vector<int>> ivec;
    //vector<string> svec = ivec; // cant convert int to string for vector to copy from
    vector<string> svec(10, "null");
}

//How many elements are there in each of the following vectors? What are the values of the elements?
void exercise3_13(){
    vector<int> v1;                 // 0 , none
    vector<int> v2(10);             // 10, none
    vector<int> v3(10, 42);         // 10, 42
    vector<int> v4{10};             // 1,  10
    vector<int> v5{10, 42};         // 2, [10,42]
    vector<string> v6{10};          // 10, emtpy strings
    vector<string> v7{10, "hi"};    // 10, "hi"
    
    
    cout << "vector<int> v1;\n"                  << "    size: "  << v1.size() << endl;
    cout << "\nvector<int> v2(10);\n"            << "    size: "  << v2.size() << endl;
    cout << "\nvector<int> v3(10, 42);\n"        << "    size: "  << v3.size() << endl;
    cout << "\nvector<int> v4{10};\n"            << "    size: "  << v4.size() << endl;
    cout << "\nvector<int> v5{10, 42};\n"        << "    size: "  << v5.size() << endl;
    cout << "\nvector<string> v6{10};\n"         << "    size: "  << v6.size() << endl;
    cout << "\nvector<string> v7{10, \"hi\"};\n" << "    size: "  << v7.size() << endl;
}

void exercise3_14(){
    cout << "Type numbers you would like to store. Type 999 to see what you stored" << endl;
    int test;
    vector<int> number;
    
    while(cin >> test){
        if(test == 999){
            break;
        }
        number.push_back(test);
    }
    cout << "----- Number that you stored -----" << endl;
    for (auto i: number){
        cout << i << endl;
    }
    cout << "----------------------------------" << endl;
    
}


void exercise3_15(){
    cout << "Type words you would like to store. Type STOP to see what you stored" << endl;
    string test;
    vector<string> word;
    
    while(cin >> test){
        if(test == "STOP"){
            break;
        }
        word.push_back(test);
    }
    
    cout << "----- words that you stored -----" << endl;
    for (auto i: word){
        cout << i << endl;
    }
    cout << "----------------------------------" << endl;
}

// Exercise 3.17: Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change
//each word to uppercase. Print the transformed elements, eight words to a line.
void exercise3_17(){
   
    //my variables
    string line;
    string newLine;
    string lineBreak = "\n";
    int i = 0;
    
    //init while loop
    while (cin >> line){
        
        //escape with QUIT string
        if(line == "QUIT") break;
        
        // To make all Characters uppercase
        for(auto &control : line){
            control = toupper(control);
        }
        
        //concat on my string and adding spaces
        line += " ";
        newLine += line;
        
        //word counter
        i++;
        
        // To keep only 8 words per line
        if(i == 8){
            newLine += lineBreak;
            i = 0;
        }
    }
    
    // Print that thang
    cout << newLine << endl;
}

//Exercise 3.18: Is the following program legal? If not, how might you fix it?
void exercise3_18(){
    //does not appear to be legal.
    //vector<int> ivec;
    //ivec[0] = 42;
    
    // i would think the correct way to do this would be:
    vector<int> ivec;
    ivec.push_back(42);
    
}


//Exercise 3.19: List three ways to define a vector and give it ten elements,
//each with the value 42. Indicate whether there is a preferred way to do so and why.
void exercise3_19(){
    
    // first way (init that thang)
    vector<int> ivec1{42,42,42,42,42,42,42,42,42,42};
    
    //seconds way (copy that thang)
    vector<int> ivec2 = ivec1;
    
    //third way (iterate/push that thang)
    vector<int> ivec3;
    for (decltype(sizeof(ivec1)) i = 0; i < sizeof(ivec1); i++){
        ivec3.push_back(42);
    }
    
    //fourth way (bonus way) *i think this works, but i am not sure
    vector<int> ivecBonus(10,42);
    
    //I would be led to believe that the preferred manner of defining a vector
    //would be best determined on a case by case basis.
}


//Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of
//the first and last elements, followed by the sum of the second and second-tolast, and so on.
/*I left user input out of this one because i felt like it.*/
void exercise3_20(){
    cout << "-- your vector --\n{";
    vector<int> test{0,1,2,3,4,5,6,7,8,9};
    for(auto control : test){
        cout << control << ",";
    }
    cout << "}\n" << endl;
    cout << "-- Sum of each adjacent pair --" << endl;
    for(auto control : test){
        if(control != test.size() - 1){
        int adjacentSum = test[control] + test[control +1];
        cout << adjacentSum << ",";
        }
    }
    cout << endl << endl;
    
    cout << "-- Sum of first to last and so on --" << endl;
    for(auto control : test){
        if(control != test.size() - 1){
            int weirdSum = test[control] + test[(test.size()-1)-control];
            cout << weirdSum << ",";
        }
    }
    cout << endl << endl;
    
}
