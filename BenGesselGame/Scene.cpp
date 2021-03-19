#include "Scene.h"

Scene& Scene::operator=(const Scene& scene)
{
	if (this != &scene)
	{
		m_number = scene.m_number;
		m_script = scene.m_script;
		m_choices = scene.m_choices;
	}

	return *this;
}

bool Scene::operator==(const Scene& scene) const
{
	if (m_number == scene.m_number)
		return true;
	return false;
}

bool Scene::operator<(const Scene& scene) const
{
	if (m_number < scene.m_number)
		return true;
	return false;
}

bool Scene::operator>(const Scene& scene) const
{
	if (m_number > scene.m_number)
		return true;
	return false;
}

void Scene::print(ostream& ostr) const
{
	list<string>::const_iterator scriptIterator = m_script.begin();
	
	for (unsigned int i = 0; i < m_script.size(); i++)
		ostr << *scriptIterator++ << endl;
}