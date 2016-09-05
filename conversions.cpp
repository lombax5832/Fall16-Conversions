using namespace std;
#include<iostream>
#include<cmath>
#include<algorithm>
#include "conversions.h"
#include <string.h>

/**
*	Author:			Alexei Snytkine
*	Description:	Module used to convert integers and doubles into strings,
*					also to see if a string is a valid identifier
*	Date Created:	9/3/16
*	Date Modified:	9/3/16
*/

void int2str(int, char[], int);
void int2str(int, char[], int, int);
void addCharToStr(char, char[], int);
int char2int(char);

/*
	Description:	Convert an integer into a string
	Pre:			Valid Positive Integer
					Sufficiently Large char Array
	Post:			Char array will be a string that prints the same text as given int
	Parameters:		
					input: int to convert to string
					output: char array to insert characters into
					position: 10^(value of first digit in input)
*/
void int2str(int input, char output[], int position, int strLength) {
	char temp = ' '; //Temporary char to hold the ascii value of the first digit of the passed input
	position = max(position, 1); //Prevents dividing by 0
	temp = (input / position) + ASCII_0; //Sets temp equal to the ascii code the first digit
	addCharToStr(temp, output, strLength); //Add temp to the end of the output string
	input %= position; //Remove the first digit from input
	position /= 10; //Move one digit lower

	//Repeat as long as we still have more digits to concatenate
	if (position != 0) {
		int2str(input, output, position, strLength);
	}
}

int str2int(const char input[]) {
	int i = 0, sign = 1, output = 0;
	if (input[i] == '-') {
		sign = -sign;
		i++;
	}
	while ((input[i] >= ASCII_0) && (input[i] <= ASCII_9)) {
		
		if (output > 0) {
			output *= 10;
		}
		output += char2int(input[i]);
		i++;
	}
	return sign*output;
}

void double2str(double input, char output[]) {
	int beforeDec = 0; // Numbers before decimal place
	int digBeforeDec = 0; // Number of digits before the decimal place
	double afterDec = 0; // Numbers after decimal place

	// Add negative sign if necessary
	if (input < 0.0) {
		input = abs(input);
		addCharToStr('-', output, MAX_DOUBLE_STRING_LENGTH);
	}

	beforeDec = input;
	afterDec = input - (double)beforeDec;

	int2str(beforeDec, output, MAX_DOUBLE_STRING_LENGTH); // Add numbers before decimal place to string
	addCharToStr('.', output, MAX_DOUBLE_STRING_LENGTH); // Add decimal place to string

	digBeforeDec = max((int)(log10(input) + 1), 1);

	for (int i = digBeforeDec; i < MAX_DOUBLE_STRING_LENGTH - 2; i++) {
		afterDec *= 10;
		addCharToStr((int)afterDec + ASCII_0, output, MAX_DOUBLE_STRING_LENGTH);
		afterDec -= (int)afterDec;
	}
}

/*
	Description:	Add a char to the end of a char array
	Pre:			Valid character array
					Valid char to append
					length > 2
	Post:			input char will be appended to end of output array
	Parameters:		
					input: char to append to output[]
					output: char array to insert character into
					length: size of output[]
*/
void addCharToStr(char input, char output[], int length) {

	//Search all characters except last, since only null char could be there
	for (int i = 0; i < length - 1; i++) {

		//If we find the end of the string, replace null char 
		//with input char and move null char over by one
		if (output[i] == '\0') {
			output[i] = input;
			output[i + 1] = '\0';
			break;
		}
	}
}

/*
	Description:	Return a signle digit int equal to the char that represents it
	Pre:			Valid character to change to an int
	Post:			Char will be converted into the digit it represents as an int
	Parameters:		
					input: char to change to an int
*/
int char2int(char input) {
	if ((input >= ASCII_0) && (input <= ASCII_9)) {
		return input - ASCII_0;
	}
	return 0;
}

void int2str(int input, char output[]) {
	int2str(input, output, MAX_INT_STRING_LENGTH);
}

void int2str(int input, char output[], int strLength) {

	int length = 1; //Number of digits in the input

	if (input < 0) {
		addCharToStr('-', output, strLength);
		input = abs(input);
	}

	length = log10(input);
	int2str(input, output, pow(10, length), strLength);
}