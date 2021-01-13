
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

// GPIO Set up     
pi = pigpio_start(NULL, NULL); 

    if (pi < 0)
    {
	cout << "can't initialise Pi" << endl;
	ofExit();
    } 
    else
    {	
	cout << "init success" << endl;
    }

    GPIO = 18;
    set_mode	(pi, GPIO, PI_OUTPUT);
    gpio_write	(pi, GPIO, 0);

    time = ofGetElapsedTimeMillis() * 0.001;

// SERIAL set-up
serial.listDevices();
vector<ofSerialDeviceInfo> devList = serial.getDeviceList();
serial.setup("/dev/ttyAMA0", 9600);

}

//--------------------------------------------------------------
void ofApp::update(){

    time = ofGetElapsedTimeMillis() * 0.001;

    if(!(time % 2))
    {
	gpio_write(pi, GPIO, 1);
    }
    else
    {
	gpio_write(pi, GPIO, 0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapString(ofToString(time), 10,10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    cout << key << " : " << static_cast<char>(key) << endl;

    if(static_cast<char>(key) == 'o')
    {
	serial.writeBytes("~0000 1\r", 8);
	cout << "wrote 8 bytes" << endl;
    } 
    
    if(static_cast<char>(key) == 'f')
    {
	serial.writeBytes("~0000 0\r", 8);
	cout << "wrote 8 bytes" << endl;
    } 

    if(static_cast<char>(key) == 'm')
    {
	serial.writeBytes("~00195 1\r", 9);
	cout << "wrote 9 bytes" << endl;
    } 

    if(static_cast<char>(key) == 'u')
    {
	serial.writeBytes("~00195 0\r", 9);
	cout << "wrote 9 bytes" << endl;
    } 

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
