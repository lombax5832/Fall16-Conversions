using namespace std;
#include <iostream>
#include <cmath>
#include "conversions.h"

int main() {
	char temp[64];
	double conv;	

	while (true) {
		conv = 0.0;
		temp[0]='\0';
		cin >> temp;
		cin.clear();

		cout << "Is Identifier: " << isIdentifier(temp) << endl;		
	}

	return 0;
}