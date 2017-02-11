#include "CrewMember.h"



CrewMember::CrewMember()
	: m_name("")
{
}


CrewMember::~CrewMember()
{
}

const std::string & CrewMember::getName() const
{
	return m_name;
}

void CrewMember::setName(const std::string & newName)
{
	m_name = newName;
}
