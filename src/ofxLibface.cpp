//
//  ofxLibface.cpp
//
//  Created by Kato Tetsuro on 12/10/19.
//
//

#include "ofxLibface.h"

void ofxLibface::findFaces(ofPixelsRef pixels) {
    cv::Mat srcMat = ofxCv::toCv(pixels);
    IplImage srcIpl = srcMat;
    vector<libface::Face> tempFaces = _libface.detectFaces(&srcIpl, cvGetSize(&srcIpl));
    
    faces.clear();
    for (vector<libface::Face>::iterator it=tempFaces.begin();
         it!=tempFaces.end(); ++it) {
        faces.push_back(ofRectangle(it->getX1(), it->getY1(), it->getWidth(), it->getHeight()));
    }
}

int ofxLibface::size() {
    return faces.size();
}

vector<ofRectangle> ofxLibface::getFaces() {
    return faces;
}

ofRectangle ofxLibface::getFace(int i) {
    return faces[i];
}