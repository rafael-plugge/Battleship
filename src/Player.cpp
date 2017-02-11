#include "Player.h"


Player::Player()
	: m_name("")
	, m_misses(0)
	, m_opponent(nullptr)
	, m_currentTurn(1)
	, m_numOfShips(s_MAX_SHIPS)
	, m_ships(nullptr)
{
	m_ships = new Ship[s_MAX_SHIPS]();
	for (unsigned i = 0u; i < m_numOfShips; i++)
	{
		m_ships[i] = Ship();
	}
}


Player::~Player()
{
	delete[] m_ships;
}

void Player::moveShip(const int & row, const int & col, const int & index)
{
	if (index < m_numOfShips)
	{
		m_ships[index].setRow(row);
		m_ships[index].setCol(col);
	}
}

void Player::playCurrentTurn()
{
}

void Player::targetSquare(const int & row, const int & col, const int & index)
{
	if (m_opponent != nullptr)
	{
		bool hitOpponent = false;
		int i = 0;
		for (; i < m_opponent->getNumOfShips(); i++)
		{
			const Ship & opShip = m_opponent->getShip(i);
			if (opShip.getRow() == row && opShip.getCol() == col)
			{
				hitOpponent = true;
				break;
			}
		}
		if (hitOpponent)
		{
			m_opponent->destroyShip(i);
		}
	}
}

void Player::hit(const int & index)
{
	destroyShip(index);
}

void Player::incTurn()
{
	m_currentTurn++;
}

void Player::destroyShip(const int & index)
{
	if (index < m_numOfShips && index >= 0)
	{
		Ship tempShips[s_MAX_SHIPS];
		int j = 0;
		for (int i = 0; i < m_numOfShips; i++)
		{
			if (i != index)
			{
				tempShips[j] = m_ships[i];
				j++;
			}
		}

		m_numOfShips--;

		delete[] m_ships;
		m_ships = new Ship[m_numOfShips]();

		for (int i = 0; i < m_numOfShips; i++)
		{
			m_ships[i] = tempShips[i];
		}

	}
}

const int & Player::getMisses() const
{
	return m_misses;
}

const Player * Player::getOpponent() const
{
	return m_opponent;
}

const int & Player::getCurrentTurn() const
{
	return m_currentTurn;
}

const int & Player::getNumOfShips() const
{
	return m_numOfShips;
}

const Ship & Player::getShip(const int & index) const
{
	return m_ships[index];
}

void Player::setMisses(const int & newMisses)
{
	m_misses = newMisses;
}

void Player::setOpponent(Player * newOpponent)
{
	m_opponent = newOpponent;
}

void Player::setCurrentTurn(const int & newTurn)
{
	m_currentTurn = newTurn;
}

void Player::setNumOfShips(const int & newNumShips)
{
	if (newNumShips <= s_MAX_SHIPS)
	{
		Ship tempShips[s_MAX_SHIPS];
		if (newNumShips < m_numOfShips)
		{
			for (int i = 0; i < newNumShips; i++)
			{
				tempShips[i] = m_ships[i];
			}
		}
		else if (newNumShips > m_numOfShips)
		{
			for (int i = 0; i < m_numOfShips; i++)
			{
				tempShips[i] = m_ships[i];
			}
		}
		m_numOfShips = newNumShips;

		delete[] m_ships;
		m_ships = new Ship[m_numOfShips]();

		for (int i = 0; i < m_numOfShips; i++)
		{
			m_ships[i] = tempShips[i];
		}
	}
}

void Player::setShip(const Ship & newShip, const int & index)
{
	if (index < m_numOfShips && index >= 0)
	{
		m_ships[index] = newShip;
	}
}
