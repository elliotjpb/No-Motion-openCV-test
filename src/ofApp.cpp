#include "ofApp.h"


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
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //doorOpen = true;
    
    //if (doorOpen == true){
    
    if (doorOpening == true){
        doorOpen(0.5);
        doorOpening = false;
    }

    
//    if (timer <= 0){
//        endTime = ofRandom(5, 10);
//        //cout << endTime << endl;
//    }
//    timer = ofGetElapsedTimef() - startTime;
//    //cout << timer << endl;
//
//
//    if (timer >= endTime){
//        timerEnd = true;
//    }
//
//    if (timerEnd == true){
//        //cout << "end of timer" << endl;
//        int val = ofRandom(1, 5);
//        //cout << val << endl;
//        choose(val, endTime);
//        ofResetElapsedTimeCounter();
//        timerEnd = false;
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::doorOpen(float motionVal){
    int startTime = ofGetElapsedTimef();
    int endTime = motionVal * 10;
    int timer = ofGetElapsedTimef() - startTime;
    cout << timer << endl;
    //motionVal + 0.1;
    
    for(float i = 0.1; i < motionVal+0.1; i = i + 0.1){
        usleep(100000);//slight delay to gradually increase value.
        Sound.setVolume(i);
        Sound.setSpeed(i);
        cout << "ramp up : " << i << endl;
    }
    
    sleep(endTime);
        
        for(float a = motionVal; a > 0.1; a = a - 0.1){
        usleep(100000); //delay
        Sound.setVolume(a);
        Sound.setSpeed(a);
         cout << "ramp down : " << a << endl;
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
