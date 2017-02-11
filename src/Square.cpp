#include "Square.h"



Square::Square()
	: m_firedOn(false)
	, m_occupiedOn(false)
{
}


Square::~Square()
{
}

const bool & Square::getFired() const
{
	return m_firedOn;
}

const bool & Square::getOccupied() const
{
	return m_occupiedOn;
}

void Square::setFired(const bool & newFired)
{
	m_firedOn = newFired;
}

void Square::setOccupied(const bool & newOccupied)
{
	m_occupiedOn = newOccupied;
}
