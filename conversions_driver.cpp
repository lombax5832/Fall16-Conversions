using namespace std;
#include <iostream>
#include <cmath>
#include "conversions.h"

int main() {
	char temp[MAX_INT_STRING_LENGTH] = "";
	int conv;	

	while (true) {
		conv = 0;
		temp[0]='\0';
		cin >> conv;
		conv = (int)conv;
		cin.clear();
		int2str(conv, temp);

		cout << "String: " << temp << endl;		
	}

	return 0;
}