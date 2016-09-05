#pragma once

/**
*	Author:			Alexei Snytkine
*	Description:	Module used to convert integers and doubles into strings,
*					also to see if a string is a valid identifier
*	Date Created:	9/3/16
*	Date Modified:	9/3/16
*/

// Maximum amount of characters need to store an integer or double, including null char, sign & decimal
const int MAX_INT_STRING_LENGTH = 12;
const int MAX_DOUBLE_STRING_LENGTH = 20;
// ASCII value of 0 and 9
const int ASCII_0 = 48;
const int ASCII_9 = 57;

/*
	Description:	Convert an integer into a string
	Pre:			Valid Integer
					Sufficiently Large char Array
	Post:			Char array will be a string that prints the same text as given int
	Parameters:		
					input: int to convert to string
					output: char array to insert characters into
*/
void int2str(int input, char output[]);

/*
	Description:	Return an integer from given string
	Pre:			Valid String
					Sufficiently Large char Array
	Post:			Returned value will include all numerical characters until the null character
	Parameters:		
					input: char array to convert to an int
*/
int str2int(const char input[]);

/*
	Description:	Convert an double into a string
	Pre:			Valid Double
					Sufficiently Large char Array
	Post:			Char array will be a string that prints the double in scientific notation
	Parameters:		
					input: double to convert to string
					output: char array to insert characters into
*/
void double2str(double input, char output[]);