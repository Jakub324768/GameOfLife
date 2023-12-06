#include "Button.h"

Button::Button() {};

Button::Button(sf::RenderWindow* Window) : window(Window)
{
	ButtonShape.setFillColor(sf::Color::Blue);
}

void Button::setSize(int Width, int Height)
{
	if (Width > 0 && Height > 0)
	{
		width = Width;
		height = Height;

		ButtonShape.setSize(sf::Vector2f(width, height));
	}
}

void Button::setPosition(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		X = x;
		Y = y;

		ButtonShape.setPosition(X, Y);
	}
}

bool Button::Event(sf::Event event)
{


	return false;
}

void Button::draw()
{
	window->draw(ButtonShape);
}