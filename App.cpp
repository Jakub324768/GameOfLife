#include "App.h"

//MainApp Begin.

MainApp::MainApp()
{
    WindowX = 500;
    WindowY = 500;
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");

    bSymulation = false;
    symulationSpeed = 1.0f;

    startButton = Button(&Window);
    stopButton = Button(&Window);
    increaseTimeSpeedButton = Button(&Window);
    decreaseTimeSpeedButton = Button(&Window);
}

MainApp::MainApp(int X, int Y) : WindowX(X), WindowY(Y)
{
    Window.create(sf::VideoMode(WindowX, WindowY), "Game of Life");

    bSymulation = false;
    symulationSpeed = 1.0f;

    startButton = Button(&Window);
    stopButton = Button(&Window);
    increaseTimeSpeedButton = Button(&Window);
    decreaseTimeSpeedButton = Button(&Window);
}

void MainApp::RUN()
{
    sf::Clock SymulationClock;
    

    //Button
    sf::RectangleShape ButtonBoard(sf::Vector2f(150, WindowY));
    ButtonBoard.setPosition(WindowX - 150, 0);
    ButtonBoard.setFillColor(sf::Color(128, 128, 128));
    
    startButton.setSize(100, 100);
    startButton.setPosition(WindowX - 125, 50);
    startButton.setButtonActon([]() {std::cout << "Button" << std::endl; });
    startButton.GetButtonShape().setFillColor(sf::Color::Green);

    stopButton.setSize(100, 100);
    stopButton.setPosition(WindowX - 125, 200);
    stopButton.setButtonActon([]() {std::cout << "Button" << std::endl; });
    stopButton.GetButtonShape().setFillColor(sf::Color::Red);

    increaseTimeSpeedButton.setSize(100, 100);
    increaseTimeSpeedButton.setPosition(WindowX - 125, 350);
    increaseTimeSpeedButton.setButtonActon([]() {std::cout << "Button" << std::endl; });

    decreaseTimeSpeedButton.setSize(100, 100);
    decreaseTimeSpeedButton.setPosition(WindowX - 125, 600);
    decreaseTimeSpeedButton.setButtonActon([]() {std::cout << "Button" << std::endl; });

    while (Window.isOpen()) {
        Events();

        Window.clear(sf::Color::White);

        DrawLattice();

        //Button   
        Window.draw(ButtonBoard);
        startButton.draw();
        stopButton.draw();
        increaseTimeSpeedButton.draw();
        decreaseTimeSpeedButton.draw();

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
        stopButton.Event(event);
        increaseTimeSpeedButton.Event(event);
        decreaseTimeSpeedButton.Event(event);
    }
}

void MainApp::Symulation()
{

}

void MainApp::DrawLattice()
{
    const int size = 4 + 1;
    for (int i = 0; i < WindowX - 150; i += size)
    {
        sf::Vertex verticalLines[2] = {
            sf::Vertex(sf::Vector2f(i,0), sf::Color::Black),
            sf::Vertex(sf::Vector2f(i,WindowY), sf::Color::Black)
        };
        Window.draw(verticalLines, 2, sf::Lines);
    }

    for (int i = 0; i < WindowY; i += size)
    {
        sf::Vertex horizontalLines[2] = {
            sf::Vertex(sf::Vector2f(0,i), sf::Color::Black),
            sf::Vertex(sf::Vector2f(WindowX - 150,i), sf::Color::Black)
        };
        Window.draw(horizontalLines, 2, sf::Lines);
    }
}

//MainApp End.