#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(800u, 600u), "Battleship")
{
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
		default:
			break;
		}
	}
}

void Game::update(const float & dt)
{
	switch (m_state)
	{
	case Game::GameStates::Customize:
		break;
	case Game::GameStates::Lobby:
		break;
	case Game::GameStates::Gameplay:
		break;
	case Game::GameStates::WinScreen:
		break;
	case Game::GameStates::LossScreen:
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
	
}

void Game::endTurn()
{
}
