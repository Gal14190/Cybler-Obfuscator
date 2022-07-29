#pragma once
#include "Obfuscator.h"
#include <vector>
#include <regex>

/**
* Change one of the varible name
*/
class VarObfuscator : public Obfuscator {
private:
	const string VAR_TYPE = "\tint";	// define varible type

	/**
	* find all the init integer in the code array
	* @return vector of indexs
	*/
	vector<int> findVars(
		string* codeArray	// code array
	);

	/**
	* change all the varibles name was chosen 
	*/
	void changeVarName(
		string*& codeArray	// code array
		,int index			// index of init varible
	);

public:
	/**
	* c'tor
	*/
	VarObfuscator(
	);
	~VarObfuscator(
	);

	/**
	* execute method
	*/
	void obfuscate(
		string fileName // input file name
	);
};