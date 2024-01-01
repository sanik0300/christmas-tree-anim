#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
struct Point3D : Vector3f
{
	Vector2f projectXOY(int xOffset, int yOffset);
	void rotatePointX(float angle, const Vector3f& origin);
	void rotatePointY(float angle, const Vector3f& origin);

	Point3D() : Vector3f() {}
	Point3D(float x, float y, float z) : Vector3f(x, y, z) { }
};

