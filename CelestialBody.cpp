#include "CelestialBody.h"

using namespace std;

CelestialBody::CelestialBody(double scale, double radius){
	this-> xPos = 0.0000;
	this-> xVel = 0.0000;
	this-> yPos = 0.0000;
	this-> yVel = 0.0000;
	this-> mass = 0.0000;
	this-> texture = nullptr;
	this-> sprite = nullptr; 
	this-> scale = scale;
	this-> radius = radius;
}

CelestialBody::CelestialBody(const CelestialBody &celestialBody){
	this-> xPos = celestialBody.xPos;
	this-> xVel = -celestialBody.xVel;
	this-> yPos = -celestialBody.yPos;
	this-> yVel = -celestialBody.yVel;
	this-> mass = celestialBody.mass;
	this-> scale = celestialBody.scale;
	this-> radius = celestialBody.radius;
	this-> filename = celestialBody.filename;
	
	this-> texture = unique_ptr < sf::Texture>(new sf::Texture());
	
	if(this-> mass < 0){
		throw invalid_argument("mass cannot be negative");
	}
	
	if(!texture-> loadFromFile(("nbody/" + filename))){
		throw invalid_argument(filename + " file doesn't exist");
	}
	
	
	this-> sprite = unique_ptr < sf::Sprite > (new sf::Sprite(*this-> texture));
	this-> sprite-> setOrigin(sf::Vector2f((float) this-> texture-> getSize().x / 2, (float) this-> texture-> getSize().y / 2));
}
CelestialBody::CelestialBody(){

}


void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	if(this-> sprite != nullptr){
		this-> sprite-> setPosition((this-> xPos / this-> scale) + this->radius, this-> yPos / this-> scale + this-> radius);
		target.draw(*this-> sprite);
	}
}

istream &operator >> (istream &input, CelestialBody &body){

	input >> body.xPos >> body.yPos >> body.xVel >> body.yVel >> body.mass >> body.filename;
	return input;
}


//Pairwise Forc
void CelestialBody::pairwise(unique_ptr<CelestialBody> &b1, unique_ptr<CelestialBody> &b2){
	
	//Position
	double dx = b2-> xPos - b1-> xPos;
	double dy = b2-> yPos - b1-> yPos;
	
	double r = sqrt((dx * dx) + (dy * dy));
	double f = (gravity * b1-> mass * b2-> mass) / (r * r);
	
	b1-> force.x += f * dx / r;
	b2-> force.x += f* dx / r;
	b1-> force.y += f * dy / r;
	b2-> force.y += f * dy / r;
		
}


void CelestialBody::printBody(){

	cout << this-> xPos << " " << this-> yPos << " " << this-> xVel << " " << this-> yVel << " " << this-> mass << " " << this-> filename << endl;
	
}
		
