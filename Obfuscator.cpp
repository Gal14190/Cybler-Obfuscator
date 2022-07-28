#include "Obfuscator.h"

Obfuscator::Obfuscator()
{
	lineCount = 0;

	srand(time(0));
}
Obfuscator::~Obfuscator()
{}

string Obfuscator::generateRandomVar()
{
	// all validion chars can be uses
	const string VALID_CHARS = "_abcdefghijklmnopqrstuvwzABCDEFGHIJKLMNOPQRSTUVWZ1234567890";
	string result = "";

	int countChars, pos;

	// random number for how many chars the name of var will contain
	countChars = (int)(MIN_VAR_CHARS + rand() % (MAX_VAR_CHARS));

	for (int i = 0; i < countChars; i++)
	{
		pos = (int)(rand() % (VALID_CHARS.length()));	// random char

		// check if the first char (index 0) is not number 
		if (i == 0 && pos > 49)
			pos -= 10;

		result.push_back(VALID_CHARS[pos]);
	}

	return result;
}

string* Obfuscator::parseFile(string filename)
{
	ifstream externalFile(filename);	// input file
	string outLine;

	string* codeArray = new string[1];

	// read lines and push into the code array
	int i;
	for (i = 1; getline(externalFile, outLine); i++) 
		pushNewLine(codeArray, i, outLine);

	// close the file
	externalFile.close();

	return codeArray;
}

void Obfuscator::writeToFile(string* codeArray)
{
	ofstream externalFile(this->OUT);	// out file

	for(int i = 0; i < this->getLineCount(); i++)
		externalFile << codeArray[i] << endl;

	// close the file
	externalFile.close();
}

void Obfuscator::pushNewLine(string*& codeArray, int index, string value)
{
	setLineCount(getLineCount() + 1); // increase the number of the array

	// init the code array if it is the first collumn
	if (index == 1)
	{
		codeArray = new string[1];
		codeArray[0] = value;
		return;
	}

	string* new_pCodeArray = new string[index];
	for (int j = 0; j < index - 1; j++)
	{
		new_pCodeArray[j] = codeArray[j];
	}

	delete[] codeArray;
	codeArray = new string[index];

	new_pCodeArray[index - 1] = value;
	for (int j = 0; j < index; j++)
	{
		codeArray[j] = new_pCodeArray[j];
	}

	delete[] new_pCodeArray;
}

void Obfuscator::insetAfter(string*& codeArray, int index, string value)
{
	setLineCount(getLineCount() + 1); // increase the number of the array
	string* new_pCodeArray = new string[getLineCount()];
	
	for (int j = 0, i = 0; i < getLineCount() - 1; j++, i++)
	{
		if (j == index + 1)
		{
			new_pCodeArray[j] = value;
			j++;
		}

		new_pCodeArray[j] = codeArray[i];
	}

	delete[] codeArray;
	codeArray = new string[getLineCount()];

	for (int i = 0; i < getLineCount(); i++)
	{
		codeArray[i] = new_pCodeArray[i];
	}

	delete[] new_pCodeArray;
}

int Obfuscator::getLineCount()
{
	return this->lineCount;
}

void Obfuscator::setLineCount(int lineCount)
{
	this->lineCount = lineCount;
}