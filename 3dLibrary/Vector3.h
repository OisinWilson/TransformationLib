#pragma once

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library
//@Known Bugs:
// no known bugs

#include<iostream>
#include <cmath>
#include <string>
#include "SFML\Graphics.hpp"

class Vector3
{
public:

	// constructors
	Vector3();
	Vector3(double x1, double y1, double z1);

	// destructor
	~Vector3();

	// return values
	double ReturnX();
	double ReturnY();
	double ReturnZ();

	// set values
	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

	// math functions
	double Length();
	double LengthSquared();
	void Normalise();

	// operators
	Vector3 operator +(Vector3 V1) const;
	
	//Vector3D operator + (Vector3D t_vector3D) const;

	Vector3 operator -(Vector3 V1) const;
	Vector3 operator -() const;

	double operator *(Vector3 V1) const;
	Vector3 operator *(double k) const;
	Vector3 operator *(float k) const;
	Vector3 operator *(int k) const;

	Vector3 operator ^(Vector3 V1) const;

	// string
	std::string ToString();

	operator sf::Vector2i() { return sf::Vector2i(static_cast<int>(m_x), static_cast<int>(m_y)); };
	operator sf::Vector2f() { return sf::Vector2f(static_cast<float>(m_x), static_cast<float>(m_y)); };
	operator sf::Vector2u() { return sf::Vector2u(static_cast<unsigned int>(m_x), static_cast<unsigned int>(m_y)); };
	operator sf::Vector3i() { return sf::Vector3i(static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_z)); };
	operator sf::Vector3f() { return sf::Vector3f(static_cast<float>(m_x), static_cast<float>(m_y), static_cast<float>(m_z)); };

private:

	// variables
	double m_x;
	double m_y;
	double m_z;
};