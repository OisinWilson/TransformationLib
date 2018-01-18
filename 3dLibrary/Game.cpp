#include "Game.h"
#include <iostream>

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library
//@Known Bugs:
// no known bugs

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "3D Lib Example" },
	m_exitGame{false},
	m_triangle{sf::Triangles}
{
	m_currentPosition[0] = { 200, 200,2 };
	m_currentPosition[1] = { 400, 200,2 };
	m_currentPosition[2] = { 300, 300,2 };

	for (int i = 0; i < 3; i++)
	{
		m_points[i] = sf::Vertex(static_cast<sf::Vector2f>(m_currentPosition[i]), RED);
		m_triangle.append(m_points[i]);
	}

	m_direction[0] = { 1,0,0 }; //right
	m_direction[1] = { -1,0,0 }; //left
	m_direction[2] = { 0,1,0 }; //down
	m_direction[3] = { 0,-1,0 }; //up
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}


void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}


void Game::update(sf::Time t_deltaTime)
{
	//translations
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{ //right
		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i];
			m_newPosition[i] = Matrix3::Matrix3::Translate(m_direction[0].ReturnX(), m_direction[0].ReturnY()) * m_newPosition[i];
			m_triangle[i].position = m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{ //left
		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i];
			m_newPosition[i] = Matrix3::Matrix3::Translate(m_direction[1].ReturnX(), m_direction[1].ReturnY()) * m_newPosition[i];
			m_triangle[i].position = m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{ //down
		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i];
			m_newPosition[i] = Matrix3::Matrix3::Translate(m_direction[2].ReturnX(), m_direction[2].ReturnY()) * m_newPosition[i];
			m_triangle[i].position = m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{ //up
		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i];
			m_newPosition[i] = Matrix3::Matrix3::Translate(m_direction[3].ReturnX(), m_direction[3].ReturnY()) * m_newPosition[i];
			m_triangle[i].position = m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i];
		}
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{ //rotate left
		m_centerPoint = { m_triangle[0].position.x + m_triangle[1].position.x + m_triangle[2].position.x ,
			m_triangle[0].position.y + m_triangle[1].position.y + m_triangle[2].position.y , 2 };
		m_centerPoint = { m_centerPoint * (1.0f / 3.0f) };

		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i] - m_centerPoint;
			m_newPosition[i] = Matrix3::Matrix3::RotationZ(-1) * m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i] + m_centerPoint;
			m_triangle[i].position = m_currentPosition[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{ //rotate right
		m_centerPoint = { m_triangle[0].position.x + m_triangle[1].position.x + m_triangle[2].position.x ,
			m_triangle[0].position.y + m_triangle[1].position.y + m_triangle[2].position.y , 2 };
		m_centerPoint = { m_centerPoint * (1.0f / 3.0f) };

		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i] - m_centerPoint;
			m_newPosition[i] = Matrix3::Matrix3::RotationZ(1) * m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i] + m_centerPoint;
			m_triangle[i].position = m_currentPosition[i];
		}
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{ //scale down
		m_centerPoint = { m_triangle[0].position.x + m_triangle[1].position.x + m_triangle[2].position.x ,
		m_triangle[0].position.y + m_triangle[1].position.y + m_triangle[2].position.y , 2 };
		m_centerPoint = { m_centerPoint * (1.0f / 3.0f) };

		for (int i = 0; i < 3; i++)
		{
			m_newPosition[i] = m_currentPosition[i] - m_centerPoint;
			m_newPosition[i] = Matrix3::Matrix3::Scale3D(90) * m_newPosition[i];
			m_currentPosition[i] = m_newPosition[i] + m_centerPoint;
			m_triangle[i].position = m_currentPosition[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{ //scale up
		{
			m_centerPoint = { m_triangle[0].position.x + m_triangle[1].position.x + m_triangle[2].position.x ,
				m_triangle[0].position.y + m_triangle[1].position.y + m_triangle[2].position.y , 2 };
			m_centerPoint = { m_centerPoint * (1.0f / 3.0f) };

			for (int i = 0; i < 3; i++)
			{
				m_newPosition[i] = m_currentPosition[i] - m_centerPoint;
				m_newPosition[i] = Matrix3::Matrix3::Scale3D(110) * m_newPosition[i];
				m_currentPosition[i] = m_newPosition[i] + m_centerPoint;
				m_triangle[i].position = m_currentPosition[i];
			}
		}
	}

	if (m_exitGame)
	{
		m_window.close();
	}
}


void Game::render()
{
	m_window.clear();
	m_window.draw(m_triangle);
	m_window.display();
}

