#ifndef CREW_H
#define CREW_H

class Crew
{
public:
	Crew();
	Crew(const Crew &);
	~Crew();

	// Getters

	const int & getSize() const;

	// Setters

	void setSize(const int &);

private:
	int m_size;
};

#endif // !CREW_H