#include "Ship.h"



Ship::Ship(const int & row, const int & col)
	: m_size(4)
	, m_shape(Shape::Line)
	, m_row(row)
	, m_col(col)
	, m_crew()
	, m_weapon()
{
}


Ship::~Ship()
{
}

const int & Ship::getSize() const
{
	return m_size;
}

const Ship::Shape & Ship::getShape() const
{
	return m_shape;
}

const int & Ship::getRow() const
{
	return m_row;
}

const int & Ship::getCol() const
{
	return m_col;
}

const Crew & Ship::getCrew() const
{
	return m_crew;
}

const Weapon & Ship::getWeapon() const
{
	return m_weapon;
}

void Ship::setSize(const int & newSize)
{
	m_size = newSize;
}

void Ship::setShape(const Shape & newShape)
{
	m_shape = newShape;
}

void Ship::setRow(const int & newRow)
{
	m_row = newRow;
}

void Ship::setCol(const int & newCol)
{
	m_col = newCol;
}

void Ship::setCrew(const Crew & newCrew)
{
	m_crew = newCrew;
}

void Ship::setWeapon(const Weapon & newWeapon)
{
	m_weapon = newWeapon;
}
