#ifndef H_scene
#define H_scene

#include <string>
#include <unordered_map>

#include "ArrayList.h"

using namespace std;

class Scene
{
public:
	Scene() { m_number = 0; }
	Scene(unsigned int number, const list<string>& script, const unordered_map<string, unsigned int>& choices) { m_number = number; m_script = script; m_choices = choices; }
	Scene(const Scene& scene) { m_number = scene.m_number; m_script = scene.m_script; m_choices = scene.m_choices; }
	Scene& operator=(const Scene& scene);
	bool operator==(const Scene& scene) const;
	bool operator!=(const Scene& scene) const { return !operator==(scene); }
	bool operator<(const Scene& scene) const;
	bool operator>(const Scene& scene) const;
	bool operator<=(const Scene& scene) const { return !operator>(scene); }
	bool operator>=(const Scene& scene) const { return !operator<(scene); }
	unsigned int getNumber() const { return m_number; }
	list<string>& getScript() { return m_script; }
	unordered_map<string, unsigned int>& getChoices() { return m_choices; }
	void setNumber(unsigned int number) { m_number = number; }
	void setScript(list<string>& script) { m_script = script; }
	void setChoices(unordered_map<string, unsigned int>& choices) { m_choices = choices; }
	void print(ostream& ostr = cout) const;
	friend ostream& operator<<(ostream& ostr, const Scene& scene) { scene.print(ostr); return ostr; }
private:
	unsigned int m_number;
	list<string> m_script;
	unordered_map<string, unsigned int> m_choices;
};

#endif