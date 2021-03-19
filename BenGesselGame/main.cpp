#include <cstdlib>
#include <string>
#include <unordered_map>

#include "functions.h"

using namespace std;

int main()
{
	const string fileName = "Scenes.txt";

	unordered_map<unsigned int, Scene> scenes;
	
	getScenes(fileName, scenes);

	unsigned int number = 100;

	while (number != 0)
	{
		Scene scene(scenes.find(number)->second);
		
		cout << scene;

		string choice;

		cin >> choice;

		number = scene.getChoices().find(choice)->second;
	}
	
	return EXIT_SUCCESS;
}