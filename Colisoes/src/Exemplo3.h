#pragma once

#include "ofMain.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

class Exemplo3 : public ofBaseApp{
	public:
		void setup() override;
		void update() override;
		void draw() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
	private:
		BoundingCircle c;
		BoundingBox b;
		math::Vector2D position;
		math::Vector2D velocity;
		int step;

		void Exemplo3::configureNextStep();
};
