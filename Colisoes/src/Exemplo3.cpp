#include "Exemplo3.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo3::setup(){
	step = 0;

	c.x = 300;
	c.y = 150;
	c.radius = 50;

	position.set(600, 200);
	b.width = 100;
	b.height = 200;

	velocity = Vector2D(50, 0);
}

//--------------------------------------------------------------
void Exemplo3::configureNextStep()
{
	if (step == 0) {
		velocity = Vector2D(100, 0);
		c.x = 150;
		c.y = 300;
		c.radius = 50;

		position.set(500, 300);
		b.width = 100;
		b.height = 200;

		step = 1;
	}
	else if (step == 1) {
		if (c.x > ofGetWidth())
			step = 2;
	}
	else if (step == 2) {
		c.x = 300;
		c.y = 200;
		c.radius = 50;

		position.set(300, 400);
		b.width = 200;
		b.height = 100;

		velocity = Vector2D(0, 100);

		step = 3;
	}
	else if (step == 3) {
		if (c.y > ofGetHeight())
			step = 4;
	}
	else if (step == 4) {
		std::exit(0);
	}
}

void Exemplo3::update(){
	configureNextStep();

	auto dt = ofGetLastFrameTime();

	c.x += velocity.x * dt;
	c.y += velocity.y * dt;
}

//--------------------------------------------------------------
void Exemplo3::draw(){
	ofSetBackgroundColor(0, 0, 0);

	b.x = position.x - b.width / 2;
	b.y = position.y - b.height / 2;
	cg::setColor(Vector3D(255, 255, 255));
	cg::drawBox(Vector2D(position.x, position.y), Vector2D(b.width, b.height));

	circleBoxCollisionCheck(&b, &c) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawCircle(Vector2D(c.x, c.y), c.radius);
}

//--------------------------------------------------------------
void Exemplo3::keyPressed(int key){

}

//--------------------------------------------------------------
void Exemplo3::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo3::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Exemplo3::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo3::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo3::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo3::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo3::dragEvent(ofDragInfo dragInfo){ 

}
