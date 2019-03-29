
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE, NOTHING }; // Contains which shape or no shape.

class SettingsMgr // Maintains current setting.
{
private:
	Color color; // Color.
	ShapeEnum shape; // Shape.
public:

	//===============================
	// SettingMgr: Current setting.
	// Parameters:
	// startingColor: Starting color.
	// startingShape: Staring Shape.
	// Return Type: None.
	//===============================

	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		color = startingColor;
		shape = startingShape;
	}

	//=================================
	// getCurColor: gets current color.
	// Parameters:
	// None.
	// Return Type: Color (color).
	//=================================

	Color getCurColor()
	{
		return color; // Returns colors
	}

	//=================================
	// getCurShape: gets current shape.
	// Parameters:
	// None.
	// Return Type: ShapeEnum (shape).
	//=================================

	ShapeEnum getCurShape()
	{
		return shape; // Returns shapes.
	}

	//=====================================
	// setCurrentColor: Sets current color.
	// Parameters:
	// setColor: Color needed to be set.
	// Return Type: None.
	//=====================================

	void setCurrentColor(Color setColor)
	{
		color = setColor;
	}

	//=====================================
	// setCurrentShape: Sets current shape.
	// Parameters:
	// setColor: Shape needed to be set.
	// Return Type: None.
	//=====================================

	void setCurrentShape(ShapeEnum setShape)
	{
		shape = setShape;
	}

	//=======================================
	// writeData: Writes data to binary file.
	// Parameters:
	// binaryFile: Binary file Data.
	// Return Type: None.
	//=======================================

	void writeData(fstream &binaryFile)
	{
		int colors = color.toInteger();
		binaryFile.write(reinterpret_cast<char*>(&colors), sizeof(colors));
		binaryFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}

	//====================================
	// readData: Read data to binary file.
	// Parameters:
	// binaryFile: Binary file Data.
	// Return Type: None.
	//====================================

	void readData(fstream &binaryFile)
	{
		int colors;
		binaryFile.read(reinterpret_cast<char*>(&colors), sizeof(colors));
		binaryFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));
		color = Color(colors);
	}
};