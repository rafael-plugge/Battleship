#include "Crew.h"



Crew::Crew()
	: m_size(3)
{
}

Crew::Crew(const Crew & copy)
	: m_size(copy.m_size)
{
}


Crew::~Crew()
{
}

const int & Crew::getSize() const
{
	return m_size;
}

void Crew::setSize(const int & newSize)
{
	if (newSize > 0)
	{
		m_size = newSize;
	}
}