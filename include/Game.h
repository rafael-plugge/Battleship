#ifndef GAME_H
#define GAME_H

// SFML Graphics library
#include "SFML\Graphics.hpp"

// standard debug library
#include <iostream>

// Project classes
#include "Player.h"
#include "Ship.h"
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void processEvents();
	void update(const float &);
	void render();

	void sendToLobby();
	void foundOpponent();
	void endTurn();

	void DebugMsg(const char *);
	void initialize();

	// game states
	enum class GameStates
	{
		MainMenu, Customize, Gameplay, Lobby, WinScreen, LossScreen
	};

	// what type to customize
	enum class Type
	{
		None, Ship, Crew, Weapon
	};

	// time for each update call 
	const sf::Time m_TIME_PER_FRAME = sf::seconds(1.0f / 60.0f);

	// Main Game Window where all draw calls are ran
	sf::RenderWindow m_window;

	// used to track time since last update call
	sf::Time m_timeElapsed;

	// current total number of turns
	int m_numOfTurns;

	// pointer to the winner
	const Player * m_winner;

	// current state of the game
	GameStates m_state;

	// what type to customize
	Type m_customizeType;

	// players
	Player m_player1, m_player2;

	// game board
	Board m_board;

};
#endif // !GAME_H