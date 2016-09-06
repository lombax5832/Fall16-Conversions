using namespace std;
#include <iostream>
#include <iomanip>
#include "convert.h"

/**
*	Author:			Alexei Snytkine
*	Description:	Test driver for convert module
*	Date Created:	9/3/16
*	Date Modified:	9/6/16
*/
int main() {
	char strToInt[MAX_INT_STRING_LENGTH]; //String for storing and dipslaying integers
	char strToDouble[MAX_DOUBLE_STRING_LENGTH]; //String for storing and dipslaying doubles
	char identifier[64]; //String for storing and dipslaying identifiers

	int intToString = 0; //Integer to convert into a string
	double doubleToString = 0.0; //Double to convert into a string

	//Testing str2int
	cout << "Enter a string to convert to an integer: ";
	cin >> strToInt;
	cout << fixed << setprecision(10) << "String -> Integer: " << str2int(strToInt) << endl;
	cin.clear();
	
	//Testing str2double
	cout << "Enter a string to convert to a double: ";
	cin >> strToDouble;
	cout << fixed << setprecision(10) << "String -> Double: " << str2double(strToDouble) << endl;
	cin.clear();

	//Testing int2str
	cout << "Enter an integer to convert to a string: ";
	cin >> intToString;
	strToInt[0] = '\0';
	int2str(intToString, strToInt);
	cout << "Integer -> String: " << strToInt << endl;
	cin.clear();

	//Testing double2str
	cout << "Enter a double to convert to a string: ";
	cin >> doubleToString;
	strToDouble[0] = '\0';
	double2str(doubleToString, strToDouble);
	cout << "Double -> String: " << strToDouble << endl;
	cin.clear();

	//Testing isIdentifier
	cout << "Enter a string to see if it is a valid identifier: ";
	cin >> identifier;
	if (isIdentifier(identifier)) {
		cout << identifier << " is a valid identifier." << endl;
	}
	else {
		cout << identifier << " is not a valid identifier." << endl;
	}

	return 0;
}