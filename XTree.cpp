#define _USE_MATH_DEFINES
#include "XTree.h"
#include <math.h>
using namespace std;
Color XTree::display_col = Color(1, 255, 1);

XTree::~XTree()
{
	for (int i = 0; i < triangles_count; i++)
	{
		delete this->triangles[i];
	}
	delete[] this->triangles;
}

XTree::XTree(int h, int smallest, int largest, int cnt, int thi)
{
	this->thickness = thi;
	this->centerZ = h / 2;
	this->height = h;
	this->triangles_count = cnt;
	this->triangles = new Triangle*[cnt];

	this->largest_tri_side = largest;
	this->smallest_tri_side = smallest;

	this->smallest_point = Point3D(0, 0, h);
	this->biggest_point = Point3D();

	int zPosDelta = height / (cnt-1),
		triangleSideDelta = (largest - smallest) / cnt;

	for (int i = 0; i < cnt; i++) 
	{
		this->triangles[i] = new Triangle(Vector3i(0, 0, h - zPosDelta * i), smallest + triangleSideDelta * i, this->thickness);
	}
}

void XTree::draw(RenderWindow& canwaswnd, int offsetX, int offsetY)
{
	if (this->frontToCam)
	{
		for (int i = triangles_count-1; i >=0; i--)
		{
			this->triangles[i]->draw(display_col, canwaswnd, offsetX, offsetY, centerZ);
		}
	}
	else {
		for (int i = 0; i < triangles_count; i++)
		{
			this->triangles[i]->draw(display_col, canwaswnd, offsetX, offsetY, centerZ);
		}
	}
	
}

void XTree::rotate(RotationDirection rtd, int delta)
{
	Vector3f _origin = Vector3f(0, 0, this->centerZ);
	float _angle = atan((float)delta / centerZ);

	if (rtd == RotationDirection::X) 
	{
		this->smallest_point.rotatePointX(_angle, _origin);
		this->biggest_point.rotatePointX(_angle, _origin);
	}
	else {
		this->smallest_point.rotatePointY(_angle, _origin);
		this->biggest_point.rotatePointY(_angle, _origin);
	}
	this->frontToCam = smallest_point.z >= biggest_point.z;

	for (char i = 0; i < triangles_count; i++) 
	{
		triangles[i]->rotate(rtd, _angle, _origin);
	}
}
