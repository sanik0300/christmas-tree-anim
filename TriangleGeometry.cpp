#include "TriangleGeometry.h"
TriangleGeometry::TriangleGeometry(Vector3i& center, int side_len)
{
	float bigCircleR = (float)side_len / sqrt(3),
		smolCircle_r = bigCircleR / 2;

	top_pt = Point3D(center.x, center.y - bigCircleR, center.z),
	left_side = Point3D(center.x - side_len / 2, center.y + smolCircle_r, center.z),
	right_side = Point3D(center.x + side_len / 2, center.y + smolCircle_r, center.z);
}
//--------------------

void TriangleGeometry::rotate(RotationDirection rtd, float angle, const Vector3f& origin)
{
	if (rtd == RotationDirection::X) {
		this->top_pt.rotatePointX(angle, origin);
		this->left_side.rotatePointX(angle, origin);
		this->right_side.rotatePointX(angle, origin);
	}
	else {
		this->top_pt.rotatePointY(angle, origin);
		this->left_side.rotatePointY(angle, origin);
		this->right_side.rotatePointY(angle, origin);
	}

}

