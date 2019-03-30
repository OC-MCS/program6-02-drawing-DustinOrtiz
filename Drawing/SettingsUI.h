
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
	RectangleShape clearSelectedBtn; // clear selected button.
	RectangleShape clearCanvasBtn; // Clear canvas button.
	ShapeMgr *clearCanvas; //
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

		Vector2f pos(80, 60);
		redBtn.setPosition(pos);
		redBtn.setRadius(25);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);

		Vector2f pos2(80, 130);
		greenBtn.setPosition(pos2);
		greenBtn.setRadius(25);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		Vector2f pos3(80, 200);
		blueBtn.setPosition(pos3);
		blueBtn.setRadius(25);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);

		Vector2f ciPos(80, 305);
		circleBtn.setPosition(ciPos);
		circleBtn.setRadius(25);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		Vector2f sqPos(83, 375);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(45, 45));

		Vector2f clPos(50, 480);
		clearSelectedBtn.setPosition(clPos);
		clearSelectedBtn.setOutlineColor(Color::White);
		clearSelectedBtn.setOutlineThickness(2);
		clearSelectedBtn.setSize(Vector2f(125, 25));
		clearSelectedBtn.setFillColor(Color::Transparent);

		Vector2f clPos2(50, 560);
		clearCanvasBtn.setPosition(clPos2);
		clearCanvasBtn.setOutlineColor(Color::White);
		clearCanvasBtn.setOutlineThickness(2);
		clearCanvasBtn.setSize(Vector2f(125, 25));
		clearCanvasBtn.setFillColor(Color::Transparent);
	}

	//==============================
	// handleMouseUp: Handles input.
	// Parameters:
	// mouse: Input.
	// Return Type: None.
	//==============================

	void handleMouseUp(Vector2f mouse, ShapeMgr *mgr)
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

		if (clearSelectedBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::White);
			sMgr->setCurrentShape(CLEARSELECTED);
		}

		if (clearCanvasBtn.getGlobalBounds().contains(mouse))
		{
			sMgr->setCurrentColor(Color::White);
			sMgr->setCurrentShape(CLEARCANVAS);
			clearCanvas->clearShapes(mgr);
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
		Font font; // Font for text.

		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text color("Selected Color", font, 25); // Selected color text.
		color.setPosition(30, 15);

		Text shape("Selected Shape", font, 25); // Selected shape text.
		shape.setPosition(30, 260);

		Text clearSelected("Clear Selected", font, 25); // Clear selected text.
		clearSelected.setPosition(30, 435);

		Text clearCanvas("Clear Canvas", font, 25); // Clear canvas text.
		clearCanvas.setPosition(35, 515);

		RectangleShape line; // Creates the line between settings and canvas.
		Vector2f linePos(250, 0);
		line.setPosition(linePos);
		line.setOutlineColor(Color::White);
		line.setOutlineThickness(2);
		line.setSize(Vector2f(0, 600));
		line.setFillColor(Color::White);

		if (sMgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}
		else
		{
			redBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}
		else
		{
			greenBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}
		else
		{
			blueBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}
		else
		{
			circleBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}
		else
		{
			squareBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::White && sMgr->getCurShape() == CLEARSELECTED)
		{
			clearSelectedBtn.setFillColor(Color::White);
			clearCanvasBtn.setFillColor(Color::Transparent);
		}
		else
		{
			clearCanvasBtn.setFillColor(Color::Transparent);
		}

		if (sMgr->getCurColor() == Color::White && sMgr->getCurShape() == CLEARCANVAS)
		{
			clearCanvasBtn.setFillColor(Color::White);
			clearSelectedBtn.setFillColor(Color::Transparent);
		}

		win.draw(color);
		win.draw(shape);
		win.draw(clearSelected);
		win.draw(clearCanvas);
		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(blueBtn);
		win.draw(circleBtn);
		win.draw(squareBtn);
		win.draw(clearSelectedBtn);
		win.draw(clearCanvasBtn);
		win.draw(line);
	}
};