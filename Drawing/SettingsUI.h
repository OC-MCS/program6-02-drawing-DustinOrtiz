
#pragma once
#include <SFML/Graphics.hpp>
#include "SettingsMgr.h"
#include <iostream>
using namespace std;
using namespace sf;

class SettingsUI // Sets left side of screen.
{
private:
	CircleShape redBtn; // Red button.
	CircleShape greenBtn; // Green button.
	CircleShape blueBtn; // Blue button.
	CircleShape circleBtn; // Circle buttton.
	RectangleShape squareBtn; // Square button.
	SettingsMgr *sMgr; // Settings.
public:

	//==================================
	// SettingUI: Sets default settings.
	// Parameters:
	// mgr: Setting manager.
	// Return Type: None.
	//==================================

	SettingsUI(SettingsMgr *mgr)
	{
		sMgr = mgr;

		Vector2f pos(80, 70);
		redBtn.setPosition(pos);
		redBtn.setRadius(25);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);

		Vector2f pos2(80, 140);
		greenBtn.setPosition(pos2);
		greenBtn.setRadius(25);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		Vector2f pos3(80, 210);
		blueBtn.setPosition(pos3);
		blueBtn.setRadius(25);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);

		Vector2f ciPos(80, 350);
		circleBtn.setPosition(ciPos);
		circleBtn.setRadius(25);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		Vector2f sqPos(83, 420);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(45, 45));
	}

	//==============================
	// handleMouseUp: Handles input.
	// Parameters:
	// mouse: Input.
	// Return Type: None.
	//==============================

	void handleMouseUp(Vector2f mouse)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Red);
		}

		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Green);
		}

		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::Blue);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentShape(CIRCLE);
		}

		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentShape(SQUARE);
		}
	}

	//==============================
	// die: Exits program if needed.
	// Parameters:
	// msg: Message.
	// Return Type: None.
	//==============================

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	//==============================
	// draw: Draws buttons changing.
	// Parameters:
	// win: Window to draw changes.
	// Return Type: None.
	//==============================

	void draw(RenderWindow& win)
	{
		Font font;

		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text color("Selected Color", font, 25);
		color.setPosition(30, 25);

		Text shape("Selected Shape", font, 25);
		shape.setPosition(30, 300);

		RectangleShape line;
		Vector2f linePos(250, 0);
		line.setPosition(linePos);
		line.setOutlineColor(Color::White);
		line.setOutlineThickness(2);
		line.setSize(Vector2f(0, 600));
		line.setFillColor(Color::White);

		if (sMgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else
		{
			redBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}
		else
		{
			greenBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else
		{
			blueBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else
		{
			circleBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}
		else
		{
			squareBtn.setFillColor(Color::Transparent);
		}

		win.draw(color);
		win.draw(shape);
		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(blueBtn);
		win.draw(circleBtn);
		win.draw(squareBtn);
		win.draw(line);
	}
};