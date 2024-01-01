#include "Point3D.h"

Vector2f Point3D::projectXOY(int xOffset=0, int yOffset=0)
{
    return Vector2f(this->x + xOffset, this->y + yOffset);
}

void Point3D::rotatePointX(float angle, const Vector3f& origin)
{
	Vector3f relative_point(this->x - origin.x, this->y - origin.y, this->z - origin.z);

	Vector3f rotated_rel(relative_point.x,
						relative_point.y * cos(angle) + relative_point.z * sin(angle),
						-1 * relative_point.y * sin(angle) + relative_point.z * cos(angle));

	this->x = rotated_rel.x + origin.x;
	this->y = rotated_rel.y + origin.y;
	this->z = rotated_rel.z + origin.z;
}

void Point3D::rotatePointY(float angle, const Vector3f& origin)
{
	Vector3f relative_point(this->x - origin.x, this->y - origin.y, this->z - origin.z);

	Vector3f rotated_rel(relative_point.x*cos(angle)+relative_point.z*sin(angle),
						relative_point.y,
						-1 * relative_point.x * sin(angle) + relative_point.z * cos(angle));

	this->x = rotated_rel.x + origin.x;
	this->y = rotated_rel.y + origin.y;
	this->z = rotated_rel.z + origin.z;
}
