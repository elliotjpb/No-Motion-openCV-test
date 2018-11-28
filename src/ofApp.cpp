#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    Sound.load("audio.wav");
    Sound.play();
    Sound.setVolume(0.2);
    ofBackground(0,0,0);
    //TIMER
    timerEnd = false;
    startTime = ofGetElapsedTimef();
    randVal = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (timer <= 0){
        endTime = ofRandom(5, 10);
        //cout << endTime << endl;
    }
    timer = ofGetElapsedTimef() - startTime;
    //cout << timer << endl;
    
    
    if (timer >= endTime){
        timerEnd = true;
    }
    
    if (timerEnd == true){
        //cout << "end of timer" << endl;
        int val = ofRandom(1, 5);
        //cout << val << endl;
        choose(val, endTime);
        ofResetElapsedTimeCounter();
        timerEnd = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::choose(int number, int time){
    //cout << time << endl;
    if(number == 1){
        cout << "number1" << endl;
        Sound.setSpeed(0.2);
        Sound.setVolume(1.0);
    }else if (number == 2){
        cout << "number2" << endl;
        Sound.setSpeed(0.5);
        Sound.setVolume(1.0);
    }else if (number == 3){
        cout << "number3" << endl;
        Sound.setSpeed(1);
        Sound.setVolume(1.0);
    }else if (number == 4){
        cout << "number4" << endl;
        Sound.setSpeed(1.5);
        Sound.setVolume(1.0);
    }
    
    //need a way to take current tempo value and then make a smooth transition to the next tempo value
    
    
    /*
     My python code that might help
     
     WaitTime = 0.05 //control speed
     
     while StepCounter < steps:
     
     #MicroStepping is true for all.
     gpio.output(microStepGPIO, True)
     #turning the gpio on and off tells the easy driver to take one step
     gpio.output(UpGPIOs, True)
     gpio.output(DowGPIOs, True)
     gpio.output(UpGPIOs, False)
     gpio.output(DowGPIOs, False)
     
     if WaitTime > 0.005:
     if StepCounter < steps/4.5:
     WaitTime -= 0.001
     if StepCounter > steps/4.5 and StepCounter < (steps - (steps/4.5)):
     WaitTime = 0.005
     
     if StepCounter > (steps - (steps/4.5)):
     if WaitTime < 0.05:
     WaitTime += 0.001
     
     print(WaitTime)
     StepCounter += 1
     
     */

    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

    
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
