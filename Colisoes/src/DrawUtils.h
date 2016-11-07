#pragma once

#include "Math/Vector2D.h"
#include "Math/Vector3D.h"
#include <ofImage.h>

namespace cg
{
	void drawPoint(const math::Vector2D& position);
	void drawLine(const math::Vector2D& initialPosition, const math::Vector2D& finalPosition);
	void drawEllipse(const math::Vector2D& center, float radiusX, float radiusY);
	void drawCircle(const math::Vector2D& center, float radius);
	void setColor(const math::Vector3D& color);
	void drawImage(const math::Vector2D& position, const ofImage& image, bool center = true);
	void drawImage(const math::Vector2D& position, const math::Vector2D& dimensions, const ofImage& image, unsigned int index, bool center = true);
	void drawBox(const math::Vector2D& position, const math::Vector2D& dimensions);
}