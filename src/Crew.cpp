#include "Crew.h"



Crew::Crew()
	: m_size(3)
{
	m_members = new CrewMember[m_size]();
}


Crew::~Crew()
{
	delete[] m_members;
}

const int & Crew::getSize() const
{
	return m_size;
}

const CrewMember & Crew::getMember(const int & index) const
{
	return m_members[index];
}

void Crew::setSize(const int & newSize)
{
	if (newSize > 0)
	{
		CrewMember * tempCrew = new CrewMember[newSize]();
		int tempSize;
		if (m_size < newSize)
		{
			tempSize = m_size;
		}
		else
		{
			tempSize = newSize;
		}
		for (int i = 0; i < tempSize; i++)
		{
			tempCrew[i] = m_members[i];
		}

		delete[] m_members;

		m_members = &tempCrew[0];

		m_size = newSize;
	}
}

void Crew::setMember(const CrewMember & newMember, const int & index)
{
	if (index < m_size)
	{
		m_members[index] = newMember;
	}
}
