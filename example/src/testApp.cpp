#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    vidGrabber.initGrabber(320, 240);
    
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()) {
        detector.findFaces(vidGrabber.getPixelsRef());
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    vidGrabber.draw(0, 0);
    int size = detector.size();
    ofNoFill();
    ofSetColor(ofColor::yellow);
    for (int i=0; i<size; ++i) {
        ofRect(detector.getFace(i));
    }
    ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}