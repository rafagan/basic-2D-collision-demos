/******************************************************************************
*
* COPYRIGHT Vin�cius G. Mendon�a ALL RIGHTS RESERVED.
* Acknowledgments to R�fagan Abreu for review and support since 2011 (kids grow fast).
*
* This software cannot be copied, stored, distributed without  
* Vin�cius G.Mendon�a prior authorization.
*
* This file was made available on http://www.pontov.com.br and it is free 
* to be restributed or used under Creative Commons license 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
*******************************************************************************
* Este software nao pode ser copiado, armazenado, distribuido sem autoriza��o 
* a priori de Vin�cius G. Mendon�a
*
* Este arquivo foi disponibilizado no site http://www.pontov.com.br e esta 
* livre para distribui��o seguindo a licen�a Creative Commons 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
******************************************************************************/
#include "AffineTransform.h"

using namespace math;

#pragma region Right hand

Vector2D rh::transform(const Matrix3 matrix, Vector2D& vector, float z)
{
	return Vector2D(
		vector.x * matrix.a() + vector.y * matrix.b() + z * matrix.c(),
		vector.x * matrix.d() + vector.y * matrix.e() + z * matrix.f());
}

Matrix3 rh::newAffineRotation(float radians)
{
	float sina = sin(radians);
	float cosa = cos(radians);

	return Matrix3(
		 cosa, -sina, 0,
		 sina,  cosa, 0,
		 0,     0,   1);
}

Matrix3 rh::newAffineScale(float scalex, float scaley)
{
	return Matrix3(
		scalex,   0,   0,
		  0,   scaley, 0,
		  0,     0,    1);
}

Matrix3 rh::newAffineTranslation(float x, float y)
{
	return Matrix3(
		1, 0, x,
		0, 1, y,
		0, 0, 1);
}

#pragma endregion

#pragma region Left hand

Vector2D lh::transform(const Matrix3 matrix, Vector2D& vector, float z)
{
	return Vector2D(
		matrix.a() * vector.x + matrix.d() * vector.y + matrix.g() * z,
		matrix.b() * vector.x + matrix.e() * vector.y + matrix.h() * z);
}

Matrix3 lh::newAffineTranslation(float x, float y)
{
	return Matrix3(
		1, 0, 0,
		0, 1, 0,
		x, y, 1);

}
#pragma endregion