#include "VarObfuscator.h"

VarObfuscator::VarObfuscator()
{
}
VarObfuscator::~VarObfuscator()
{
}

void VarObfuscator::obfuscate(string fileName)
{
	string* codeArray = this->parseFile(fileName);	// get the code array from the file

	// search for all the init integer varibles 
	vector<int> vVars = findVars(codeArray);

	// choose random varible
	int index = (int)(rand() % (vVars.size()));

	// chenge all the vaibles name
	changeVarName(codeArray, vVars.at(index));

	// publish
	this->writeToFile(codeArray);
}

vector<int> VarObfuscator::findVars(string* codeArray)
{
	vector<int> v;

	for (int i = 0; i < this->getLineCount(); i++)
	{
		if (codeArray[i].find(var_type) != std::string::npos)
			v.push_back(i);
	}

	return v;
}

void VarObfuscator::changeVarName(string*& codeArray, int index)
{
	string varName;
	string newVarName = this->generateRandomVar();	// randomize new varible name

	smatch s;
	regex_search(codeArray[index], s, regex("int [a-zA-Z_]+"));	// search for original varible name
	
	varName = s.str(0).erase(0, 4); // erase the init varible 'int '
	
	// run over all the code. begin from the init varible
	for (int i = index; i < this->getLineCount(); i++)
	{
		string code = codeArray[i];

		// stop if its end of secetion
		if (code.find("}") != std::string::npos)
			return;

		// replace the name of the varible name in the code line
		// check if the line contain the varible name
		if (regex_match(code.begin(), code.end(), regex("((.*)"+varName+"(.*))")))
		{
			// check if the varible name contain inside quotation marks
			if (regex_match(code.begin(), code.end(), regex("((.*)\"(.*)" + varName + "(.*)\"(.*))")))
				codeArray[i] = regex_replace(code, regex("(" + varName + ")(?=(?:[^\"]|\"[^\"]*\")*$)"), newVarName);
			else
				codeArray[i] = regex_replace(code, regex(varName), newVarName);

			// log
			cout << "Change var. Name: \"" << varName << "\" New Name: \"" << newVarName << "\" Index: " << i <<  endl;
		}
	}
}