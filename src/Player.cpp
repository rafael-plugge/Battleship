#include "Player.h"



Player::Player()
	: m_name("")
	, m_misses(0)
	, m_opponent(nullptr)
	, m_currentTurn(1)
	, m_numOfShips(4)
	, m_ships{ Ship() }
{
}


Player::~Player()
{
}

void Player::moveShip(const int & row, const int & col, const int & index)
{
	
}

void Player::playCurrentTurn()
{
}

void Player::targetSquare(const int & row, const int & col, const int & index)
{
}

void Player::hit(const int & index)
{
}

void Player::incTurn()
{
	m_currentTurn++;
}

void Player::destroyShip(const int & index)
{
}

const int & Player::getMisses() const
{
	// TODO: insert return statement here
}

const Player * Player::getOpponent() const
{
	return nullptr;
}

const int & Player::getCurrentTurn() const
{
	// TODO: insert return statement here
}

const int & Player::getNumOfShips() const
{
	// TODO: insert return statement here
}

const Ship & Player::getShip(const int &) const
{
	// TODO: insert return statement here
}

void Player::setMisses(const int &)
{
}

void Player::setOpponent(const Player *)
{
}

void Player::setCurrentTurn(const int &)
{
}

void Player::setNumOfShips(const int &)
{
}

void Player::setShip(const Ship &, const int &)
{
}
