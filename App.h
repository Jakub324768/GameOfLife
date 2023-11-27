#include <SFML\Graphics.hpp>

class MainApp
{
    int WindowX, WindowY;
    sf::RenderWindow Window;
    
public:
    MainApp();
    MainApp(int X,int Y);

    void RUN();
    void Events();
};