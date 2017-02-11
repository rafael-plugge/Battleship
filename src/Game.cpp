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

	initialize();
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;

	clock.restart();
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
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			case sf::Keyboard::Space:
				if (m_state == GameStates::WinScreen || m_state == GameStates::LossScreen)
				{
					DebugMsg("\n\tRestarting !\n");
					initialize();
				}
				m_state = GameStates::Lobby;
				break;
			case sf::Keyboard::A:
				m_player1.targetSquare(0, 0);
				m_player2.targetSquare(0, 0);
				break;
			case sf::Keyboard::S:
				m_player1.targetSquare(1, 1);
				m_player1.targetSquare(1, 2);
				m_player1.targetSquare(1, 3);
				m_player1.targetSquare(1, 4);
				break;
			case sf::Keyboard::D:
				m_player2.targetSquare(1, 1);
				m_player2.targetSquare(2, 1);
				m_player2.targetSquare(3, 1);
				m_player2.targetSquare(4, 1);
				break;
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
		DebugMsg("\nControls:\n A = both players miss\n S = player1 destroys player2\n D = player2 destroys player1");
		break;
	case GameStates::Gameplay:

		if (m_player1.getNumOfShips() <= 0)
		{
			m_winner = m_player1.getOpponent();
		}
		else if (m_player2.getNumOfShips() <= 0)
		{
			m_winner = m_player2.getOpponent();
		}
		if (m_winner == nullptr)
		{
		}
		else if (m_winner == &m_player1)
		{
			m_state = GameStates::WinScreen;
			DebugMsg("Player1 is the victor");
			DebugMsg("Player2 is the loser");
		}
		else if (m_winner == &m_player2)
		{
			m_state = GameStates::LossScreen;
			DebugMsg("Player1 is the loser");
			DebugMsg("Player2 is the victor");
		}
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

void Game::initialize()
{
	m_winner = nullptr;
	m_player1 = Player();
	m_player2 = Player();

	Ship tempShip;
	tempShip.setRow(1); tempShip.setCol(1);
	m_player1.setShip(tempShip, 0);
	tempShip.setRow(2); tempShip.setCol(1);
	m_player1.setShip(tempShip, 1);
	tempShip.setRow(3); tempShip.setCol(1);
	m_player1.setShip(tempShip, 2);
	tempShip.setRow(4); tempShip.setCol(1);
	m_player1.setShip(tempShip, 3);

	tempShip.setRow(1); tempShip.setCol(1);
	m_player2.setShip(tempShip, 0);
	tempShip.setRow(1); tempShip.setCol(2);
	m_player2.setShip(tempShip, 1);
	tempShip.setRow(1); tempShip.setCol(3);
	m_player2.setShip(tempShip, 2);
	tempShip.setRow(1); tempShip.setCol(4);
	m_player2.setShip(tempShip, 3);
}
