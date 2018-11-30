#include "ofApp.h"

using namespace ofxCv;
using namespace cv;



//--------------------------------------------------------------
void ofApp::setup(){
    Sound.load("audio.wav");
    Sound.play();
    Sound.setVolume(0.1);
    Sound.setSpeed(0.1);
    ofBackground(0,0,0);
    doorOpening = false;
    //loop = false;
    //TIMER
    //timerEnd = false;
    //startTime = ofGetElapsedTimef();
    //randVal = 10;
    
    //CV STUFF
    
    camera.setDeviceID(0);
    camera.setup(320, 240);
    
    gui.setup();
    
    gui.add(lkMaxLevel.set("lkMaxLevel", 3, 0, 8));
    gui.add(lkMaxFeatures.set("lkMaxFeatures", 200, 1, 1000));
    gui.add(lkQualityLevel.set("lkQualityLevel", 0.01, 0.001, .02));
    gui.add(lkMinDistance.set("lkMinDistance", 4, 1, 16));
    gui.add(lkWinSize.set("lkWinSize", 8, 4, 64));
    gui.add(usefb.set("Use Farneback", true));
    gui.add(fbPyrScale.set("fbPyrScale", .5, 0, .99));
    gui.add(fbLevels.set("fbLevels", 4, 1, 8));
    gui.add(fbIterations.set("fbIterations", 2, 1, 8));
    gui.add(fbPolyN.set("fbPolyN", 7, 5, 10));
    gui.add(fbPolySigma.set("fbPolySigma", 1.5, 1.1, 2));
    gui.add(fbUseGaussian.set("fbUseGaussian", false));
    gui.add(fbWinSize.set("winSize", 32, 4, 64));
    
    curFlow = &fb;

}

//--------------------------------------------------------------
void ofApp::update(){
    //CV STUFF UPDATE
    camera.update();
    if(camera.isFrameNew()) {
        
        if(usefb) {
            curFlow = &fb;
            fb.setPyramidScale(fbPyrScale);
            fb.setNumLevels(fbLevels);
            fb.setWindowSize(fbWinSize);
            fb.setNumIterations(fbIterations);
            fb.setPolyN(fbPolyN);
            fb.setPolySigma(fbPolySigma);
            fb.setUseGaussian(fbUseGaussian);
        } else {
            curFlow = &lk;
            lk.setMaxFeatures(lkMaxFeatures);
            lk.setQualityLevel(lkQualityLevel);
            lk.setMinDistance(lkMinDistance);
            lk.setWindowSize(lkWinSize);
            lk.setMaxLevel(lkMaxLevel);
        }
        curFlow->calcOpticalFlow(camera); //Optical Flow on camrea.
        
        //Calculating ammount of motion---------------------------
        motion = fb.getAverageFlow();
        float filter = abs(motion.x); //Getting X axix for motion
        int mapping = ofMap(filter, 0, 7, 0, 10);//Mapping values
        currentVal = mapping;
        
        if (currentVal > previousVal){
            valChange.push_back(mapping); //adding values to vector
        }else if (currentVal < previousVal){
            currentCalcStep = calcVal(valChange, prevCalcStep);
            valChange.clear(); //returning values to function to get last element
            prevCalcStep = currentCalcStep;
        }
        previousVal = currentVal;
        
        if (currentCalcStep > 10){
            currentCalcStep = 10;
        }
        
        if (currentCalcStep == 1){
            currentCalcStep = 0;
        }
        if (currentCalcStep > 0){
            SendCurr = currentCalcStep;
            if (SendCurr != SendPre){
                value(SendCurr);
            }
            SendPre = SendCurr;
        }
//            if (doorOpening == true){
//                door(1);
//                doorOpening = false;
//        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(250, 100);
    camera.draw(0,0,640,480);
    curFlow->draw(0,0,640,480);
    
    ofDrawBitmapStringHighlight(ofToString((int) ofGetFrameRate()) + "fps", 10, 20);
    ofPopMatrix();
    gui.draw();

    
}

//--------------------------------------------------------------
void ofApp::door(float motionVal, int endVal){
    
    endTime = endVal;
    
    //cout << workingVal << endl;
    
    for(float i = 0.1; i < motionVal+0.1; i = i + 0.1){
        usleep(100000);//slight delay to gradually increase value.
        Sound.setVolume(i);
        Sound.setSpeed(i);
        //cout << "ramp up : " << i << endl;
    }

    sleep(endTime);

        for(float a = motionVal; a > 0.1; a = a - 0.1){
        usleep(100000); //delay
        Sound.setVolume(a);
        Sound.setSpeed(a);
         //cout << "ramp down : " << a << endl;
        }


    //need to add openCV motion.
    //but also look into door sensor. 
    
    
//    //cout << time << endl;
//    if(number == 1){
//        cout << "number1" << endl;
//        Sound.setSpeed(0.2);
//        Sound.setVolume(1.0);
//    }else if (number == 2){
//        cout << "number2" << endl;
//        Sound.setSpeed(0.5);
//        Sound.setVolume(1.0);
//    }else if (number == 3){
//        cout << "number3" << endl;
//        Sound.setSpeed(1);
//        Sound.setVolume(1.0);
//    }else if (number == 4){
//        cout << "number4" << endl;
//        Sound.setSpeed(1.5);
//        Sound.setVolume(1.0);
//    }

    
}

//--------------------------------------------------------------
int ofApp::calcVal(vector<int> motion, int prevVal){
    
    int currentVar;
    int prevVar;
    
    prevVar = prevVal;
    //if not empty get last element
    if (!motion.empty()){
        currentVar = motion.back();
        
        if (currentVar == prevVar){
            
            currentVar = 0;
        }
        return currentVar;
    }

    
}

//--------------------------------------------------------------
void ofApp::value(float val){
    float newVal;
    
    newVal = val/10;
    
    cout << newVal << " : " << val << endl;
    
    door(newVal, val);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    doorOpening = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
