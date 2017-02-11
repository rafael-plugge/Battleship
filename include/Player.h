#ifndef PLAYER_H
#define PLAYER_H

// standard library
// required for name
#include <string>

#include "Ship.h"

class Player
{
public:
	Player();
	~Player();
	void moveShip(const int &, const int &, const int &);
	void playCurrentTurn();
	void targetSquare(const int &, const int &, const int &);
	void hit(const int &);
	void incTurn();
	void destroyShip(const int &);

	/**/
	// Getters
	/**/

	const int & getMisses() const;
	const Player * getOpponent() const;
	const int & getCurrentTurn() const;
	const int & getNumOfShips() const;
	const Ship & getShip(const int &) const;

	/**/
	// Setters
	/**/

	void setMisses(const int &);
	void setOpponent(const Player *);
	void setCurrentTurn(const int &);
	void setNumOfShips(const int &);
	void setShip(const Ship &, const int &);

private:
	std::string m_name;
	int m_misses;
	Player * m_opponent;
	int m_currentTurn;
	int m_numOfShips;
	Ship m_ships[4];
};

#endif // !PLAYER_H