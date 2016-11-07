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
#ifndef VECTOR3D_H_INCLUDED
#define VECTOR3D_H_INCLUDED

#include "Vector2D.h"

namespace math
{
    /**
        This class represents a 3 coordinate space mathematical vector.
        All operations expected for a vector, like sum, subtraction, product,
        cross product, dot product and normalization are provided.

		Also, a set of useful functions are also provided, to more complex operations
		like reflex, truncation, distance. Functions also provide a non-mutable version
		of methods and easier interoperability with Vector2D.
    */
    class Vector3D
    {

    public:
        float   x;
        float   y;
        float   z;

        /** Creates a new null vector 3D */
        explicit Vector3D();

        /** Create a new vector 3D based on the given values.
        @param _x x coordinate
        @param _y y coordinate
        @param _z z coordinate
        */
        explicit Vector3D(float _x, float _y, float _z);

        /**
          Creates a new Vector3D using the x and y coordinates
          from the given Vector2D and the given z coordinate.
          @param Vector2D& A 2D vector
          @param z A z coordinate.
        */
        explicit Vector3D(const Vector2D& other, float _z);

        /**
            Creates a new Vector3D using the x and y coordinates
            from the given Vector2D and applying 0 in the Z coordinate
            @param Vector2D& A 2D vector
        */
        explicit Vector3D(const Vector2D& other);

        /**
            Creates a new Vector3D from the given array. The coordinates
            will be mapped as following. Index 0 as x, index 1 as y and
            index 2 as z
            @param xyz An array containing the x, y, z coordinates
        */
        explicit Vector3D(float xyz[3]);

        /**
            Adds to x coordinate
            @param _x The amount to add in x
            @return This vector.
        */
        Vector3D& addX(float _x);

        /**
            Adds to y coordinate
            @param _y The amount to add in y
            @return This vector.
        */
        Vector3D& addY(float _y);

        /**
            Adds to z coordinate
            @param _z The amount to add in z
            @return This vector.
        */
        Vector3D& addZ(float _z);

        /**
            Adds to all vector coordinates

            @param _x The amount to add in x
            @param _y The amount to add in y
            @param _z The amount to add in z

            @return This vector.
        */
        Vector3D& add(float _x, float _y, float _z);

        /**
            Sets the x, y and z coordinates in one single operation.

            @param _x The x coordinate
            @param _y The y coordinate
            @param _z The z coordinate
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& set(float _x, float _y, float _z);

        /**
            Sets the x, y and z coordinates in one single operation. The
            coordinates will be mapped as following. Array index 0 as x,
            index 1 as y and index 2 as z

            @param xyz An array containing the x, y, z coordinates
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& set(const float xyz[3]);

        /**
            Sets the x, y and z coordinates in one single operation.
            The x and y coordinates will be taken from the given Vector2D.

            @param Vector2D& A 2D vector
            @param z A z coordinate.
        */
        Vector3D& set(const Vector2D& v, float _z);

        /**
            Allows write access to the vector coordinates as if was
            an array containing the x in index 0, y in index 1
            and z in index 2. No bounds check are made, so be careful.
            @param index The coordinate index. As descrived above.
        */
        float& operator [](long index);

        /**
            Allows read access to the vector coordinates as if was
            an array containing the x in index 0, y in index 1
            and z in index 2. No bounds check are made, so be careful.
            @param k The coordinate index. As descrived above.
        */
        float operator [](long index) const;

        /** Assigns the value from the other Vector3D in this Vector3D.*/
        Vector3D& operator =(const Vector2D& other);

        /** Assignment operator. z will be assigned to 0. */
        Vector3D& operator +=(const Vector3D& other);

        /** Adds the given Vector3D values to this vector */
        Vector3D& operator +=(const Vector2D& other);

        /** Subtracts this Vector3D from the given vector */
        Vector3D& operator -=(const Vector3D& other);

        /**
            Subtracts this Vector2D from the given vector.
            Z coordinate will be left unchanged.
        */
        Vector3D& operator -=(const Vector2D& other);

        /** Multiplies this vector by the given scalar constant. */
        Vector3D& operator *=(float c);

        /** Divides this vector by the given vector */
        Vector3D& operator /=(float c);

        /** Creates a new Vector that is the negation of this one. */
        Vector3D operator -(void) const;
        /** Creates a new vector with the sum of this and the given one.*/
        Vector3D operator +(const Vector3D& other) const;
        /**
            Creates a new vector with the sum of this and the given one.
            The z coordinate will remain equal to this vector z coordinate.
        */
        Vector3D operator +(const Vector2D& other) const;

        /** Creates a new vector with the subtraction of this and the given
            one.*/
        Vector3D operator -(const Vector3D& other) const;

