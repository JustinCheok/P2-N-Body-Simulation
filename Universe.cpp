 /*
Copyright[2021]
Justin Cheok
*/

#include "Universe.h"
using namespace std;
void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const {
for(int i = 0; i < this-> numPlanets; i++) {
  this-> bodies.at(i)-> draw(target, states);
}
}
// universe window
Universe::Universe(float radiusScreen) {
this->bodies.clear();
cin >> this-> numPlanets;
cin >> this->universeSize;
this-> scale = universeSize / radiusScreen;
CelestialBody temp((double) this-> scale, (double) radiusScreen);
for(int i = 0; i < this-> numPlanets; ++i) {
  cin >> temp;
this->bodies.push_back(unique_ptr <CelestialBody>(new CelestialBody(temp)));
}
}

void Universe::leapFrog(float *cT, float dT) {
double accelerationX;
double accelerationY;
for(int k = 0; k < (int) this-> bodies.size(); ++k) {
this->bodies.at(k)-> clearForces();
}
for(int i = 0; i < (int) this-> bodies.size(); ++i) {
for(int j = 0 + i; j< (int) this-> bodies.size(); ++j) {
if(i != j) {
  CelestialBody::pairwise(bodies.at(i), bodies.at(j));
}
}
accelerationX = this-> bodies.at(i)-> getForces().x /
this-> bodies.at(i)-> getMass();
accelerationY = this-> bodies.at(i)-> getForces().y /
this-> bodies.at(i)-> getMass();
this-> bodies.at(i)->
setXVel(this-> bodies.at(i)-> getVelocity().x + (dT * accelerationX));
this-> bodies.at(i)-> setYVel(this-> bodies.at(i)->
getVelocity().y + (dT * accelerationY));
this->bodies.at(i)->setXpos(this-> bodies.at(i)->
getPosition().x +
(dT * this-> bodies.at(i)->getVelocity().x));
this-> bodies.at(i)-> setYPos(this-> bodies.at(i)-> getPosition().y +
(dT * this-> bodies.at(i)-> getVelocity().y));
}
*cT += dT;
}
void Universe::printUniverse() {
cout << this->numPlanets << endl << this-> universeSize <<
endl;
for(int i = 0; i < this->numPlanets; ++i) {
this->bodies.at(i)->printBody();
}
}
