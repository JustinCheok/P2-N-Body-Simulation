/*
Copyright[2021]
Justin Cheok
*/

#ifndef UNIVERSE
#define UNIVERSE

#include "CelestialBody.h"
#include <iostream>
#include <utility>
#include <vector>
#include <memory>

class Universe: public sf:: Drawable {
public:
Universe(float radiusScreen);
void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
void leapFrog(float *cT, float dT);
void printUniverse();

private:
int numPlanets;
float scale;
float universeSize;
vector<std::unique_ptr<CelestialBody>> bodies;
};
#endif
