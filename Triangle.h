#pragma once
#include <SFML/Graphics.hpp>
#include "TriangleGeometry.h"
using namespace sf;
using namespace std;
class Triangle
{
	TriangleGeometry *outer3, *inner3;
	static const float max_brightness_delta;
public:
	~Triangle();
	Triangle(Vector3i center, int side_len, int thickness);
	void draw(Color& color, RenderWindow& rwd, int xOffset, int yOffset, int MaxZDelta);
	void rotate(RotationDirection rtd, float angle, const Vector3f& origin);
};

