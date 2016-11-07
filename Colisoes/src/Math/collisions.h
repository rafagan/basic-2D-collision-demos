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

#pragma once

struct BoundingBox {
	float x;
	float y;
	int width; 
	int height;
};

//Implementação alternativa
// struct BoundingBox { 
// 	int left, right, top, bottom;
// };

struct Point { 
	float x;
	float y; 
};

int pointBoxCollisionCheck(const Point *point, const BoundingBox *box);

//Três maneiras diferentes de fazer a mesma coisa
int AABBCollisionCheck(const BoundingBox *box, const BoundingBox *other);
int AABBInnerCollisionCheck(const BoundingBox *box, const BoundingBox *other);
int AABBOffsetCollisionCheck(const BoundingBox *box, const BoundingBox *other);

struct BoundingCircle {
	float radius;
	float x, y;
};

int circleCollisionCheck(const BoundingCircle *c1, const BoundingCircle *c2);
int circleBoxCollisionCheck(const BoundingBox *b, const BoundingCircle *c);