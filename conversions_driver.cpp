using namespace std;
#include <iostream>
#include <cmath>
#include "conversions.h"

int main() {
	char temp[MAX_DOUBLE_STRING_LENGTH] = "";
	double conv;	

	while (true) {
		conv = 0.0;
		temp[0]='\0';
		cin >> temp;
		cin.clear();

		cout << "Double: " << str2double(temp) << endl;		
	}

	return 0;
}