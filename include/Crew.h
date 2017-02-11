#ifndef CREW_H
#define CREW_H

#include "CrewMember.h"

class Crew
{
public:
	Crew();
	~Crew();

	// Getters

	const int & getSize() const;
	const CrewMember & getMember(const int &) const;

	// Setters

	void setSize(const int &);
	void setMember(const CrewMember &, const int &);

private:
	int m_size;
	CrewMember * m_members;
};

#endif // !CREW_H