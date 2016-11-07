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

#ifndef MATHUTIL_H_INCLUDED
#define MATHUTIL_H_INCLUDED

#include <cmath>

namespace math
{
	static const double MATH_PI = 3.14159265358979323846;
	static const double MATH_PI_OVER_TWO = MATH_PI / 2.0;
	static const double ONE_DEGREE = 180.0 / MATH_PI;
	static const double E = 2.7182818284590452354;
	static const float FLOAT_DELTA = 0.00001f;
	static const float DOUBLE_DELTA =  0.00000000000001f;

	static const unsigned short FAST_SIN_PRECISION = 65535; //MAX_SHORT

    inline double toDegrees(double angrad)
    {
        return angrad * ONE_DEGREE;
    }

    inline float toDegrees(float angrad)
    {
        return static_cast<float>(angrad * ONE_DEGREE);
    }

    inline float toDegrees(int angrad)
    {
        return toDegrees(static_cast<float>(angrad));
    }

    inline double toRadians(double angdeg)
    {
        return angdeg / ONE_DEGREE;
    }

    inline float toRadians(float angdeg)
    {
        return static_cast<float>(angdeg / ONE_DEGREE);
    }

    inline float toRadians(int angdeg)
    {
        return toRadians(static_cast<float>(angdeg));
    }

   /**
    * Compare if two floats are equals within the given delta tolerance.
    * 
    * @param f1 A float
    * @param f2 Another float
    * @param delta The delta tolerance.
    * @return True if they are equal, false if not.
    */
   static bool equals(float f1, float f2, float delta=FLOAT_DELTA) {    
	   return abs(f1 - f2) <= delta;
   }

   /**
    * Compare if two floats are equals within the given delta tolerance.
    * 
    * @param f1 A float
    * @param f2 Another float
    * @param delta The delta tolerance.
    * @return True if they are equal, false if not.
    */
   static bool equals(double f1, double f2, double delta=DOUBLE_DELTA) {
      return abs(f1 - f2) <= delta;
   }

   /**
    * If the value is bigger than 1, returns 1. 
	* If smaller than 0, returns 0.
	*
	* Otherwise returns the value itself.
    */
   inline float saturate(float value)
   {
	   return value > 1.0f ? 1.0f : (value < 0 ? 0 : value);
   }

   /**
    * If the value is bigger than 255, returns 255. 
	* If smaller than 0, returns 0.
	*
	* Otherwise returns the value itself.
    */
   inline int saturate(int value)
   {
	   return value > 255 ? 255 : (value < 0 ? 0 : value);
   }

   /**
    * If the value is bigger than 255, returns 255. 
	*
	* Otherwise returns the value itself.
    */
   inline unsigned saturate(unsigned value)
   {
	   return value > 255 ? 255 : value;
   }

   template<typename T>
   T padValue(T &value, T min, T max);
   template<typename T>
   T padValueCyclic(T &value, T min, T max);

   double fastSin(double radians);

   inline double fastCos(double radians)
   {
	   return fastSin(radians + MATH_PI / 2.0);
   }

   inline double fastSinDeg(double degrees)
   {
	   return fastSin(toRadians(degrees));
   }

   inline double fastCosDeg(double degrees)
   {
	   return fastCos(toRadians(degrees));
   }
}

#endif // MATHUTIL_H_INCLUDED
