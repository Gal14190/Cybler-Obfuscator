#include "LineObfuscator.h"

LineObfuscator::LineObfuscator()
{
}
LineObfuscator::~LineObfuscator()
{
}

void LineObfuscator::obfuscate(string fileName)
{
	string* codeArray = this->parseFile(fileName); // get the code array from the file

	// get the location of the 'void main' the check if valid
	int mainIndex = findVoidMain(codeArray);
	if (mainIndex == -1)
	{
		cout << "void main() not found" << endl;
		return;
	}

	// generate varible name
	string varName = this->generateRandomVar();
	string varInit_str = "\tint " + varName + ";";

	// randomize two numbers and get formula
	string varCall_str = formula(varName);
	int randPosition = (int)(mainIndex + 2 + rand() % (endSection(codeArray, mainIndex + 2) - mainIndex + 1));	// randomize location
	
	this->insetAfter(codeArray, mainIndex + 1, varInit_str);// push the init varible after 'void main' location
	this->insetAfter(codeArray, randPosition, varCall_str);	// push the varible use

	// log
	cout << "Write init varible. Index: " << mainIndex + 1 << " Syntex: " << varInit_str << endl;
	cout << "Write use varible. Index: " << randPosition << " Syntex: " << varCall_str << endl;

	// publish
	this->writeToFile(codeArray);
}

int LineObfuscator::findVoidMain(string* codeArray)
{
	for (int i = 0; i < this->getLineCount(); i++)
	{
		if (codeArray[i].find("void main()") != std::string::npos)
			return i;
	}

	return -1;
}

int LineObfuscator::endSection(string* codeArry, int index)
{
	int i;
	for (i = index; i < this->getLineCount(); i++)
	{
		if (codeArry->at(i) == '}')
			return i;
	}

	return i - 1;
}

string LineObfuscator::formula(string varName)
{
	// randomize two numbers
	int num1 = (int)(1 + rand() % (MAX_NUMBER));
	int num2 = (int)(1 + rand() % (MAX_NUMBER));

	// varible = random number 1   +   random number 2
	return (
		"\t" 
		+ varName
		+ " = " 
		+ to_string(num1) 
		+ " + " 
		+ to_string(num2) 
		+ ";"
		);
}