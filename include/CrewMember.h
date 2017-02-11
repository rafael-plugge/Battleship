#ifndef CREW_MEMBER_H
#define CREW_MEMBER_H

#include <string>

class CrewMember
{
public:
	CrewMember();
	~CrewMember();

	// Getters

	const std::string & getName() const;

	// Setters

	void setName(const std::string &);

private:
	std::string m_name;
};

#endif // !CREW_MEMBER_H