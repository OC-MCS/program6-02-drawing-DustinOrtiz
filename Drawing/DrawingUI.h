
#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeMgr.h"
#include <iostream>
using namespace std;
using namespace sf;

class DrawingUI // Draws shapes and colors on right side of screen.
{
private:
	RectangleShape canvas; // Canvas to draw on.
public:

	//======================
	// DrawingUI: Positions.
	// Parameters:
	// p: Position.
	// Return Type: None.
	//======================

	DrawingUI(Vector2f p)
	{
		p;
	}

	//=========================================
	// draw: Draws shapes and colors on canvas.
	// Parameters:
	// win: Window to draw shapes and colors.
	// mgr: Shape manager.
	// Return Type: None.
	//=========================================

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		Vector2f canvasPos(257, 0);
		canvas.setPosition(canvasPos);
		canvas.setOutlineColor(Color::Black);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(542, 597));
		canvas.setFillColor(Color::Black);
		win.draw(canvas);

		for (unsigned int i = 0; i < mgr->getShapes().size(); i++)
		{
			mgr->getShapes()[i]->draw(win);
		}
	}

	//========================================================
	// isMouseInCanvas: Detects if mouse is in canvas to draw.
	// Parameters:
	// mousePos: Mouse position.
	// Return Type: bool (inCanvas).
	//========================================================
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inCanvas;

		if (canvas.getGlobalBounds().contains(mousePos))
		{
			inCanvas = true;
		}
		else
		{
			inCanvas = false;
		}

		return inCanvas; // Returns if mouse is in canvas.
	}
};