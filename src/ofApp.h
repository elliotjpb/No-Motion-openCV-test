#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxCv.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void door(float motionVal, int endVal);
    int calcVal(vector<int> motion, int prevVal);
    
    void value(float val);
    //void doorClosed(float motionVal);
    
    ofSoundPlayer   Sound;
    
    bool doorOpening;
    //bool loop;
    //TIMER
    
    int startTime;
    int endTime;
    int timer;
    int currentTime;
    int randVal;
    int globalTime;
    int tempMotion;
    
    int SendPre, SendCurr;
    
    
    int currentCalcStep, prevCalcStep;
    int preCal, currentCal;
    int currentVal;
    int previousVal;

    vector<int> valChange;

    
   // int endTime;
    bool timerEnd;
    
    //CV STUFF
    
    ofVideoGrabber camera;
    
    ofRectangle rect;
    
    ofxCv::FlowFarneback fb;
    ofxCv::FlowPyrLK lk;
    
    ofxCv::Flow* curFlow;
    ofxCv::FlowFarneback getFlow;
    
    ofxPanel gui;
    ofParameter<float> fbPyrScale, lkQualityLevel, fbPolySigma;
    ofParameter<int> fbLevels, lkWinSize, fbIterations, fbPolyN, fbWinSize, lkMaxLevel, lkMaxFeatures, lkMinDistance;
    ofParameter<bool> fbUseGaussian, usefb;
    
    ofVec2f motion;

};
