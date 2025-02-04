#include "ofApp.h"

vector<int> numbers;

//--------------------------------------------------------------
void ofApp::setup()
{

	randomNumbers();
    ofBackground(255, 182, 193);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    vector<ofColor> pinkShades = 
    {
        ofColor(255, 105, 180),
        ofColor(219, 112, 147),
        ofColor(255, 20, 147)
    };

    float xOffset = ofGetWidth() / 5.5;
    float centerY = ofGetHeight() / 2;

    for (size_t i = 0; i < numbers.size(); i++) {
        float radius = numbers[i];
        ofSetColor(pinkShades[i % pinkShades.size()]);
        ofDrawCircle(xOffset * (i + 1), centerY, radius);

        ofSetColor(255);
        ofDrawBitmapString(ofToString(numbers[i]), xOffset * (i + 1) - 10, centerY + 5);
        ofSetColor(255, 0, 0);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case 'r': randomNumbers();
        break;
    case 'b': triABulles();
        break;
    case 'i': triInsertion();
        break;


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

//--------------------------------------------------------------
void ofApp::randomNumbers()
{
	numbers.clear();
	for (int i = 0; i < 5; i++) 
	{
		numbers.push_back(ofRandom(10, 100));
	}
}

//--------------------------------------------------------------
void ofApp::triABulles()
{
    bool swapped;
    do 
    {
        swapped = false;
        for (size_t i = 0; i < numbers.size() - 1; i++) 
        {
            if (numbers[i] > numbers[i + 1]) 
            {
                swap(numbers[i], numbers[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

//--------------------------------------------------------------
void ofApp::triInsertion() 
{
    for (size_t i = 1; i < numbers.size(); i++) 
    {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) 
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}
