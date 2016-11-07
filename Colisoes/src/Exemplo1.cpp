#include "Exemplo1.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo1::setup(){
	step = 0;
}

//--------------------------------------------------------------
void Exemplo1::configureNextStep()
{
	if (step == 0) {
		velocity = Vector2D(0, 200);
		rect1.x = 300;
		rect1.y = 0;
		rect1.width = 70;
		rect1.height = 100;

		rect2.x = 300;
		rect2.y = 400;
		rect2.width = 100;
		rect2.height = 100;

		step = 1;
	}
	else if (step == 1) {
		if (rect1.y > ofGetHeight())
			step = 2;
	}
	else if (step == 2) {
		velocity = Vector2D(200, 0);

		rect1.x = 100;
		rect1.y = 200;
		rect1.width = 100;
		rect1.height = 70;

		rect2.x = 500;
		rect2.y = 200;
		rect2.width = 100;
		rect2.height = 100;

		step = 3;
	}
	else if (step == 3) {
		if (rect1.x > ofGetWidth())
			step = 4;
	}
	else if (step == 4) {
		std::exit(0);
	}
}

void Exemplo1::update(){
	configureNextStep();
	
	auto dt = ofGetLastFrameTime();
	rect1.x += velocity.x * dt;
	rect1.y += velocity.y * dt;
}

//--------------------------------------------------------------
void Exemplo1::draw(){
	ofSetBackgroundColor(0, 0, 0);

	cg::setColor(Vector3D(255, 255, 255));
	cg::drawBox(Vector2D(rect2.x, rect2.y), Vector2D(rect2.width, rect2.height));

	AABBCollisionCheck(&rect1, &rect2) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawBox(Vector2D(rect1.x, rect1.y), Vector2D(rect1.width, rect1.height));
}

//--------------------------------------------------------------
void Exemplo1::keyPressed(int key){
	
}

//--------------------------------------------------------------
void Exemplo1::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo1::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Exemplo1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo1::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo1::dragEvent(ofDragInfo dragInfo){ 

}
