#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <vector>

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
    void StartSymulaton() { bSymulation = true; };
    void StopSymulation() { bSymulation = false; };
    void IncreaseSymulationTimeSpeed() { if (symulationSpeed > 0.1f) symulationSpeed -= 0.1f; };
    void DecreaseSymulationTimeSpeedButton() { if (symulationSpeed < 1.0f) symulationSpeed += 0.1f; };

    void DrawLattice();

    int X0 = 0, Y0 = 0;
    int MoveSpeed = 1;
    void Symulation();

    std::vector<sf::Vector2i> cubeTab;
    bool mouseAddCube(int x, int y);
public:
    MainApp();
    MainApp(int X, int Y);

    void RUN();
    void Events();
    void SetSymulationSpeed(float Speed) { symulationSpeed = Speed; };
};

