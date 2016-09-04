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
void addCharToStr(char, char[], int);

void int2str(int input, char output[]) {

	int length = 1; //Number of digits in the input

	if (input < 0) {
		addCharToStr('-', output, MAX_INT_STRING_LENGTH);
		input = -input;
	}

	length = log10(input);
	int2str(input, output, pow(10, length));
}

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
void int2str(int input, char output[], int position) {
	char temp = ' '; //Temporary char to hold the ascii value of the first digit of the passed input
	position = max(position, 1); //Prevents dividing by 0
	temp = (input / position) + DIGIT_TO_ASCII_OFFSET; //Sets temp equal to the ascii code the first digit
	addCharToStr(temp, output, MAX_INT_STRING_LENGTH); //Add temp to the end of the output string
	input %= position; //Remove the first digit from input
	position /= 10; //Move one digit lower

	//Repeat as long as we still have more digits to concatenate
	if (input != 0) {
		int2str(input, output, position);
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