/******************************************************************************
*
* COPYRIGHT Vinícius G. Mendonça ALL RIGHTS RESERVED.
* Acknowledgments to Ráfagan Abreu for review and support since 2011 (kids grow fast).
*
* This software cannot be copied, stored, distributed without  
* Vinícius G.Mendonça prior authorization.
*
* This file was made available on http://www.pontov.com.br and it is free 
* to be restributed or used under Creative Commons license 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
*******************************************************************************
* Este software nao pode ser copiado, armazenado, distribuido sem autorização 
* a priori de Vinícius G. Mendonça
*
* Este arquivo foi disponibilizado no site http://www.pontov.com.br e esta 
* livre para distribuição seguindo a licença Creative Commons 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
******************************************************************************/

#include "Vector2D.h"
#include "MathUtil.h"

#include <stdexcept>
#include <sstream>

using namespace math;

Vector2D::Vector2D() : x(0), y(0)
{
}

Vector2D::Vector2D(int aX, int anY) : x(float(aX)), y(float(anY))
{
}

Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y)
{
}

Vector2D::Vector2D(float xy[2]) : x(xy[0]), y(xy[1])
{
}

Vector2D Vector2D::newBySizeAngle(float size, float radians)
{
    return Vector2D(cos(radians) * size,
                    sin(radians) * size);
}

Vector2D& Vector2D::set(float _x, float _y)
{
	x = _x;
	y = _y;
	return *this;
}

Vector2D& Vector2D::set(const float xy[2])
{
    x = xy[0];
    y = xy[1];
    return *this;
}

Vector2D& Vector2D::set(const Vector2D& other)
{
    if (&other == this)
        return *this;

    x = other.x;
    y = other.y;
    return *this;
}

float Vector2D::sizeSqr() const
{
	return x * x + y * y;
}

float Vector2D::size() const
{
	return sqrtf(sizeSqr());
}

float Vector2D::angle() const
{
	return atan2f(y,x);
}

Vector2D& Vector2D::rotate(float radians) 
{
	float s = sin(radians);
    float c = cos(radians);

    float newX = x * c - y * s;
    float newY = x * s + y * c;

    x = newX;
    y = newY;

    return *this;
}

Vector2D& Vector2D::normalize()
{
	float s = sizeSqr();
	return (s == 0) ? *this : (*this /= sqrtf(s));
}

Vector2D& Vector2D::resize(float size)
{
	return normalize() *= size;
}

float Vector2D::operator[] (long index) const
{
    if (index == 0)
        return x;
    if (index == 1)
        return y;

    std::stringstream ss;
    ss << "Index out of bounds: " << index << " size: 2";
    throw std::out_of_range(ss.str());
}

float& Vector2D::operator[] (long index)
{
    if (index == 0)
        return x;
    if (index == 1)
        return y;

    std::stringstream ss;
    ss << "Index out of bounds: " << index << " size: 2";
    throw std::out_of_range(ss.str());
}

Vector2D& Vector2D::operator += (const Vector2D& other)
{
	x += other.x;
    y += other.y;
    return *this;
}

Vector2D& Vector2D::operator -= (const Vector2D& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2D& Vector2D::operator *= (float c)
{
	x *= c;
	y *= c;
	return *this;
}

Vector2D& Vector2D::operator /= (float c)
{
	x /= c;
    y /= c;
    return *this;
}

Vector2D Vector2D::operator -(void) const
{
	return Vector2D(-x, -y);
}

Vector2D Vector2D::operator +(const Vector2D& other) const
{
	return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator -(const Vector2D& other) const
{
	return Vector2D(x - other.x, y - other.y);
}

Vector2D math::operator*(float scalar, const Vector2D& vector)
{
	return vector * scalar;
}

Vector2D Vector2D::operator *(float c) const
{
	return Vector2D(x*c, y*c);
}

Vector2D Vector2D::operator /(float c) const
{
	return Vector2D(x/c, y/c);
}

bool Vector2D::operator ==(const Vector2D& other) const
{
	return equals(x, other.x) && equals(y, other.y);	
}

bool Vector2D::operator !=(const Vector2D& other) const
{
	return !(*this == other);	
}

float Vector2D::dot(const Vector2D& other) const
{
    return x * other.x + y * other.y;
}

float Vector2D::relativeAngleBetween(const Vector2D v2) const
{
	return angle() - v2.angle();
}

std::ostream& math::operator<<(std::ostream& output, const Vector2D& p)
{
	output << "(" << p.x << "," << p.y << ")";
	return output;
}
