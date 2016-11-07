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

#include "Vector3D.h"
#include "Vector2D.h"

#include "MathUtil.h"

#include <stdexcept>
#include <sstream>

using namespace math;

Vector3D::Vector3D() : x(0), y(0), z(0)
{}

Vector3D::Vector3D(float _x, float _y, float _z)
        : x(_x), y(_y), z(_z)
{}

Vector3D::Vector3D(const Vector2D& other, float _z)
 : x(other.x), y(other.y), z(_z)
{
}

Vector3D::Vector3D(const Vector2D& other)
: x(other.x), y(other.y), z(0)
{
}

Vector3D::Vector3D(float xyz[3])
: x(xyz[0]), y(xyz[1]), z(xyz[2])
{
}

Vector3D& Vector3D::set(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    return *this;
}

Vector3D& Vector3D::set(const float xyz[3])
{
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
    return *this;
}

Vector3D& Vector3D::set(const Vector2D& v, float _z)
{
    x = v.x;
    y = v.y;
    z = _z;
    return *this;
}

Vector3D& Vector3D::addX(float _x)
{
    x += _x;
    return *this;
}

Vector3D& Vector3D::addY(float _y)
{
    y += _y;
    return *this;
}

Vector3D& Vector3D::addZ(float _z)
{
    z += _z;
    return *this;
}

Vector3D& Vector3D::add(float _x, float _y, float _z)
{
    x += _x;
    y += _y;
    z += _z;
    return *this;
}


float& Vector3D::operator [](long index)
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default:
        {
            std::stringstream ss;
            ss << "Index out of bounds: " << index << " size: 3";
            throw std::out_of_range(ss.str());
        }
    }
}

float Vector3D::operator [](long index) const
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default:
        {
            std::stringstream ss;
            ss << "Index out of bounds: " << index << " size: 3";
            throw std::out_of_range(ss.str());
        }
    }
}

Vector3D& Vector3D::operator +=(const Vector3D& other)
{
    return add(other.x, other.y, other.z);
}

Vector3D& Vector3D::operator =(const Vector2D& other)
{
    return set(other, 0.0f);
}

Vector3D& Vector3D::operator +=(const Vector2D& other)
{
    return add(other.x, other.y, 0.0f);
}

Vector3D& Vector3D::operator -=(const Vector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return (*this);
}

Vector3D& Vector3D::operator -=(const Vector2D& other)
{
    x -= other.x;
    y -= other.y;
    return (*this);
}

Vector3D& Vector3D::operator *=(float c)
{
    x *= c;
    y *= c;
    z *= c;
    return *this;
}

Vector3D& Vector3D::operator /=(float c)
{
    x /= c;
    y /= c;
    z /= c;
    return *this;
}

Vector3D Vector3D::operator -(void) const
{
    return (Vector3D(-x, -y, -z));
}

Vector3D Vector3D::operator +(const Vector3D& other) const
{
    return (Vector3D(x + other.x, y + other.y, z + other.z));
}

Vector3D Vector3D::operator +(const Vector2D& other) const
{
    return (Vector3D(x + other.x, y + other.y, z));
}

Vector3D Vector3D::operator -(const Vector3D& other) const
{
    return (Vector3D(x - other.x, y - other.y, z - other.z));
}

Vector3D Vector3D::operator -(const Vector2D& other) const
{
    return (Vector3D(x - other.x, y - other.y, z));
}

Vector3D Vector3D::operator *(float c) const
{
    return (Vector3D(x * c, y * c, z * c));
}

Vector3D math::operator * (float scalar, const Vector3D& vector)
{
	return vector * scalar;
}

Vector3D Vector3D::operator /(float t) const
{
    float f = 1.0F / t;
    return (Vector3D(x * f, y * f, z * f));
}

Vector3D Vector3D::operator *(const Vector3D& other) const
{
    return (Vector3D(x * other.x,
                     y * other.y,
                     z * other.z));
}

bool Vector3D::operator ==(const Vector3D& other) const
{
	return equals(x, other.x) &&
		   equals(y, other.y) &&
		   equals(z, other.z);
}

bool Vector3D::operator !=(const Vector3D& other) const
{
    return !(*this == other);
}

float Vector3D::dot(const Vector3D& other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

Vector3D& Vector3D::cross(const Vector3D& other)
{
    float nx, ny;

    nx = y * other.z - z * other.y;
    ny = z * other.x - x * other.z;
    z = x * other.y - y * other.x;

    x = nx;
    y = ny;

    return *this;
}

float Vector3D::sizeSqr() const
{
    return x * x + y * y + z * z;
}

float Vector3D::size() const
{
    return sqrtf(sizeSqr());
}

Vector3D& Vector3D::resize(float size)
{
	return normalize() *= size;
}

Vector3D& Vector3D::normalize()
{
	float s = sizeSqr();
	return (s == 0) ? *this : (*this /= sqrtf(s));
}

Vector3D& Vector3D::rotateX(float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);

    float ny = c * y - s * z;
    float nz = c * z + s * y;

    y = ny;
    z = nz;

    return (*this);
}

Vector3D& Vector3D::rotateY(float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);

    float nx = c * x + s * z;
    float nz = c * z - s * x;

    x = nx;
    z = nz;

    return (*this);
}

Vector3D& Vector3D::rotateZ(float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);

    float nx = c * x - s * y;
    float ny = c * y + s * x;

    x = nx;
    y = ny;

    return (*this);
}

Vector3D& Vector3D::rotateAxis(float angle, const Vector3D& axis)
{
    float s = sinf(angle);
    float c = cosf(angle);
    float k = 1.0F - c;

    float nx = x * (c + k * axis.x * axis.x) +
               y * (k * axis.x * axis.y - s * axis.z) +
               z * (k * axis.x * axis.z + s * axis.y);

    float ny = x * (k * axis.x * axis.y + s * axis.z) +
               y * (c + k * axis.y * axis.y) +
               z * (k * axis.y * axis.z - s * axis.x);

    float nz = x * (k * axis.x * axis.z - s * axis.y) +
               y * (k * axis.y * axis.z + s * axis.x) +
               z * (c + k * axis.z * axis.z);

    x = nx;
    y = ny;
    z = nz;

    return *this;
}

std::ostream& math::operator<<(std::ostream& output, const Vector3D& p)
{
	output << "(" << p.x << "," << p.y << "," << p.z << ")";
	return output;	
}