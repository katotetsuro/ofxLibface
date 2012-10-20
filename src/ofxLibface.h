//
//  ofxLibface.h
//
//  Created by Kato Tetsuro on 12/10/19.
//
//

#ifndef __ofxLibface__
#define __ofxLibface__

#include "ofMain.h"
#include "ofxCv.h"
#include "LibFace.h"

class ofxLibface {
private:
    vector<ofRectangle> faces;
    libface::LibFace _libface;
public:
    void findFaces(ofPixelsRef pixels);
    int  size();
    vector<ofRectangle> getFaces();
    ofRectangle getFace(int i);
};

#endif /* defined(__ofxLibface__) */
