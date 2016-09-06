using namespace std;
#include <iostream>
#include <iomanip>
#include "convert.h"

/**
*	Author:			Alexei Snytkine
*	Description:	Module used to convert integers and doubles into strings,
*					also to see if a string is a valid identifier
*	Date Created:	9/3/16
*	Date Modified:	9/6/16
*/
int main() {
	char strToInt[MAX_INT_STRING_LENGTH];
	char strToDouble[MAX_DOUBLE_STRING_LENGTH];
	char identifier[64];

	int intToString = 0;
	double doubleToString = 0.0;

	cout << "Enter a string to convert to an integer: ";
	cin >> strToInt;
	cout << fixed << setprecision(10) << "String -> Integer: " << str2int(strToInt) << endl;
	cin.clear();

	cout << "Enter a string to convert to a double: ";
	cin >> strToDouble;
	cout << fixed << setprecision(10) << "String -> Double: " << str2double(strToDouble) << endl;
	cin.clear();

	cout << "Enter an integer to convert to a string: ";
	cin >> intToString;
	strToInt[0] = '\0';
	int2str(intToString, strToInt);
	cout << "Integer -> String: " << strToInt << endl;
	cin.clear();

	cout << "Enter a double to convert to a string: ";
	cin >> doubleToString;
	strToDouble[0] = '\0';
	double2str(doubleToString, strToDouble);
	cout << "Double -> String: " << strToDouble << endl;
	cin.clear();

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