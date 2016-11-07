#include "DrawUtils.h"
#include "ofMain.h"

using namespace std;
using namespace math;

void cg::drawPoint(const Vector2D& position)
{
	ofDrawLine(position.x, ofGetHeight() - position.y, position.x + 1, ofGetHeight() - position.y + 1);
}

void cg::drawLine(const Vector2D& initialPosition, const Vector2D& finalPosition)
{
	ofDrawLine(initialPosition.x, ofGetHeight() - initialPosition.y, finalPosition.x, ofGetHeight() - finalPosition.y);
}

void cg::drawCircle(const Vector2D& center, float radius)
{
	ofDrawCircle(center.x, ofGetHeight() - center.y, radius);
}

void cg::drawEllipse(const Vector2D& center, float radiusX, float radiusY)
{
	ofDrawEllipse(center.x, ofGetHeight() - center.y, radiusX, radiusY);
}

void cg::setColor(const Vector3D& color)
{
	ofSetColor(static_cast<int>(color.x), static_cast<int>(color.y), static_cast<int>(color.z));
}

void cg::drawImage(const Vector2D& position, const ofImage& image, bool center)
{
	image.draw(position.x - (center ? image.getWidth() / 2.0f : 0.0f), ofGetHeight() - position.y - (center ? image.getHeight() / 2.0f : 0.0f));
}

void cg::drawImage(const Vector2D& position, const Vector2D& dimensions, const ofImage& image, unsigned int index, bool center)
{
	unsigned int numQuads[2] = {
		static_cast<unsigned int>(image.getWidth() / dimensions.x), 
		static_cast<unsigned int>(image.getHeight() / dimensions.y) 
	};
	auto maxIndex = numQuads[0] * numQuads[1];
	index = index % maxIndex;
	auto quadLeftUpCorner = Vector2D(dimensions.x * (index % numQuads[0]), dimensions.y * floor(index / numQuads[0]));

	image.drawSubsection(
		position.x - (center ? dimensions.x / 2.0f : 0.0f), 
		ofGetHeight() - position.y - (center ? dimensions.y / 2.0f : 0.0f),
		dimensions.x, dimensions.y, quadLeftUpCorner.x, quadLeftUpCorner.y);
}

void cg::drawBox(const Vector2D& position, const Vector2D& size)
{
	//Já desenha no centro
	ofDrawPlane(position.x, ofGetHeight() - position.y, size.x, size.y);
}