#include <iostream>
#include <string>
#include <vector>
#include "Source.h"

using namespace std;

struct block 
{
	char name;
	double base;
	double power;
	double coefficient;
	char nextOperation = NULL;

	double operator+(block other)
	{
		return this->coefficient*pow(this->base, this->power) + other.coefficient*pow(other.base, other.power);
	}

};

void printOriginalExpression(std::vector<block> &algebraEquation);

void printFirstDerivative(std::vector<block> &algebraEquation);

int main()
{
	string equation;
	cin >> equation;
	vector<block> algebraEquation;

	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] == 'x' || equation[i] == 'y') //TODO allow all character symbols *create isCharacter() for checking. 
		{
			block block;
			block.name = equation[i];
			char c = equation[i - 1];
			block.coefficient = c - 48; //acii char -> int difference
			(equation[i + 1] == '^') ? block.power = equation[i+2] - 48 : block.power = 1 ;
			algebraEquation.push_back(block);
		}

		if (equation[i] == '+' || equation[i] == '-') // TODO allow all operators/
		{
			block* lastBlock = &algebraEquation.back();
			lastBlock->nextOperation = equation[i];
		}

	}

	printOriginalExpression(algebraEquation);
	printFirstDerivative(algebraEquation);

	//getUserDefinedLengthAndWidth();
	

	while (1); //hold the output window open.
	return 0;
}

void printFirstDerivative(std::vector<block> &algebraEquation)
{
	cout << "\nFirst Derivative\n";
	for (auto item : algebraEquation)
	{
		cout << item.coefficient*item.power << item.name;
		if (item.power - 1 > 1)
		{
			cout << "^" << item.power - 1;
		}
		if (item.nextOperation) {
			cout << " " << item.nextOperation << " ";
		}
	}
}

void printOriginalExpression(std::vector<block> &algebraEquation)
{
	cout << "--Original Expression--\n";
	for (auto item : algebraEquation)
	{
		cout << item.coefficient << item.name;
		if (item.power > 1)
		{
			cout << "^" << item.power;
		}
		if (item.nextOperation != NULL) {
			cout << item.nextOperation;
		}
	}
}

void getUserDefinedLengthAndWidth()
{
	double surfaceAreaAvailable;
	double length;
	double width;
	double maxVolume;

	cout << "Please enter Length and width of material available. \nLength: ";
	cin >> length;
	cout << "Width: ";
	cin >> width;
	surfaceAreaAvailable = length * width;
	cout << "Surface Area: " << surfaceAreaAvailable;
}
