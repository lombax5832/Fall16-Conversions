#pragma once

/**
*	Author:			Alexei Snytkine
*	Description:	Module used to convert integers and doubles into strings,
*					also to see if a string is a valid identifier
*	Date Created:	9/3/16
*	Date Modified:	9/3/16
*/

// Maximum amount of characters need to store an integer, including null char & sign
const int MAX_INT_STRING_LENGTH = 12;
// Offset of decimal digits to ascii value
const int DIGIT_TO_ASCII_OFFSET = 48;

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