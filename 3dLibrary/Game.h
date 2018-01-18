#ifndef GAME
#define GAME

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library
//@Known Bugs:
// no known bugs

#include <SFML/Graphics.hpp>
#include "Matrix3.h"

const sf::Color RED{ 128, 0, 0, 255 };

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

	bool m_exitGame; // exiting game

	sf::VertexArray m_triangle;
	sf::Vertex m_points[3];

	Vector3 m_currentPosition[3];
	Vector3 m_newPosition[3];

	Vector3 m_direction[4];

	Vector3 m_centerPoint;
};

#endif // !GAME

