#pragma once
#include <SFML\Graphics.hpp>

enum class ButtonType : unsigned char
{
	null,
	play,
	pause,
	up,
	down
};

class Button
{
	sf::RenderWindow* window;

	// Pozycja.
	int X = 0, Y = 0;

    //Wysokoœæ, szerokoœæ.
	int height = 1, width = 1;

	sf::RectangleShape ButtonShape;

	ButtonType type = ButtonType::null;

public:
	Button();
	Button(sf::RenderWindow* Window, ButtonType Type = ButtonType::null);

	void setSize(int Width, int Height);

	void setPosition(int x, int y);

	bool Event(sf::Event event);

	void draw();

	sf::RectangleShape& GetButtonShape() { return ButtonShape; };
};

