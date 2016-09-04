using namespace std;
#include <iostream>
#include <cmath>
#include "conversions.h"

int main() {
	char temp[MAX_INT_STRING_LENGTH] = "";
	int conv = 1345098027;

	int2str(conv, temp);

	cout << temp << endl;

	return 0;
}