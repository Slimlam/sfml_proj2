#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//g++ -Wall -o bin/"%e" "%f" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

class Ball {
	 
	public:

		Ball(int rad, int x, int y, int r, int g, int b);
		sf::CircleShape C;
		void move(float x, float y);
		void update();

	private:

};

int main()
{
	Ball ball(50, 100, 30, 250, 0, 0);

	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML Test");
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
				window.close();
				break;

				default:
				break;
			}
		}
	ball.update();
	window.clear(sf::Color::Black);
	window.draw(ball.C);
	window.display();
	}
	return 0;
}

Ball::Ball(int rad, int x, int y, int r, int g, int b)
{
	C.setRadius(rad);
	C.setFillColor(sf::Color(r,g,b));
	C.setPosition(x,y);

}

void Ball::update(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		C.move(-1,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		C.move(1,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		C.move(0,1);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		C.move(0,-1);
	}
}
