#include "Button.h"

Button::Button()
{
	window = nullptr;
}

Button::Button(sf::RenderWindow* Window, ButtonType Type) : window(Window)
{
	ButtonShape.setFillColor(sf::Color::Blue);
	type = Type;
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
				return true;
			}

		}
	}

	return false;
}

void Button::draw()
{
	window->draw(ButtonShape);
 
	if (type != ButtonType::null)
	{
		sf::Vertex* vertex = nullptr;
		switch (type)
		{
		case ButtonType::play:
			vertex = new sf::Vertex[3];
			vertex[0] = sf::Vertex(sf::Vector2f(X+0.1*width, Y+0.1*height), sf::Color::Black);
			vertex[1] = sf::Vertex(sf::Vector2f(X+width-0.1*width, Y+0.5*height), sf::Color::Black);
			vertex[2] = sf::Vertex(sf::Vector2f(X+0.1*width, Y+height-0.1*height), sf::Color::Black);
			window->draw(vertex, 3, sf::Triangles);
			delete[] vertex;
			break;
		case ButtonType::pause:
			vertex = new sf::Vertex[8];
			vertex[0] = sf::Vertex(sf::Vector2f(X + 0.2 * width, Y + 0.1 * height), sf::Color::Black);
			vertex[1] = sf::Vertex(sf::Vector2f(X + 0.2 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[2] = sf::Vertex(sf::Vector2f(X + 0.45 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[3] = sf::Vertex(sf::Vector2f(X + 0.45 * width, Y + 0.1 * height), sf::Color::Black);
			vertex[4] = sf::Vertex(sf::Vector2f(X + 0.55 * width, Y + 0.1 * height), sf::Color::Black);
			vertex[5] = sf::Vertex(sf::Vector2f(X + 0.55 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[6] = sf::Vertex(sf::Vector2f(X + 0.8 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[7] = sf::Vertex(sf::Vector2f(X + 0.8 * width, Y + 0.1 * height), sf::Color::Black);
			window->draw(vertex, 8, sf::Quads);
			delete[] vertex;
			break;
		case ButtonType::up:
			vertex = new sf::Vertex[3];
			vertex[0] = sf::Vertex(sf::Vector2f(X + 0.1 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[1] = sf::Vertex(sf::Vector2f(X + width - 0.1 * width, Y + height - 0.1 * height), sf::Color::Black);
			vertex[2] = sf::Vertex(sf::Vector2f(X + 0.5 * width, Y + 0.1 * height), sf::Color::Black);
			window->draw(vertex, 3, sf::Triangles);
			delete[] vertex;
			break;
		case ButtonType::down:
			vertex = new sf::Vertex[3];
			vertex[0] = sf::Vertex(sf::Vector2f(X + 0.1 * width, Y + 0.1 * height), sf::Color::Black);
			vertex[1] = sf::Vertex(sf::Vector2f(X + width - 0.1 * width, Y + 0.1 * height), sf::Color::Black);
			vertex[2] = sf::Vertex(sf::Vector2f(X + 0.5 * width, Y + height - 0.1 * height), sf::Color::Black);
			window->draw(vertex, 3, sf::Triangles);
			delete[] vertex;
			break;
		default:
			break;
		}
		
	}
}