        /**
            Creates a new vector with the subtraction of this and the given one
            The z coordinate will remain equal to this vector z coordinate.
        */
        Vector3D operator -(const Vector2D& other) const;

        /** Creates a new vector with the product of this vector and the given
            scalar constant.*/
        Vector3D operator *(float c) const;

        /** Creates a new vector with the division of this vector and the given
            scalar constant.*/
        Vector3D operator /(float c) const;

        /** Creates a new vector with the product of this vector and the given
            one.*/
        Vector3D operator *(const Vector3D& other) const;

        /** Test if two vectors are equal */
        bool operator ==(const Vector3D& other) const;

        /** Test if two vectors are different */
        bool operator !=(const Vector3D& other) const;
				
        /** @return the size (magnitude) of this vector squared */
        float sizeSqr() const;

        /** @return the size (magnitude) of this vector */
        float size() const;

		/** Changes this vector size */
		Vector3D& resize(float size);

        /** Apply a cross product in this vector with the given vector.
            @param other The vector that will be used in the cross product.
            @return This own vector, modified by the cross product,
                    for invocation chaning.
        */
        Vector3D& cross(const Vector3D& other);

        /**
            Applies the dot product of this vector and the other one.
            @return The dot product.
        */
        float dot(const Vector3D& other) const;

        /**
            Creates a new vector that is a normalized version of this one.            
        */
		Vector3D& normalize();

        /**
            Rotates this vector around the x axis.
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& rotateX(float radians);

        /**
            Rotates this vector around the y axis.
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& rotateY(float radians);

        /**
            Rotates this vector around the z axis.
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& rotateZ(float radians);

        /**
            Rotates this vector around the given axis.
            @return This own vector is returned, for invocation chaning.
        */
        Vector3D& rotateAxis(float radians, const Vector3D& axis);

		/**
		* Returns true if it's the zero vector (size == 0)
		*/
		inline bool isZero() const { return equals(x, 0) && equals(y, 0) && equals(z,0); }

		/**
		* Returns true if it's a unit vector (size == 1)
		*/
		inline bool isUnit() const { return equals(size(), 1); }
    };

	Vector3D operator*(float scalar, const Vector3D& vector);

	/** Returns the x and y components of this vector as a Vector2D */
	inline Vector2D xy(const Vector3D& v) { return Vector2D(v.x, v.y); }
	/** Returns the y and x components of this vector as a Vector2D */
	inline Vector2D yx(const Vector3D& v) { return Vector2D(v.y, v.x); }

	/** Returns the x and z components of this vector as a Vector2D */
	inline Vector2D xz(const Vector3D& v) { return Vector2D(v.x, v.z); }
	/** Returns the z and x components of this vector as a Vector2D */
	inline Vector2D zx(const Vector3D& v) { return Vector2D(v.z, v.x); }

	/** Returns the y and z components of this vector as a Vector2D */
	inline Vector2D yz(const Vector3D& v) { return Vector2D(v.y, v.z); }
	/** Returns the z and y components of this vector as a Vector2D */
	inline Vector2D zy(const Vector3D& v) { return Vector2D(v.z, v.y); }

	inline float distanceSqr(const Vector3D& p1, const Vector3D& p2)
	{
		return (p1 - p2).sizeSqr();
	}

	inline float distance(const Vector3D& p1, const Vector3D& p2)
	{
		return (p1 - p2).size();
	}

	inline Vector3D rotateX(const Vector3D& v, float radians)
	{
		return Vector3D(v).rotateX(radians);
	}

	inline Vector3D cross(Vector3D v1, Vector3D v2)
	{
		return Vector3D(v1).cross(v2);
	}

	inline Vector3D rotateY(const Vector3D& v, float radians)
	{
		return Vector3D(v).rotateY(radians);
	}

	inline Vector3D rotateZ(const Vector3D& v, float radians)
	{
		return Vector3D(v).rotateZ(radians);
	}

	inline Vector3D& rotateAxis(const Vector3D& v, float radians, const Vector3D& axis)
	{
		return Vector3D(v).rotateAxis(radians, axis);
	}

	inline Vector3D resize(const Vector3D& v, float size)
	{
		return Vector3D(v).resize(size);
	}

	inline math::Vector3D truncate(const math::Vector3D& v, float size)
	{					
		return (v.sizeSqr() > size * size) ? resize(v, size) : v;
	}

	inline Vector3D normalize(const Vector3D& v) 
	{ 
		return Vector3D(v).normalize(); 
	}

	inline Vector3D reflect(const Vector3D& ray, const Vector3D& normal) 
	{
		return ray - 2 * ray.dot(normal) * normal;
	}

	std::ostream& operator<<(std::ostream& output, const Vector3D& p);
}
#endif // VECTOR3D_H_INCLUDED
