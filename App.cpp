#include "App.h"

MainApp::MainApp()
{
    WindowX = 500;
    WindowY = 500;
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
}

MainApp::MainApp(int X, int Y) : WindowX(X), WindowY(Y)
{
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
}

void MainApp::RUN()
{
    while (Window.isOpen()) {

        Events();

        Window.clear(sf::Color::White);
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