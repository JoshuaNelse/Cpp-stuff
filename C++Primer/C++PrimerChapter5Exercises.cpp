#include <iostream>
#include <vector>
using namespace std;

void exercise5_5();
void switchStuff();
void continuePractice();
int gotoPractice();
void tryCatchstuff();
int main() {

	cout << "exercise 5.5: (should inform you of your letter grade) \n";
	exercise5_5();
	cout << "\n\nMessing around with switches: (counts i,o,a, and other characters) \n";
	switchStuff();
	cout << "\n\nMessing around with the continue statement: (should only print even numbers) \n";
	continuePractice();
	cout << "\n\nProperSyntax using goto statement: (first 10 numbers from fibonacci series) \n";
	gotoPractice();
	cout << "\n\ntry catch block: (throws expection if dividing by zero) \n";
	tryCatchstuff();

	cin.get();
	cin.get();
	return 0;
}





void exercise5_5() {
	vector<char> gradeList = { 'F', 'D', 'C', 'B', 'A' };

	int grade;
	string plusOrMinus;
	string returnString;
	char letterGrade;
	cout << "Enter your grade!" << endl;
	cin >> grade;

	if (grade < 60) {
		letterGrade = gradeList[0];
	}
	else {
		letterGrade = gradeList[(grade - 50) / 10];
		if ((grade % 10) < 3) {
			plusOrMinus = "-";
		}
		if ((grade % 10) > 7) {
			plusOrMinus = "+";
		}
	}

	returnString.push_back(letterGrade);
	returnString += plusOrMinus;

	cout << grade << " is a ";

	for (auto control : returnString) {
		cout << control;
	}

	cout << endl;
}

void switchStuff() {
	string myString = "My name is Josh";
	cout << "string \"";
	int aCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int otherCnt = 0;

	for (auto control : myString) {
		switch (control) {
		case 'a':
			++aCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		default:
			++otherCnt;
		}
		cout << control;
	}
	cout << "\""<< endl;
	cout << "a: " << aCnt << endl;
	cout << "i: " << iCnt << endl;
	cout << "o: " << oCnt << endl;
	cout << "other: " << otherCnt << endl;
}

void continuePractice() {
	vector<int> myNums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//print all even numbers
	for (auto control : myNums) {
		if (control % 2) {
			continue;
		}
		cout << control << " ";
	}
}

int gotoPractice() {
		goto line2;
	line1:
		return 0;
	line2:
		vector<int> fibSeries; goto line3;
	line3:
		int i = 0; goto line4;
	line4:
		fibSeries.push_back(i); goto line6;
	line5:
		fibSeries.push_back(fibSeries[i - 1] + fibSeries[i - 2]); goto line6;
	line6:
		cout << fibSeries[i] << " "; goto line7;
	line7:
		++i; if (i >= 10) goto line1; if (i < 2) goto line4;  goto line5;
}

void tryCatchstuff() {
	cout << "Enter two numbers to divide. \n";
	int x;
	int y;
	cin >> x >> y;

	try {
		if (y == 0) {
			throw runtime_error("Cannot divide by zero.");
		}
		else {
			cout << endl << x << "/" << y << " = " << x / y;
		}
	}
	catch (runtime_error err) {
		cout << err.what();
	}
}