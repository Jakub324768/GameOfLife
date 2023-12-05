#include "App.h"

MainApp::MainApp()
{
    WindowX = 500;
    WindowY = 500;
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
    bSymulation = false;
    symulationSpeed = 1.0f;
}

MainApp::MainApp(int X, int Y) : WindowX(X), WindowY(Y)
{
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
    bSymulation = false;
    symulationSpeed = 1.0f;
}

void MainApp::RUN()
{
    sf::Clock SymulationClock;

    while (Window.isOpen()) {

        Events();

        Window.clear(sf::Color::Black);

        //Button
        {
            sf::RectangleShape ButtonBoard(sf::Vector2f(300, WindowY));
            ButtonBoard.setPosition(WindowX - 300, 0);
            ButtonBoard.setFillColor(sf::Color(128, 128, 128));
            Window.draw(ButtonBoard);
        }

        if (bSymulation && SymulationClock.getElapsedTime().asSeconds() >= symulationSpeed)
        {
            SymulationClock.restart();
            Symulation();
        }

        Window.display();
    }
}

void MainApp::Events()
{
    sf::Event event;
    while (Window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            Window.close();
        }
    }
}

void MainApp::Symulation()
{

}