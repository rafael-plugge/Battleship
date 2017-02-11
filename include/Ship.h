#ifndef SHIP_H
#define SHIP_H

#include "Crew.h"
#include "Weapon.h"

class Ship
{
public:
	Ship(const int & row = 0, const int & col = 0);
	Ship(const Ship &);
	~Ship();

	enum class Shape
	{
		Rectangle, Line
	};

	// Getters

	const int & getSize() const;
	const Shape & getShape() const;
	const int & getRow() const;
	const int & getCol() const;
	const Crew & getCrew() const;
	const Weapon & getWeapon() const;

	// Setters

	void setSize(const int &);
	void setShape(const Shape &);
	void setRow(const int &);
	void setCol(const int &);
	void setCrew(const Crew &);
	void setWeapon(const Weapon &);

private:
	int m_size;
	Shape m_shape;
	int m_row;
	int m_col;
	Crew m_crew;
	Weapon m_weapon;
};

#endif // !SHIP_H