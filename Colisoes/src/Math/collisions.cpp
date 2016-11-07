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
	int top = point->y >= box->y;
	int bottom = point->y <= (box->y + box->height);

	return (left && right && top && bottom);
}

int AABBCollisionCheck(const BoundingBox *box, const BoundingBox *other){ 
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->x;
	boxRight = box->x + box->width; 
	boxTop = box->y;
	boxBottom = box->y + box->height;

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->x;
	otherRight = other->x + other->width; 
	otherTop = other->y;
	otherBottom = other->y + other->height;

	if(boxLeft > otherRight)
		return 0;
	if(boxRight < otherLeft)
		return 0;
	if(boxTop > otherBottom)
		return 0;
	if(boxBottom < otherTop)
		return 0;

	return 1; 
}

int AABBInnerCollisionCheck(const BoundingBox *box, const BoundingBox *other){ 
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->x;
	boxRight = box->x + box->width;
	boxTop = box->y;
	boxBottom = box->y + box->height;

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->x;
	otherRight = other->x + other->width; 
	otherTop = other->y;
	otherBottom = other->y + other->height;

	if(boxRight > otherLeft && boxLeft < otherRight)
		if(boxTop < otherBottom && boxBottom > otherTop)
			return 1;
	return 0; 
}

int circleCollisionCheck(const BoundingCircle *c1, const BoundingCircle *c2) {
	Point distV;
	distV.x = c1->x - c2->x;
	distV.y = c1->y - c2->y;

	auto distSqr = distV.x * distV.x + distV.y * distV.y;
	auto sumRadius = (c1->radius * c1->radius + 2 * c1->radius * c2->radius + c2->radius * c2->radius);
	return distSqr < sumRadius;
}

int circleBoxCollisionCheck(const BoundingBox *b, const BoundingCircle *c) {
	Point p;
	float boxLeft, boxRight, boxTop, boxBottom;

	boxLeft = b->x;
	boxRight = b->x + b->width; 
	boxTop = b->y;
	boxBottom = b->y + b->height;

	if(c->x < boxLeft)
		p.x = boxLeft;
	else if(c->x > boxRight)
		p.x = boxRight;
	else
		p.x = c->x;

	if(c->y < boxTop)
		p.y = boxTop;
	else if(c->y > boxBottom)
		p.y = boxBottom;
	else
		p.y = c->y;

	Point distV;
	distV.x = p.x - c->x;
	distV.y = p.y - c->y;
	auto distSqr = distV.x * distV.x + distV.y * distV.y; 

	return distSqr < c->radius * c->radius;
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