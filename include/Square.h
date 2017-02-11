#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square();
	~Square();

	// Getters

	const bool & getFired() const;
	const bool & getOccupied() const;

	// Setters

	void setFired(const bool &);
	void setOccupied(const bool &);

private:
	bool m_firedOn;
	bool m_occupiedOn;
};

#endif // !SQUARE_H