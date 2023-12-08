#include "App.h"

MainApp::MainApp()
{
    WindowX = 500;
    WindowY = 500;
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
    bSymulation = false;
    symulationSpeed = 1.0f;
    startButton = Button(&Window);
}

MainApp::MainApp(int X, int Y) : WindowX(X), WindowY(Y)
{
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");
    bSymulation = false;
    symulationSpeed = 1.0f;
    startButton = Button(&Window);
}

void MainApp::RUN()
{
    sf::Clock SymulationClock;

    //Button
    sf::RectangleShape ButtonBoard(sf::Vector2f(300, WindowY));
    ButtonBoard.setPosition(WindowX - 300, 0);
    ButtonBoard.setFillColor(sf::Color(128, 128, 128));
    
    startButton.setSize(200, 100);
    startButton.setPosition(WindowX - 250, 100);
    startButton.setButtonActon([]() {std::cout << "Button" << std::endl; });

    while (Window.isOpen()) {

        Events();

        Window.clear(sf::Color::Black);

        //Button   
        Window.draw(ButtonBoard);
        startButton.draw();
        

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
        startButton.Event(event);
    }
}

void MainApp::Symulation()
{

}