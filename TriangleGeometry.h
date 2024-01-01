#pragma once
#include <SFML/Graphics.hpp>
#include "Point3D.h"
using namespace sf;
enum RotationDirection { X, Y };

struct TriangleGeometry
{
	Point3D top_pt, left_side, right_side;
	TriangleGeometry(Vector3i& center, int side_len);

	void rotate(RotationDirection rtd, float angle, const Vector3f& origin);
};

