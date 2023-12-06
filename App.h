#pragma once
#include <SFML\Graphics.hpp>

class MainApp
{
    int WindowX, WindowY;
    sf::RenderWindow Window;

    bool bSymulation;
    float symulationSpeed;

public:
    MainApp();
    MainApp(int X, int Y);

    void RUN();
    void Events();
    void Symulation();
    void SetSymulationSpeed(float Speed) { symulationSpeed = Speed; };
};

