#ifndef H_functions
#define H_functions

#include <string>
#include <unordered_map>

#include "Scene.h"

using namespace std;

void getScenes(string fileName, unordered_map<unsigned int, Scene>& scenes);

#endif