#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
#include <iostream>

class MainApp
{
    int WindowX, WindowY;
    sf::RenderWindow Window;

    bool bSymulation;
    float symulationSpeed;

    Button startButton;
    Button stopButton;
    Button increaseTimeSpeedButton;
    Button decreaseTimeSpeedButton;

    void DrawLattice();
public:
    MainApp();
    MainApp(int X, int Y);

    void RUN();
    void Events();
    void Symulation();
    void SetSymulationSpeed(float Speed) { symulationSpeed = Speed; };
};

