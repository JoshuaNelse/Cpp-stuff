#include <iostream>
#include <vector>
using namespace std;

void exercise3_30();
int exercise3_31(int i);
void exercise3_32();
void exercise3_34();
void exercise3_35();
void exercise3_41();
void exercise3_40ish();

int main(){
	
	//exercise3_30();
	//exercise3_31();
	//exercise3_32();
	//exercise3_34();
	//exercise3_35();
	//exercise3_41();
	exercise3_40ish();

	cin.get();
	return 0;
}

//Exercise 3.30: Identify the indexing errors in the following code
void exercise3_30() {
	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 1; ix <= size(ia); ++ix) {
		ia[ix] = ix;
		// the [0] index is never being filled, so [10] is actually one past the last index of the ia array
	}
}

//Exercise 3.31: Write a program to define an array of ten ints.Give each element the same value as its position in the array.
int exercise3_31(int i) {
	int arr[10];
	for (int j = 0; j < size(arr); ++j) {
		arr[j] = j;
	}
	return arr[i];
}

//Exercise 3.32: Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors. 
void exercise3_32() {
	int arr2[10];
	for (int i = 0; i < size(arr2); ++i) {
		arr2[i] = exercise3_31(i); //because im lazy
	}
	//rewrite using a vector
	vector<int> vec3;
	for (auto i = 0; i < size(arr2); ++i){
		vec3.push_back(exercise3_31(i));
	}
}

void exercise3_34() {
	int arr[3] = {1,2,3};
	int *p1 = arr;
	int *p2 = arr + 2;
	p1 += p2 - p1;
	// 0076F8F4 = 0076F8F4 + 0076F8F4 - 0076F8F4 << this is the techinical values of the variables in the above expression 
}

//Exercise 3.35: Using pointers, write a program to set the elements in an array to zero.
// im not sure what i am supposed to be doing.... pointers cannot change the object they are pointing to.
void exercise3_35() {
	int arr[5] = { 2,4,7,9,8 };
	int *p = arr;
	int *p2 = arr + size(arr);
	for (int i = 0; i < size(arr); ++i) {
		cout << arr[i] << " ";
		arr[i] = 0;
		cout << "New: " << arr[i] << endl;
	}
}

//Exercise 3.41: Write a program to initialize a vector from an array of ints. 
void exercise3_41() {
	int arr[5] = { 3,2,5,6,7 };
	vector<int> vec(begin(arr), end(arr));
	// thats pretty nifty.
}

// just playing around with printing a 2d array for practice.
void exercise3_40ish() {
	int arr2D[3][10];
	int i = 0;
	for (auto &row : arr2D) {
		i += 10;
		cout << endl;
		for (auto &element : row) {
			element = i;
			i++;
			cout << i << " ";
		}
	}
}