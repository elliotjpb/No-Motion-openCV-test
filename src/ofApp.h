#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxOsc.h"

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
    
    void choose(int number, int time);
    
    ofSoundPlayer   Sound;
    
    //TIMER
    
    int startTime;
    int currentTime;
    int randVal;
    int globalTime;
    int timer;
    int endTime;
    bool timerEnd;
};
