#pragma once
#include <SFML\Graphics.hpp>
#include <functional>

class Button
{
	sf::RenderWindow* window;

	std::function<void()> fun;

	// Pozycja.
	int X = 0, Y = 0;

    //Wysokoœæ, szerokoœæ.
	int height = 1, width = 1;

	sf::RectangleShape ButtonShape;

public:
	Button();
	Button(sf::RenderWindow* Window);

	void setButtonActon(std::function<void()> action) { fun = action; };

	void setSize(int Width, int Height);

	void setPosition(int x, int y);

	bool Event(sf::Event event);

	void draw();
};

