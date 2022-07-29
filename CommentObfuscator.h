#pragma once
#include "Obfuscator.h"
#include <vector>

/**
* Delete all the comments and push new random comments
*/
class CommentObfuscator : public Obfuscator {
private:
	const int MAX_COMMENTS = 5; // max comments to push
	const int MIN_COMMENTS = 2; // min comments to push

	vector<string> vComments;

	/**
	* delete all the comments in the code array
	*/
	void deleteComments(
		string* codeArray	// code array
	);

	/**
	* write random comments into the code array
	*/
	void writeComments(
		string*& codeArray	// code array
	);
public:
	/**
	* c'tor
	*/
	CommentObfuscator(
	);
	~CommentObfuscator(
	);

	/**
	* execute method
	*/
	void obfuscate(
		string fileName	// input file name
	);
};
