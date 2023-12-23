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
    startButton.GetButtonShape().setFillColor(sf::Color::Green);

    stopButton.setSize(100, 100);
    stopButton.setPosition(WindowX - 125, 200);
    stopButton.GetButtonShape().setFillColor(sf::Color::Red);

    increaseTimeSpeedButton.setSize(100, 100);
    increaseTimeSpeedButton.setPosition(WindowX - 125, 350);

    decreaseTimeSpeedButton.setSize(100, 100);
    decreaseTimeSpeedButton.setPosition(WindowX - 125, 600);


    sf::RectangleShape cube(sf::Vector2f(4, 4));
    cube.setFillColor(sf::Color::Green);

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

        for (auto T : cubeTab)
        {
            cube.setPosition((T.x - X0) * 5, (T.y - Y0) * 5);
            Window.draw(cube);
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
        else if (startButton.Event(event))
        {
            StartSymulaton();
        }
        else if (stopButton.Event(event))
        {
            StopSymulation();
        }
        else if (increaseTimeSpeedButton.Event(event))
        {
            IncreaseSymulationTimeSpeed();
        }
        else if (decreaseTimeSpeedButton.Event(event))
        {
            DecreaseSymulationTimeSpeedButton();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                Window.clear();
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                Y0 += MoveSpeed;
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                Y0 -= MoveSpeed;
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                X0 += MoveSpeed;
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                X0 -= MoveSpeed;
            }
            else if (event.key.code == sf::Keyboard::Add)
            {
                if(MoveSpeed < 100)
                MoveSpeed++;
            }
            else if (event.key.code == sf::Keyboard::Subtract)
            {
                if (MoveSpeed > 1)
                    MoveSpeed--;
            }
        }
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