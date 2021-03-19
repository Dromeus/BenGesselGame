#include <fstream>

#include "functions.h"

void getScenes(string fileName, unordered_map<unsigned int, Scene>& scenes)
{
	ifstream inData;

	inData.open(fileName);

	string line;

	while (inData.peek() != EOF)
	{		
		getline(inData, line);

		unsigned int number = stoul(line);

		list<string> text;

		while (line[line.size() - 1] != '|')
		{
			getline(inData, line);

			string line1;

			if (line[line.size() - 1] == '|')
				line1 = line.substr(0, line.size() - 1);
			else
				line1 = line;

			text.push_back(line1);
		}

		unordered_map<string, unsigned int> choices;

		getline(inData, line);

		unsigned int begin = 0;

		unsigned int end = line.find("|");

		while (line.find("|", begin) != string::npos)
		{
			string option = line.substr(begin, end - begin);

			begin = end + 1;

			if (line.find("|", begin) == string::npos)
				end = line.size();
			else
				end = line.find("|", begin);

			unsigned int value = static_cast<unsigned int>(stoul(line.substr(begin, end - begin)));

			choices.insert(make_pair(option, value));

			if (end == line.size())
				break;
			
			begin = end + 1;

			if (line.find("|", begin) == string::npos)
				end = line.size();
			else
				end = line.find("|", begin);
		}

		Scene scene(number, text, choices);

		scenes.insert(make_pair(number, scene));
	}

	inData.close();
}