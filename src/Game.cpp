#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(800u, 600u), "Battleship")
	, m_timeElapsed(sf::Time::Zero)
	, m_numOfTurns(0)
	, m_winner(nullptr)
	, m_state(GameStates::MainMenu)
	, m_customizeType(Type::None)
	, m_player1()
	, m_player2()
	, m_board()
{
	DebugMsg("In the MainMenu Screen");
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;

	while (m_window.isOpen())
	{
		processEvents();
		m_timeElapsed += clock.restart();
		while (m_timeElapsed > m_TIME_PER_FRAME)
		{
			m_timeElapsed -= m_TIME_PER_FRAME;
			update(m_TIME_PER_FRAME.asSeconds());
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event windowEvent;
	while (m_window.pollEvent(windowEvent))
	{
		switch (windowEvent.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			switch (windowEvent.key.code)
			{
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Game::update(const float & dt)
{
	// temporary variables to demonstrate functionality
	Ship tempShip;
	tempShip.setShape(Ship::Shape::Line);
	Crew tempCrew;
	tempCrew.setSize(2);
	Weapon tempWeapon;
	tempShip.setCrew(tempCrew);
	tempShip.setWeapon(tempWeapon);

	switch (m_state)
	{
	case GameStates::MainMenu:
		break;
	case GameStates::Customize:
		for (int i = 0; i < m_player1.getNumOfShips(); i++)
		{
			m_player1.setShip(tempShip, i);
		}
		break;
	case GameStates::Lobby:
		foundOpponent();
		m_state = GameStates::Gameplay;
		break;
	case GameStates::Gameplay:
		break;
	case GameStates::WinScreen:
		break;
	case GameStates::LossScreen:
		break;
	default:
		break;
	}
}

void Game::render()
{
	m_window.clear();
	m_window.display();
}

void Game::sendToLobby()
{
	m_state = GameStates::Lobby;
}

void Game::foundOpponent()
{
	m_player1.setOpponent(&m_player2);
	m_player2.setOpponent(&m_player1);
}

void Game::endTurn()
{
	m_numOfTurns++;
}

void Game::DebugMsg(const char * msg)
{
	std::cout << msg << std::endl;
}
