#pragma once
#include "Obfuscator.h"

/**
* Add random varible after void main and use it in random location in the code array
*/
class LineObfuscator : public Obfuscator {
private:
	const int MAX_NUMBER = 999; // max of the numbers to sum

	/**
	* find the index of 'void main'
	* @return index
	*/
	int findVoidMain(
		string* codeArray	// code array
	);

	/**
	* search for end section
	* @return end section
	*/
	int endSection(
		string* codeArry	// code array
		,int index			// start index
	);

	/**
	* random to numbers and set the formula
	* @return formula to push
	*/
	string formula(
		string varName	// varible name
	);

public:
	/**
	* c'tor
	*/
	LineObfuscator(
	);
	~LineObfuscator(
	);

	/**
	* execute method
	*/
	void obfuscate(
		string fileName		// input file name
	);
};
