#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>
#include<iostream>

using namespace sf;

#define W 1200
#define H 700
#define PI 22/7
#define GRID_SIZE 25
#define AMPLITUDE 150
#define FREQUENCY 0.0001f

int speed = 170;

struct plot
{
	float x, y;
	Color color;
	plot(Color c)
	{
		x = 0;
		y = H/2;
		color = c;
	}
	void tick()
	{
		//y += 1;
		//x += .05f;

		//if (x >= W) x = 0;  if (x < 0) x = W - 1;
		//if (y >= H) y = 0;  if (y < 0) y = H - 1;
	}

};

void drawGrid(RenderTexture *g);

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(W, H), "Curves");
	window.setFramerateLimit(60);

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

	plot p1(Color::Red), p2(Color::Red), p3(Color::Blue);

	Sprite sprite;

	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
	t.clear();  t.draw(sBackground);

	RectangleShape rec;
	rec.setFillColor(Color::Yellow);
	rec.setSize(Vector2f(20,20));


	bool paused = false;
	float X = 0.00f;
	float angle = 0.00f;
	


	drawGrid(&t);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == sf::Event::MouseMoved)
			{
				std::cout << "Method 1: (" << e.mouseButton.x << ", " << e.mouseButton.y << ")\n";
				std::cout << "Method 2: (" << Mouse::getPosition(window).x << ", " << Mouse::getPosition(window).y << ")\n\n";
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter))
			paused = !paused;

		float Hz = (100*sin(X));

		
		

		if(paused){
			for (int i = 0; i < speed; i++)
			{
				//float x_axis = 4 * sqrt(X) * sin(2 * sin(3 * X + 10));
				//float y_axis = 4 * sqrt(X) * sin(X); 
				//float x_axis = cos(angle) * angle;
				//float y_axis = sin(angle) * (sin(3 * angle) + cos(angle));

				//float x_axis = cos(angle) * (sin(10 * angle) + cos(angle));
				//float y_axis = sin(angle) * (sin(10 * angle) + cos(angle)); 

				//float x_axis = X;
				//float y_axis = 0.0f;
				//
				//
				//for (int i = 1; i < 299; i++)
				//{
				//	y_axis += sin(i * X) / i;
				//	i++;
				//}
				//
				//x_axis = y_axis;

				
				float x_axis = X;
				float y_axis = sin(X);
				
				//y_axis +=  ((1/X)*sin((PI*X*X)/10));

				

				//rec.setPosition(p3.x + (AMPLITUDE * x_axis), p3.y - (AMPLITUDE * y_axis));
				//p1.tick();
				//p2.tick();
				p3.tick();

				CircleShape c(2);

				//c.setPosition(p1.x, p1.y - (AMPLITUDE * sin(X)));
				//c.setFillColor(p1.color);
				//t.draw(c);
				//
				//c.setPosition(p2.x + (AMPLITUDE * cos(X)), p2.y - (AMPLITUDE * sin(X)));
				//c.setFillColor(p2.color);
				//t.draw(c);
				//
				//c.setPosition(p3.x, p3.y - (AMPLITUDE * tan(X)));
				//c.setFillColor(p3.color);
				//t.draw(c);

				//c.setPosition(p3.x + (AMPLITUDE * cos(X) * X), p3.y + (AMPLITUDE * sin(X) * X));
				//c.setPosition(p3.x + (AMPLITUDE * cos(X) * tan(X)), p3.y + (AMPLITUDE * sin(X) * tan(X)));
				//c.setPosition(p3.x + (AMPLITUDE * cos(90 * X) * X), p3.y + (AMPLITUDE * sin(90 * X) * X));
				//c.setPosition(p3.x + (AMPLITUDE * X), p3.y - (AMPLITUDE * (((X * X * X) + 6 * (X * X) + 9 * X))));
				//c.setPosition(p3.x + (AMPLITUDE * X), p3.y - (AMPLITUDE * ((3 * (X * X * X * X) + 4 * (X * X * X)))));
				//c.setPosition(p3.x + (AMPLITUDE * X), p3.y - (AMPLITUDE * ((3 * pow(X, 4) + 4 * pow(X, 3)))));


				//c.setPosition(p3.x + (AMPLITUDE * cos(X)), p3.y - (AMPLITUDE * sin(X)));
				//c.setPosition(p3.x + (AMPLITUDE * (6 * cos(X) - 4 * cos(1.5 * X))), p3.y - (AMPLITUDE * (6 * sin(X) - 4 * sin(1.5 * X))));
				//c.setPosition(p3.x + (AMPLITUDE * (6 * cos(X) - 7 * cos(1.5 * X))), p3.y - (AMPLITUDE * (6 * sin(X) - 7 * sin(1.5 * X))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * (4 * exp(60 * ((tan(X)) / (cos(X)))))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * (4 * exp(angle * ((cos(X)* sin(X)) / (tan(X)))))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * (4 * exp(60 * ((cos(X)) / (tan(X)))))));
				//c.setPosition(p3.x + (AMPLITUDE * (4 * sqrt(X) * cos(X))), p3.y - (AMPLITUDE * (4 * sqrt(X) * sin(X))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * (4 * sqrt(2 * PI) * exp(-(X * X) / 2))));
				//c.setPosition(p3.x + (AMPLITUDE * (2 * sin(3 * X + 10))), p3.y - (AMPLITUDE * (4 * sin(X))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * ((4 * X) / (X * X + 6))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * ((pow(X, 3) + pow(X, 2) + X + 1) / (X))));
				//c.setPosition(p3.x + (AMPLITUDE * (X)), p3.y - (AMPLITUDE * sqrt((pow(X, 2) * (3 - X)) / (X + 1))));
				//c.setPosition(p3.x+(AMPLITUDE * ( X ) ), p3.y-(AMPLITUDE *  (( 8) )/(pow(X,2) + 4) ) );
				//c.setPosition(p3.x+(AMPLITUDE * ( X*X*X) ), p3.y-(AMPLITUDE *  (( 8) )/(pow(X,2) + 4) ) );
				c.setPosition(p3.x+(AMPLITUDE * x_axis ), p3.y-(AMPLITUDE * y_axis) );
				c.setFillColor(p3.color);
				t.draw(c);

				t.display();
				X += FREQUENCY;
				angle += FREQUENCY ;
				//if (angle > 2*PI +0.34f) paused = false;
			}
		}


		////// draw  ///////
		window.clear();
		
		window.draw(sprite);
		window.draw(rec);
		window.display();
	}

	return 0;
}


void drawGrid(RenderTexture *g)
{
	int x = 0, y = 0;
	for (int k = 0; k <= (int)(W / GRID_SIZE); k++)
	{

		CircleShape l(.5f);
		l.setFillColor(Color::Green);

		for (int j = 0; j < H; j++)
		{

			l.setPosition(x, y);
			g->draw(l);
			y++;
		}

		x += GRID_SIZE;
		y = 0;


	}

	x = 0, y = 0;
	for (int k = 0; k <= (int)(H / GRID_SIZE); k++)
	{

		CircleShape l(.5f);
		l.setFillColor(Color::Green);

		for (int j = 0; j < W; j++)
		{

			l.setPosition(x, y);
			g->draw(l);
			x++;
		}

		y += GRID_SIZE;
		x = 0;


	}
}