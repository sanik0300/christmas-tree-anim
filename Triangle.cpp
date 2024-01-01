#include "Triangle.h"

const float Triangle::max_brightness_delta=0.5;

Triangle::Triangle(Vector3i center, int side_len, int thickness)
{
	this->inner3 = new TriangleGeometry(center, max(side_len - thickness, 2));
	this->outer3 = new TriangleGeometry(center, side_len + thickness);
}

Triangle::~Triangle()
{
	delete this->inner3;
	delete this->outer3;
}

float clamp(float val, float lower, float upper) 
{
	if (val < lower) { return lower; }
	if (val > upper) { return upper; }
	return val;
}

void Triangle::draw(Color& color, RenderWindow& rwd, int xOffset, int yOffset, int MaxZDelta)
{
	ConvexShape leftSide, rightSide, bottom;
	//draw left side
	leftSide.setPointCount(4);
	Vector2f outer_top = outer3->top_pt.projectXOY(xOffset, yOffset),
		inner_top = inner3->top_pt.projectXOY(xOffset, yOffset),
		inner_left = inner3->left_side.projectXOY(xOffset, yOffset),
		outer_left = outer3->left_side.projectXOY(xOffset, yOffset);
	leftSide.setPoint(0, outer_top);
	leftSide.setPoint(1, inner_top);
	leftSide.setPoint(2, inner_left);
	leftSide.setPoint(3, outer_left);
	int avgZ1 = MaxZDelta - (outer3->top_pt.z + inner3->top_pt.z + inner3->left_side.z + outer3->left_side.z) / 4;
	float coef1 = ((float)avgZ1 / MaxZDelta)*max_brightness_delta;
	leftSide.setFillColor(Color(clamp(color.r*(1-coef1), 0, 255), 
								clamp(color.g*(1-coef1), 0, 255),
								clamp(color.b*(1-coef1), 0, 255)));

	//draw right side
	rightSide.setPointCount(4);
	Vector2f outer_right = outer3->right_side.projectXOY(xOffset, yOffset),
			 inner_right = inner3->right_side.projectXOY(xOffset, yOffset);
	rightSide.setPoint(0, inner_top);
	rightSide.setPoint(1, outer_top);
	rightSide.setPoint(2, outer_right);
	rightSide.setPoint(3, inner_right);
	int avgZ2 = MaxZDelta - (inner3->top_pt.z + outer3->top_pt.z + outer3->right_side.z + inner3->right_side.z) / 4;
	float coef2 = ((float)avgZ2 / MaxZDelta)*max_brightness_delta;
	rightSide.setFillColor(Color(clamp(color.r * (1 - coef2), 0, 255), 
								clamp(color.g * (1 - coef2), 0, 255), 
								clamp(color.b * (1 - coef2), 0, 255)));

	//draw bottom
	bottom.setPointCount(4);
	bottom.setPoint(0, outer_left);
	bottom.setPoint(1, inner_left);
	bottom.setPoint(2, inner_right);
	bottom.setPoint(3, outer_right);
	int avgZ3 = MaxZDelta - (inner3->left_side.z + outer3->left_side.z + outer3->right_side.z + inner3->right_side.z) / 4;
	float coef3 = ((float)avgZ3 / MaxZDelta)*max_brightness_delta;
	bottom.setFillColor(Color(clamp(color.r * (1 - coef3), 0, 255), 
							clamp(color.g * (1 - coef3), 0, 255), 
							clamp(color.b * (1 - coef3), 0, 255)));

	rwd.draw(leftSide);
	rwd.draw(rightSide);
	rwd.draw(bottom);
}

void Triangle::rotate(RotationDirection rtd, float angle, const Vector3f& origin)
{
	this->inner3->rotate(rtd, angle, origin);
	this->outer3->rotate(rtd, angle, origin);
}
