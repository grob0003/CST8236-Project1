#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TransformNode.h"

int main(int argc, char* argv)
{
	float scrWdth = 1500.0f;
	float scrHght = 900.0f;
	sf::RenderWindow window(sf::VideoMode((int)scrWdth, (int)scrHght), "Project1", sf::Style::Titlebar | sf::Style::Close);

	/*SOUND DOESNT WORK??? error 0xc000007b for me locally*/

	/*sf::SoundBuffer buffer;
	buffer.loadFromFile("res/easy-joy.ogg");
	sf::Sound sound(buffer);*/

	/*Texture*/
	sf::Texture bgTexture;
	bgTexture.loadFromFile("res/rain.jpg");
	bgTexture.setRepeated(true);

	/* Non-tiling sprites */
	sf::Sprite nonTilingRainSprite;
	nonTilingRainSprite.setTexture(bgTexture);

	sf::Sprite nonTilingSecondRainSprite;
	nonTilingSecondRainSprite.setTexture(bgTexture);

	/* Tiling sprite */
	sf::Sprite tilingRainSprite;
	tilingRainSprite.setTexture(bgTexture);
	tilingRainSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

	sf::IntRect backgroundRect = tilingRainSprite.getTextureRect();
	float secondTimer = 0.0f; // elapsed time per second.
	float movementSpeed = 25.0f; // scrolling movement speed.

	/*MIDDLE WINDMILL*/
	sf::Texture midTexture;
	midTexture.loadFromFile("res/greenB.png");
	midTexture.setRepeated(true);
	sf::Texture midBodyTexture;
	midBodyTexture.loadFromFile("res/greenW.png");
	midBodyTexture.setRepeated(true);

	/*LEFT WINDMILL*/
	sf::Texture leftTexture;
	leftTexture.loadFromFile("res/redB.png");
	leftTexture.setRepeated(true);
	sf::Texture leftBodyTexture;
	leftBodyTexture.loadFromFile("res/redW.png");
	leftBodyTexture.setRepeated(true);

	/*RIGHT WINDMILL*/
	sf::Texture rightTexture;
	rightTexture.loadFromFile("res/purpleB.png");
	rightTexture.setRepeated(true);
	sf::Texture rightBodyTexture;
	rightBodyTexture.loadFromFile("res/purpleW.png");
	rightBodyTexture.setRepeated(true);

	/*Make the shapes*/
	/*MIDDLE WINDMILL*/
	sf::CircleShape midShape;
	midShape.setRadius(1);

	sf::ConvexShape midBodyShape;
	midBodyShape.setPointCount(5);

	midBodyShape.setPoint(0, sf::Vector2f(0, 200));
	midBodyShape.setPoint(1, sf::Vector2f(20, 30));
	midBodyShape.setPoint(2, sf::Vector2f(50, 5));
	midBodyShape.setPoint(3, sf::Vector2f(80, 30));
	midBodyShape.setPoint(4, sf::Vector2f(100, 200));

	sf::ConvexShape midAnchorShape;
	midAnchorShape.setPointCount(8);

	midAnchorShape.setPoint(0, sf::Vector2f(-15, 0));
	midAnchorShape.setPoint(1, sf::Vector2f(-3, 3));
	midAnchorShape.setPoint(2, sf::Vector2f(0, 15));
	midAnchorShape.setPoint(3, sf::Vector2f(3, 3));
	midAnchorShape.setPoint(4, sf::Vector2f(15, 0));
	midAnchorShape.setPoint(5, sf::Vector2f(3, -3));
	midAnchorShape.setPoint(6, sf::Vector2f(0, -15));
	midAnchorShape.setPoint(7, sf::Vector2f(-3, -3));

	sf::RectangleShape midBladeShape1(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape midBladeShape2(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape midBladeShape3(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape midBladeShape4(sf::Vector2<float>(30.0f, 120.0f));

	/*LEFT WINDMILL*/
	sf::CircleShape leftShape;
	leftShape.setRadius(1);

	sf::ConvexShape leftBodyShape;
	leftBodyShape.setPointCount(5);

	leftBodyShape.setPoint(0, sf::Vector2f(0, 200));
	leftBodyShape.setPoint(1, sf::Vector2f(20, 30));
	leftBodyShape.setPoint(2, sf::Vector2f(50, 5));
	leftBodyShape.setPoint(3, sf::Vector2f(80, 30));
	leftBodyShape.setPoint(4, sf::Vector2f(100, 200));

	sf::ConvexShape leftAnchorShape;
	leftAnchorShape.setPointCount(8);

	leftAnchorShape.setPoint(0, sf::Vector2f(-15, 0));
	leftAnchorShape.setPoint(1, sf::Vector2f(-3, 3));
	leftAnchorShape.setPoint(2, sf::Vector2f(0, 15));
	leftAnchorShape.setPoint(3, sf::Vector2f(3, 3));
	leftAnchorShape.setPoint(4, sf::Vector2f(15, 0));
	leftAnchorShape.setPoint(5, sf::Vector2f(3, -3));
	leftAnchorShape.setPoint(6, sf::Vector2f(0, -15));
	leftAnchorShape.setPoint(7, sf::Vector2f(-3, -3));

	sf::RectangleShape leftBladeShape1(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape leftBladeShape2(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape leftBladeShape3(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape leftBladeShape4(sf::Vector2<float>(30.0f, 120.0f));

	/*RIGHT WINDMILL*/
	sf::CircleShape rightShape;
	rightShape.setRadius(1);

	sf::ConvexShape rightBodyShape;
	rightBodyShape.setPointCount(5);

	rightBodyShape.setPoint(0, sf::Vector2f(0, 200));
	rightBodyShape.setPoint(1, sf::Vector2f(20, 30));
	rightBodyShape.setPoint(2, sf::Vector2f(50, 5));
	rightBodyShape.setPoint(3, sf::Vector2f(80, 30));
	rightBodyShape.setPoint(4, sf::Vector2f(100, 200));

	sf::ConvexShape rightAnchorShape;
	rightAnchorShape.setPointCount(8);

	rightAnchorShape.setPoint(0, sf::Vector2f(-15, 0));
	rightAnchorShape.setPoint(1, sf::Vector2f(-3, 3));
	rightAnchorShape.setPoint(2, sf::Vector2f(0, 15));
	rightAnchorShape.setPoint(3, sf::Vector2f(3, 3));
	rightAnchorShape.setPoint(4, sf::Vector2f(15, 0));
	rightAnchorShape.setPoint(5, sf::Vector2f(3, -3));
	rightAnchorShape.setPoint(6, sf::Vector2f(0, -15));
	rightAnchorShape.setPoint(7, sf::Vector2f(-3, -3));

	sf::RectangleShape rightBladeShape1(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape rightBladeShape2(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape rightBladeShape3(sf::Vector2<float>(30.0f, 120.0f));
	sf::RectangleShape rightBladeShape4(sf::Vector2<float>(30.0f, 120.0f));

	/*Colour the shapes*/
	/*MIDDLE WINDMILL*/
	midShape.setFillColor(sf::Color::White);
	midBodyShape.setTexture(&midBodyTexture);
	midAnchorShape.setFillColor(sf::Color::Black);

	midBladeShape1.setTexture(&midTexture);
	midBladeShape2.setTexture(&midTexture);
	midBladeShape3.setTexture(&midTexture);
	midBladeShape4.setTexture(&midTexture);
	midBladeShape1.setRotation(0);
	midBladeShape2.setRotation(90);
	midBladeShape3.setRotation(180);
	midBladeShape4.setRotation(270);

	/*LEFT WINDMILL*/
	leftShape.setFillColor(sf::Color::White);
	leftBodyShape.setTexture(&leftBodyTexture);
	leftAnchorShape.setFillColor(sf::Color::Black);

	leftBladeShape1.setTexture(&leftTexture);
	leftBladeShape2.setTexture(&leftTexture);
	leftBladeShape3.setTexture(&leftTexture);
	leftBladeShape4.setTexture(&leftTexture);
	leftBladeShape1.setRotation(0);
	leftBladeShape2.setRotation(90);
	leftBladeShape3.setRotation(180);
	leftBladeShape4.setRotation(270);

	/*RIGHT WINDMILL*/
	rightShape.setFillColor(sf::Color::White);
	rightBodyShape.setTexture(&rightBodyTexture);
	rightAnchorShape.setFillColor(sf::Color::Black);

	rightBladeShape1.setTexture(&rightTexture);
	rightBladeShape2.setTexture(&rightTexture);
	rightBladeShape3.setTexture(&rightTexture);
	rightBladeShape4.setTexture(&rightTexture);
	rightBladeShape1.setRotation(0);
	rightBladeShape2.setRotation(90);
	rightBladeShape3.setRotation(180);
	rightBladeShape4.setRotation(270);

	bool keyHeld = false;

	bool growing = true;

	/*Setting positions and origins*/
	/*MIDDLE WINDMILL*/
	sf::Vector2f midOrigPos(scrWdth / 2.0f, scrHght / 2.0f);
	midShape.setPosition(midOrigPos);
	midBodyShape.setOrigin(50.0f, 30.0f);
	midBladeShape1.setOrigin(-2.5f, -2.5f);
	midBladeShape2.setOrigin(-2.5f, -2.5f);
	midBladeShape3.setOrigin(-2.5f, -2.5f);
	midBladeShape4.setOrigin(-2.5f, -2.5f);


	/*LEFT WINDMILL*/
	sf::Vector2f leftOrigPos(scrWdth / 4.0f, scrHght / 2.0f);
	leftShape.setPosition(leftOrigPos);
	leftBodyShape.setOrigin(50.0f, 30.0f);
	leftBladeShape1.setOrigin(-2.5f, -2.5f);
	leftBladeShape2.setOrigin(-2.5f, -2.5f);
	leftBladeShape3.setOrigin(-2.5f, -2.5f);
	leftBladeShape4.setOrigin(-2.5f, -2.5f);


	/*RIGHT WINDMILL*/
	sf::Vector2f rightOrigPos((scrWdth / 4.0f) * 3.0f, scrHght / 2.0f);
	rightShape.setPosition(rightOrigPos);
	rightBodyShape.setOrigin(50.0f, 30.0f);
	rightBladeShape1.setOrigin(-2.5f, -2.5f);
	rightBladeShape2.setOrigin(-2.5f, -2.5f);
	rightBladeShape3.setOrigin(-2.5f, -2.5f);
	rightBladeShape4.setOrigin(-2.5f, -2.5f);


	/*TransformNode*/
	/*MIDDLE WINDMILL*/
	TransformNode mid(&midShape);
	TransformNode midBody(&midBodyShape);
	TransformNode midAnchor(&midAnchorShape);
	TransformNode midBlade1(&midBladeShape1);
	TransformNode midBlade2(&midBladeShape2);
	TransformNode midBlade3(&midBladeShape3);
	TransformNode midBlade4(&midBladeShape4);

	/*LEFT WINDMILL*/
	TransformNode left(&leftShape);
	TransformNode leftBody(&leftBodyShape);
	TransformNode leftAnchor(&leftAnchorShape);
	TransformNode leftBlade1(&leftBladeShape1);
	TransformNode leftBlade2(&leftBladeShape2);
	TransformNode leftBlade3(&leftBladeShape3);
	TransformNode leftBlade4(&leftBladeShape4);

	/*RIGHT WINDMILL*/
	TransformNode right(&rightShape);
	TransformNode rightBody(&rightBodyShape);
	TransformNode rightAnchor(&rightAnchorShape);
	TransformNode rightBlade1(&rightBladeShape1);
	TransformNode rightBlade2(&rightBladeShape2);
	TransformNode rightBlade3(&rightBladeShape3);
	TransformNode rightBlade4(&rightBladeShape4);

	/*Adding*/
	/*MIDDLE WINDMILL*/
	midAnchor.AddChild(&midBlade1);
	midAnchor.AddChild(&midBlade2);
	midAnchor.AddChild(&midBlade3);
	midAnchor.AddChild(&midBlade4);
	midBody.AddChild(&midAnchor);
	mid.AddChild(&midBody);

	/*LEFT WINDMILL*/
	leftAnchor.AddChild(&leftBlade1);
	leftAnchor.AddChild(&leftBlade2);
	leftAnchor.AddChild(&leftBlade3);
	leftAnchor.AddChild(&leftBlade4);
	leftBody.AddChild(&leftAnchor);
	left.AddChild(&leftBody);

	/*RIGHT WINDMILL*/
	rightAnchor.AddChild(&rightBlade1);
	rightAnchor.AddChild(&rightBlade2);
	rightAnchor.AddChild(&rightBlade3);
	rightAnchor.AddChild(&rightBlade4);
	rightBody.AddChild(&rightAnchor);
	right.AddChild(&rightBody);

	sf::Clock deltaTime;
	int choice = 0;
	bool upDown = false;
	bool leftRight = false;
	bool keyRelease = false;
	sf::Vector2i origPos;

	while (window.isOpen())
	{

		float elaspedTime = deltaTime.restart().asSeconds();

		sf::Event sfEvent;
		while (window.pollEvent(sfEvent))
		{
			if (sfEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (sfEvent.type == sf::Event::KeyReleased)
			{
				keyRelease = true;
			}
			else if (sfEvent.type == sf::Event::KeyPressed)
			{

				switch (sfEvent.key.code){
				case sf::Keyboard::Num1:
					choice = 1;
					break;
				case sf::Keyboard::Num2:
					choice = 2;
					break;
				case sf::Keyboard::Num3:
					choice = 3;
					break;
				case sf::Keyboard::Num4:
				case sf::Keyboard::A:
					choice = 4;
					break;
				default:
					keyHeld = false;
					break;
				}

			}
			else if (sfEvent.type == sf::Event::MouseMoved)
			{
				//sound.play();

				float deltaX = float(sfEvent.mouseMove.x) - origPos.x;
				float deltaY = float(sfEvent.mouseMove.y) - origPos.y;

				if (deltaX != 0){
					leftRight = true;
					upDown = false;
				}
				if (deltaY != 0){
					upDown = true;
					leftRight = false;
				}
			}
			origPos = sf::Mouse::getPosition(window);

		}



		float angleAmount = 360.0f;
		float totRot = angleAmount * elaspedTime;


			switch (choice){
			case 1:
				if (upDown){
					leftShape.setPosition(midShape.getPosition().x, midShape.getPosition().y);
					leftShape.setOrigin(midShape.getPosition().x / 2, midShape.getPosition().y / 2);
					leftBodyShape.setPosition(-leftShape.getOrigin().x, -leftShape.getOrigin().y);
					leftBodyShape.rotate(-totRot);
					leftShape.rotate(totRot);
				}
				if (leftRight && !upDown){
					leftBodyShape.rotate(-totRot*2);
				}


				break;
			case 2:
				if (upDown){
					midShape.setPosition(leftShape.getPosition().x, leftShape.getPosition().y);
					midShape.setOrigin(leftShape.getPosition().x / 2, leftShape.getPosition().y / 2);
					midBodyShape.setPosition(-midShape.getOrigin().x, -midShape.getOrigin().y);
					midBodyShape.rotate(-totRot);
					midShape.rotate(totRot);
				}
				if (leftRight && !upDown){
					midBodyShape.rotate(-totRot*2);
				}
				break;
			case 3:
				if (upDown){
					rightShape.setPosition(midShape.getPosition().x, midShape.getPosition().y);
					rightShape.setOrigin(midShape.getPosition().x / 2, midShape.getPosition().y / 2);
					rightBodyShape.setPosition(-rightShape.getOrigin().x, -rightShape.getOrigin().y);
					rightBodyShape.rotate(-totRot);
					rightShape.rotate(totRot);
				}
				if (leftRight && !upDown){
					rightBodyShape.rotate(-totRot*2);
				}
				break;
			case 4:
				if (keyRelease){
					midShape.setOrigin(0, 0);
					midShape.setRotation(0);
					midBodyShape.setPosition(0, 0);
					midBodyShape.setRotation(0);
					midShape.setPosition(midOrigPos);
					leftShape.setOrigin(0, 0);
					leftShape.setRotation(0);
					leftBodyShape.setPosition(0, 0);
					leftBodyShape.setRotation(0);
					leftShape.setPosition(leftOrigPos);
					rightShape.setOrigin(0, 0);
					rightShape.setRotation(0);
					rightBodyShape.setPosition(0, 0);
					rightBodyShape.setRotation(0);
					rightShape.setPosition(rightOrigPos);
					keyRelease = false;
				}
				if (upDown){
					leftShape.setOrigin(midShape.getPosition().x / 2, midShape.getPosition().y / 2);
					leftBodyShape.setPosition(-leftShape.getOrigin().x, -leftShape.getOrigin().y);
					leftBodyShape.rotate(-totRot);
					leftShape.rotate(totRot);
					midShape.setOrigin(leftShape.getPosition().x / 2, leftShape.getPosition().y / 2);
					midBodyShape.setPosition(-midShape.getOrigin().x, -midShape.getOrigin().y);
					midBodyShape.rotate(-totRot);
					midShape.rotate(totRot);
					rightShape.setOrigin(midShape.getPosition().x / 2, midShape.getPosition().y / 2);
					rightBodyShape.setPosition(-rightShape.getOrigin().x, -rightShape.getOrigin().y);
					rightBodyShape.rotate(-totRot);
					rightShape.rotate(totRot);
				}
				if (leftRight && !upDown){
					leftBodyShape.rotate(-totRot * 2);
					midBodyShape.rotate(-totRot * 2);
					rightBodyShape.rotate(-totRot * 2);
				}
				break;
			default:
				break;
			}

		leftRight = false;
		upDown = false;

		leftAnchorShape.rotate(totRot);
		midAnchorShape.rotate(totRot);
		rightAnchorShape.rotate(totRot);


		/*background movements*/
		secondTimer += elaspedTime;

		sf::IntRect deltaRect = backgroundRect;
		deltaRect.height = backgroundRect.height + (int)(movementSpeed * secondTimer);
		tilingRainSprite.setTextureRect(deltaRect);

		if (secondTimer > 0.1f)
		{
			secondTimer -= 0.1f;
			backgroundRect.top += (int)movementSpeed;

			if (backgroundRect.top >= (float)bgTexture.getSize().y) {
				backgroundRect.top -= bgTexture.getSize().y;
			}
		}


		float textureHeight = (float)bgTexture.getSize().y;
		if (nonTilingRainSprite.getPosition().y + textureHeight <= 0.0f){
			nonTilingRainSprite.setPosition(0.0f, nonTilingRainSprite.getPosition().y + textureHeight);
		}

		float combinedY = nonTilingRainSprite.getPosition().y + bgTexture.getSize().y;
		nonTilingSecondRainSprite.setPosition(nonTilingRainSprite.getPosition().x, combinedY);


		// do stuff.
		window.clear();

		//draw stuff
		window.draw(tilingRainSprite);

		mid.Draw(&window);
		left.Draw(&window);
		right.Draw(&window);

		window.display();
	}

	return 0;
}

