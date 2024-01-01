#pragma once
#include "Triangle.h"
using namespace std;
class XTree
{
	int centerZ, height, 
		smallest_tri_side, largest_tri_side,
		triangles_count,
		thickness;
	Triangle** triangles;
	static Color display_col;
	bool frontToCam = true;
	float YRotAngle = 0;
	Point3D smallest_point, biggest_point;
public:
	~XTree();
	XTree(int h, int smallest, int largest, int cnt, int thi);
	void draw(RenderWindow& canwaswnd, int offsetX, int offsetY);
	void rotate(RotationDirection rtd, int delta);
};

