#include "Button.h"

Button::Button()
{
	window = nullptr;
}

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
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.mouseButton.x >= X && event.mouseButton.x <= X + width && event.mouseButton.y >= Y && event.mouseButton.y <= Y + height)
			{
				fun();
				return true;
			}

		}
	}

	return false;
}

void Button::draw()
{
	window->draw(ButtonShape);
}