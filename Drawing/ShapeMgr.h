
#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <vector>
using namespace std;
using namespace sf;

class ShapeMgr // Maintains current shapes and colors.
{
private:
	vector<DrawingShape*> shapes; // Stores shapes and colors.
public:

	//===============================
	// ShapeMgr: Default constructor.
	// Parameters:
	// None.
	// Return Type: None.
	//===============================

	ShapeMgr()
	{
		shapes = {};
	}

	//=========================
	// addShape: Adds shapes.
	// Parameters:
	// pos: Position of shape.
	// whichShape: Which Shape.
	// color: Which color.
	// Return Type: None.
	//=========================

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle *circle; // circle.
			circle = new Circle(pos, color, whichShape);
			shapes.push_back(circle);
		}

		if(whichShape == SQUARE)
		{
			Square *square; // Square.
			square = new Square(pos, color, whichShape);
			shapes.push_back(square);
		}
	}

	//=============================================
	// getShapes: gets current shape data.
	// Parameters:
	// None.
	// Return Type: vector<DrawingShape*> (shapes).
	//=============================================

	vector<DrawingShape*> getShapes()
	{
		return shapes; // Returns shapes data.
	}

	//======================
	// saveData: Saves Data.
	// Parameters:
	// binaryFile: Binary File Data.
	// Return Type: None.
	//======================

	void saveData(fstream &binaryFile)
	{
		ShapeData saved; // Shapes Data.

		for (unsigned int i = 0; i < shapes.size(); i++)
		{
			saved = shapes[i]->getShapeData();
			binaryFile.write(reinterpret_cast<char*>(&saved), sizeof(saved));
		}
	}

	//==============================
	// restoreData: Restores Data.
	// Parameters:
	// binaryFile: Binary File Data.
	// Return Type: None.
	//==============================

	void restoreData(fstream &binaryFile)
	{
		ShapeData restored; // Shapes data.

		while (binaryFile.read(reinterpret_cast<char*>(&restored), sizeof(restored)))
		{
			addShape(restored.pos, restored.sH, Color(restored.colorNumber));
		}
	}
};