/******************************************************************************
*
* COPYRIGHT Ráfagan S. de Abreu. ALL RIGHTS RESERVED.
*
* This software can be copied, stored and distributed without
* author's prior authorization. Just let him know and leave this header in this source code.
*
* This file was made available on https://github.com/rafagan/basic-2D-collision-demos/ and it is free
* to be restributed or used under Apache 2.0 license:
* http://www.apache.org/licenses/
*
******************************************************************************/

#include "collisions.h"

int pointBoxCollisionCheck(const Point *point, const BoundingBox *box) {
	int left = point->x >= box->x;
	int right = point->x <= (box->x + box->width);
	int bottom = point->y >= box->y;
	int top = point->y <= (box->y + box->height);

	return (left && right && top && bottom);
}

int AABBCollisionCheck(const BoundingBox *box, const BoundingBox *other){ 
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->x;
	boxRight = box->x + box->width; 
	boxBottom = box->y;
	boxTop = box->y + box->height;

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->x;
	otherRight = other->x + other->width; 
	otherBottom = other->y;
	otherTop = other->y + other->height;

	if(boxLeft > otherRight)
		return 0;
	if(boxRight < otherLeft)
		return 0;
	if (boxBottom > otherTop)
		return 0;
	if(boxTop < otherBottom)
		return 0;

	return 1; 
}

int AABBInnerCollisionCheck(const BoundingBox *box, const BoundingBox *other){ 
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->x;
	boxRight = box->x + box->width;
	boxBottom = box->y;
	boxTop = box->y + box->height;

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->x;
	otherRight = other->x + other->width; 
	otherBottom = other->y;
	otherTop = other->y + other->height;

	if(boxRight > otherLeft && boxLeft < otherRight)
		if(boxTop > otherBottom && boxBottom < otherTop)
			return 1;
	return 0; 
}

int circleCollisionCheck(const BoundingCircle *circle, const BoundingCircle *other) {
	Point distV;
	distV.x = circle->x - other->x;
	distV.y = circle->y - other->y;

	auto distSqr = distV.x * distV.x + distV.y * distV.y;
	auto sumRadius = (circle->radius * circle->radius + 2 * circle->radius * other->radius + other->radius * other->radius);
	return distSqr < sumRadius;
}

int circleBoxCollisionCheck(const BoundingBox *box, const BoundingCircle *circle) {
	Point result;
	float boxLeft, boxRight, boxTop, boxBottom;

	boxLeft = box->x;
	boxRight = box->x + box->width; 
	boxBottom = box->y;
	boxTop = box->y + box->height;

	if(circle->x < boxLeft)
		result.x = boxLeft;
	else if(circle->x > boxRight)
		result.x = boxRight;
	else
		result.x = circle->x;

	if(circle->y > boxTop)
		result.y = boxTop;
	else if(circle->y < boxBottom)
		result.y = boxBottom;
	else
		result.y = circle->y;

	Point distV;
	distV.x = result.x - circle->x;
	distV.y = result.y - circle->y;
	auto distSqr = distV.x * distV.x + distV.y * distV.y; 

	return distSqr < circle->radius * circle->radius;
}

int AABBOffsetCollisionCheck(const BoundingBox *box, const BoundingBox *other) {
	Point offset;
	offset.x = other->x - box->x;
	offset.y = other->y - box->y;

	if(offset.x >= 0) {
		if(offset.x > box->width)
			return 0;
	} else if(-offset.x > other->width)
		return 0;

	if(offset.y >= 0) {
		if(offset.y > box->height)
			return 0;
	} else if(-offset.y > other->height)
		return 0;

	return 1;
}