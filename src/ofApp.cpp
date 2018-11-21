#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    sampleRate    = 44100; /* Sampling Rate */
    bufferSize    = 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    mySample.load(ofToDataPath("audio.wav"));
    ofBackground(0,0,0);
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
    value = 1; //default speed value
    
    //TIMER
    
    timerEnd = false;
    
    startTime = ofGetElapsedTimef();
    randVal = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (timer <= 0){
        endTime = ofRandom(5, 10);
    }
    timer = ofGetElapsedTimef() - startTime;
    //cout << timer << endl;
    
    
    if (timer >= endTime){
        timerEnd = true;
    }
    
    if (timerEnd == true){
        //cout << "end of timer" << endl;
        int val = ofRandom(1, 5);
        cout << val << endl;
        choose(val);
        ofResetElapsedTimeCounter();
        timerEnd = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::choose(int number){
    
        if(number == 1){
        
        cout << "number1" << endl;
            value = 0.2;
    }else if (number == 2){
        cout << "number2" << endl;
        value = 0.5;
    }else if (number == 3){
        cout << "number3" << endl;
        value = 1;
    }else if (number == 4){
        cout << "number4" << endl;
        value = 1.5;
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
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    for (int i = 0; i < bufferSize; i++){
        wave = mySample.play(value);//play the file with a speed setting.
        output[i*nChannels    ] = wave;
        output[i*nChannels + 1] = wave;
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    value = 1.5;
    
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
