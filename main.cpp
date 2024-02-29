/*
Copyright[2021]
Justin Cheok
*/

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "Universe.h"
#include "CelestialBody.h"
#include <SFML/Audio.hpp>

using namespace std;
int main(int argc, char *argv[]) {
sf::VideoMode videoMode;
sf::RenderWindow window(sf::VideoMode(videoMode.getDesktopMode().height,
videoMode.getDesktopMode().height), "nbody");
Universe universe(videoMode.getDesktopMode().height/2);
// Background starfield.jpg
sf::Texture backgroundTexture;
sf::Vector2u TextureSize;
sf::Vector2u WindowSize;
// Load up starfielkd
if(!backgroundTexture.loadFromFile("nbody/starfield.jpg"))
return -1;
sf::Sprite background(backgroundTexture);
// Size
TextureSize = backgroundTexture.getSize();
WindowSize = window.getSize();
// Size Calc
float scaleX = (float) WindowSize.x / TextureSize.x;
float scaleY = (float) WindowSize.y / TextureSize.y;
background.setTexture(backgroundTexture);
background.setScale(scaleX, scaleY);
// Sound
sf::SoundBuffer buffer;
if(!buffer.loadFromFile("nbody/2001.wav"))
return -1;
// SOund play
sf::Sound sound;
sound.setBuffer(buffer);
sound.play();
float cT;
float dT;
float mT;
if(argc == 3) {
