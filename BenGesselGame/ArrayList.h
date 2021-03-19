#ifndef H_arraylist
#define H_arraylist

#include <iostream>

using namespace std;

template <class T>
class ArrayList
{
public:
	ArrayList() { m_length = 0; m_ptr = nullptr; }
	ArrayList(unsigned int length, T* ptr);
	ArrayList(const ArrayList<T>& arrayList);
	~ArrayList() { delete[] m_ptr; }
	ArrayList<T>& operator=(const ArrayList<T>& arrayList);
	T& operator[](unsigned int index) { return m_ptr[index]; }
	const T& operator[](unsigned int index) const { return m_ptr[index]; }
	unsigned int getLength() const { return m_length; }
	void setArray(unsigned int length, T* ptr);
	void print(ostream& ostr = cout) const;
	friend ostream& operator<<(ostream& ostr, const ArrayList<T>& arrayList) { arrayList.print(ostr); return ostr; }
private:
	unsigned int m_length;
	T* m_ptr;
};

template <class T>
ArrayList<T>::ArrayList(unsigned int length, T* ptr)
{
	m_length = length;

	m_ptr = new T[m_length];

	for (unsigned int i = 0; i < m_length; i++)
		m_ptr[i] = ptr[i];
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayList)
{
	m_length = arrayList.m_length;

	m_ptr = new T[m_length];

	for (unsigned int i = 0; i < m_length; i++)
		m_ptr[i] = arrayList.m_ptr[i];
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayList)
{
	if (this != &arrayList)
	{
		delete[] m_ptr;
		
		m_length = arrayList.m_length;

		m_ptr = new T[m_length];

		for (unsigned int i = 0; i < m_length; i++)
			m_ptr[i] = arrayList.m_ptr[i];
	}

	return *this;
}

template <class T>
void ArrayList<T>::setArray(unsigned int length, T* ptr)
{
	delete[] m_ptr;

	m_length = length;

	for (unsigned int i = 0; i < m_length; i++)
		m_ptr[i] = ptr[i];
}

template <class T>
void ArrayList<T>::print(ostream& ostr) const
{
	ostr << "[";

	for (unsigned int i = 0; i < m_length - 1; i++)
		ostr << m_ptr[i] << " ";

	ostr << m_ptr[m_length - 1] << "]";
}

#endif