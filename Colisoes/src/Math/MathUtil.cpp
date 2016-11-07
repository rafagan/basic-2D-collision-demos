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

#include <algorithm>
#include "MathUtil.h"

template<typename T>
T math::padValue(T &value, T min, T max)
{
    value = std::min(std::max(value, min), max);
	return value;
}

template<typename T>
T math::padValueCyclic(T& value, T min, T max)
{
	T minValue = std::min(value, min) * -1;
	value += minValue;
	min += minValue;
	max += minValue;
	T delta = max - min;

	if (value > max)
		value -= static_cast<T>(delta * floor(max / delta));
	else if (value < min)
		value += static_cast<T>(delta * ceil(min / delta));

	value -= minValue;

	return value;
}

inline unsigned short radiansToBinary(double radians, const unsigned short precision = math::FAST_SIN_PRECISION)
{
	return static_cast<unsigned short>(math::padValueCyclic(radians, 0.0, 1.9999999 * math::MATH_PI) * precision / (2 * math::MATH_PI));
}

inline double binaryToRadians(unsigned short binary, const unsigned short precision = math::FAST_SIN_PRECISION)
{
	return math::padValueCyclic(binary, static_cast<unsigned short>(0), precision) * 2 * math::MATH_PI / precision;
}

inline unsigned short degreesToBinary(double degrees, const unsigned short precision = math::FAST_SIN_PRECISION)
{
	return static_cast<unsigned short>(math::padValueCyclic(degrees, 0.0, 359.9999999) * precision / 360);
}

inline double binaryToDegrees(unsigned short binary, const unsigned short precision = math::FAST_SIN_PRECISION)
{
	return math::padValueCyclic(binary, static_cast<unsigned short>(0), precision) * 360.0 / precision;
}

double math::fastSin(double radians)
{
	static double cache[FAST_SIN_PRECISION] =
		{ FAST_SIN_PRECISION }; //Dummy value for empty type check
	if (cache[0] == FAST_SIN_PRECISION)
		for (auto i = 0; i < FAST_SIN_PRECISION; ++i)
			cache[i] = sin(binaryToRadians(i));

	return cache[radiansToBinary(radians)];
}