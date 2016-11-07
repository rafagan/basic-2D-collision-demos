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