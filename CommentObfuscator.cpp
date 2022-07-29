#include "CommentObfuscator.h"

CommentObfuscator::CommentObfuscator()
{
	// init random comments
	vComments.push_back("\t// print out the sum");
	vComments.push_back("\t// find index of substring inside string");
	vComments.push_back("\t// check if number is prime");
	vComments.push_back("\t// this is a comment");
	vComments.push_back("\t// debug");
	vComments.push_back("\t// TODO: insert new number");
}

CommentObfuscator::~CommentObfuscator()
{
}

void CommentObfuscator::obfuscate(string fileName)
{
	string* codeArray = this->parseFile(fileName); // get the code array from the file

	deleteComments(codeArray);	// delete all the comments
	writeComments(codeArray);	// push new comments

	// publish
	this->writeToFile(codeArray);
}

void CommentObfuscator::deleteComments(string* codeArray)
{
	for (int i = 0; i < this->getLineCount(); i++) 
	{
		int pos = codeArray[i].find("//");	// find the start position of start comment '//'

		if (pos != std::string::npos)
		{
			// delete the comment
			for (int j = pos; j < codeArray[i].length(); j++)
			{
				(codeArray[i])[j] = ' ';
			}

			// log
			cout << "Delete comment. index: " << i << endl;
		}
	}
}

void CommentObfuscator::writeComments(string*& codeArray)
{
	int mount = (int)(MIN_COMMENTS + rand() % (MAX_COMMENTS - MIN_COMMENTS + 1)); // randomize the mount of the comments to push

	for (int i = 0; i < mount; i++)
	{
		int index = (int)(rand() % (getLineCount() - 2)); // randomize the location of the comment to push
		
		// randomize comment
		string comment = vComments.at(
			(int)(rand() % (vComments.size()))
		);

		// push the comment into the code array
		this->insetAfter(codeArray, index, comment);

		// log
		cout << "Write comment. index: " << index << " comment: " << comment << endl;
	}
}