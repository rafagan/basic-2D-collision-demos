#include "Exemplo4.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo4::setup(){
	ofHideCursor();

	color1 = Vector3D(255, 0, 0);
	color2 = Vector3D(0, 255, 0);
	color3 = Vector3D(255, 255, 0);
	
	colors[0] = color1;
	colors[1] = color2;

	b1.width = b2.width = 100;
	b1.height = b2.height = 100;
	c1.radius = c2.radius = 100;

	b2.x = c2.x = 600;
	b2.y = c2.y = 300;

	pressedButton = 1;
}

//--------------------------------------------------------------
void Exemplo4::update(){
	switch (pressedButton) {
		case 1:
			b1.x = mouse.x;
			b1.y = mouse.y;

			//TODO: Fazer o teste com os outros algoritmos de bounding box implementados
			colors[0] = AABBOffsetCollisionCheck(&b1, &b2) ? color3 : color2;
			break;
		case 2:
			c1.x = mouse.x;
			c1.y = mouse.y;

			colors[0] = circleCollisionCheck(&c1, &c2) ? color3 : color2;
			break;
		case 3:
			c1.x = mouse.x;
			c1.y = mouse.y;

			colors[0] = circleBoxCollisionCheck(&b2, &c1) ? color3 : color2;
			break;
		case 4:
			Point p;
			p.x = mouse.x;
			p.y = mouse.y;

			colors[1] = pointBoxCollisionCheck(&p, &b2) ? color3 : color2;
			break;
	}
}

//--------------------------------------------------------------
void Exemplo4::draw(){
	ofSetBackgroundColor(0, 0, 0);

	switch (pressedButton) {
	case 1:
		cg::setColor(colors[1]);
		cg::drawBox(Vector2D(b2.x, b2.y), Vector2D(b2.width, b2.height));
		cg::setColor(colors[0]);
		cg::drawBox(Vector2D(b1.x, b1.y), Vector2D(b1.width, b1.height));
		break;
	case 2:
		cg::setColor(colors[1]);
		cg::drawCircle(Vector2D(c2.x, c2.y), c2.radius);
		cg::setColor(colors[0]);
		cg::drawCircle(Vector2D(c1.x, c1.y), c1.radius);
		break;
	case 3:
		cg::setColor(colors[1]);
		cg::drawCircle(Vector2D(c1.x, c1.y), c1.radius);
		cg::setColor(colors[0]);
		cg::drawBox(Vector2D(b2.x + b2.width / 2, b2.y + b2.height / 2), Vector2D(b2.width, b2.height));
		break;
	case 4:
		cg::setColor(colors[1]);
		cg::drawBox(Vector2D(b2.x + b2.width / 2, b2.y + b2.height / 2), Vector2D(b2.width, b2.height));
		cg::setColor(colors[0]);
		cg::drawCircle(Vector2D(mouse.x, mouse.y), 1);
		break;
	}
}

//--------------------------------------------------------------
void Exemplo4::keyPressed(int key){
	if (isdigit(key))
		pressedButton = key - '0';
}

//--------------------------------------------------------------
void Exemplo4::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo4::mouseMoved(int x, int y ){
	mouse = Vector2D(x, ofGetHeight() - y);
}

//--------------------------------------------------------------
void Exemplo4::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo4::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo4::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo4::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo4::dragEvent(ofDragInfo dragInfo){ 

}
