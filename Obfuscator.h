#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
* Base class for Obfuscator method uses.
*/
class Obfuscator {
private:
	const int MAX_VAR_CHARS = 10;	// max of chars in varible to generate
	const int MIN_VAR_CHARS = 4;	// min of chars in varible to generate
	int lineCount;

public:
	const string OUT = "newCode.c";	// result file name

	/**
	* c'tor
	*/
	Obfuscator(
	);
	~Obfuscator(

	);

	/**
	* execute method
	*/
	virtual void obfuscate(
		string fileName		// input file name
	) = 0;

	/**
	* get the amount of lines in the code file
	* @return line count
	*/
	int getLineCount(
	);

	/**
	* set the amount of lines in the code file
	*/
	void setLineCount(
		int lineCount	// amount of lines
	);

protected:
	/**
	* generate random variable name
	* 
	* @return random name
	*/
	string generateRandomVar(
	);

	/**
	* read file content
	* 
	* @return file content
	*/
	string* parseFile(
		string filename		// file name to parse
	);

	/**
	* write array of string lines into the execute file
	*/
	void writeToFile(
		string* codeArray	// code array
	);

	/**
	* push new line into the code array
	*/
	void pushNewLine(
		string*& codeArray	// code array
		,int index			// the last index to push
		,string value		// value to push
	);

	/**
	* push new value to the code array after index
	*/
	void insetAfter(
		string*& codeArray	// code array
		,int index			// index to push after
		,string value		// value to push
	);
};
