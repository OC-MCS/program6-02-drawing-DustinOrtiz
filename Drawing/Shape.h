
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct ShapeData // Maintains shapes data.
{
	int colorNumber; // Shape color.
	Vector2f pos; // Shape position.
	ShapeEnum sH; // Which shape.
};

class DrawingShape // Draws the shapes.
{
private:
	Vector2f location; // Shape location.
	Color color; // Shape color.
	ShapeEnum shape; // Which shape.
	ShapeData shapeData; // Shape Data.
public:

	//===================================
	// DrawingShape: Sets the shape data.
	// Parameters:
	// loc: Location of shape.
	// col: Color of shape.
	// sH: Which Shape.
	// Return Type: None.
	//===================================

	DrawingShape(Vector2f loc, Color col , ShapeEnum sH)
	{
		location = loc;
		color = col;
		shape = sH;

		shapeData.colorNumber = col.toInteger();
		shapeData.pos = loc;
		shapeData.sH = sH;
	}

	//===============================
	// draw: draws the default shape.
	// Parameters:
	// win: Window to draw.
	// Return Type: None.
	//===============================

	virtual void draw(RenderWindow &win) = 0;

	//=================================
	// getShapeData: gets shape data.
	// Parameters:
	// None.
	// Return Type: struct (shapeData).
	//=================================

	ShapeData getShapeData()
	{
		return shapeData; // returns shape data.
	}
};

class Circle : public DrawingShape // Draws the circles
{
private:
	CircleShape circle; // Circle shape.
public:

	//===========================
	// Circle: Draws the circles.
	// Parameters:
	// loc: Location of shape.
	// col: Color of shape.
	// sH: Which Shape.
	// Return Type: None.
	//===========================

	Circle(Vector2f loc, Color col, ShapeEnum sH) : DrawingShape(loc, col, sH)
	{
		circle.setPosition(loc);
		circle.setRadius(5);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(col);
		circle.setFillColor(col);
	}

	//==============================
	// draw: draws the circle shape.
	// Parameters:
	// win: Window to draw circles.
	// Return Type: None.
	//==============================

	void draw(RenderWindow &win)
	{
		win.draw(circle);
	}
};

class Square : public DrawingShape // Draws the squares.
{
private:
	RectangleShape square; // Square shape.
public:

	//===================================
	// Square: Draws the squares.
	// Parameters:
	// loc: Location of shape.
	// col: Color of shape.
	// sH: Which Shape.
	// Return Type: None.
	//===================================

	Square(Vector2f loc, Color col, ShapeEnum sH) : DrawingShape(loc, col, sH)
	{
		square.setPosition(loc);
		square.setOutlineColor(col);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(8, 8));
		square.setFillColor(col);
	}

	//==============================
	// draw: draws the square shape.
	// Parameters:
	// win: Window to draw squares.
	// Return Type: None.
	//==============================

	void draw(RenderWindow &win)
	{
		win.draw(square);
	}
};