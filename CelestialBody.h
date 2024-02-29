#ifndef CELESTIALBODY
#define CELESTIALBODY

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const float gravity = 6.67E-11;

class CelestialBody: public sf::Drawable{
	
	
	public:
	CelestialBody(double scale, double radius);
	CelestialBody(const CelestialBody &celestialBody);
	CelestialBody();
	void printBody();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	friend istream &operator >>(istream &input, CelestialBody &body);
	
	sf::Vector2f getVelocity(){
		return sf::Vector2f(xVel, yVel);
	};
	
	void setXVel(double value){
		xVel = value;
	};
	void setYVel(double value){
		yVel = value;
	};
	
	sf::Vector2f getPosition(){
		return sf::Vector2f(xPos, yPos);
	};
	
	void setXpos(double value){
		xPos = value;
	};
	
	void setYPos(double value){
		yPos = value;
	};
	
	double getMass(){
		return this->mass;
	}
	
	sf::Vector2f getForces(){
		return this-> force;
	};
	
	void clearForces(){
		this-> force = sf::Vector2f(0,0);
	};
	
	static void pairwise(unique_ptr<CelestialBody> &b1, unique_ptr<CelestialBody> &b2);
	
	
	private:
	double xPos, yPos, xVel, yVel;
	double mass, scale, radius;
	string filename;
	unique_ptr<sf::Texture> texture;
	unique_ptr<sf::Sprite> sprite;
	sf::Vector2f force;
	
	
	
	};
	
#endif
