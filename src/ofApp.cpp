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
    case 'm': triFusionB();
        break;
    case 'q': triRapideB();
        break;
    case 's': melanger();



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

//--------------------------------------------------------------
void fusion(vector<int>& arr, int gauche, int milieu, int droite) 
{
    vector<int> partieGauche(arr.begin() + gauche, arr.begin() + milieu + 1);
    vector<int> partieDroite(arr.begin() + milieu + 1, arr.begin() + droite + 1);

    int i = 0, j = 0, k = gauche;
    while (i < partieGauche.size() && j < partieDroite.size()) 
    {
        if (partieGauche[i] <= partieDroite[j]) 
        {
            arr[k++] = partieGauche[i++];
        }
        else 
        {
            arr[k++] = partieDroite[j++];
        }
    }
    while (i < partieGauche.size()) arr[k++] = partieGauche[i++];
    while (j < partieDroite.size()) arr[k++] = partieDroite[j++];
}
//--------------------------------------------------------------
void triFusionA(vector<int>& arr, int gauche, int droite)
{
    if (gauche < droite) 
    {
        int milieu = gauche + (droite - gauche) / 2;
        triFusionA(arr, gauche, milieu);
        triFusionA(arr, milieu + 1, droite);
        fusion(arr, gauche, milieu, droite);
    }
}

//--------------------------------------------------------------
void ofApp::triFusionB() 
{
    triFusionA(numbers, 0, numbers.size() - 1);
}


//--------------------------------------------------------------
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    
    for (j ; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}

//--------------------------------------------------------------
void triRapideA(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot = partition(arr, low, high);
        triRapideA(arr, low, pivot - 1);
        triRapideA(arr, pivot + 1, high);
    }
}

//--------------------------------------------------------------
void ofApp::triRapideB() 
{
    triRapideA(numbers, 0, numbers.size() - 1);
}

//--------------------------------------------------------------
void ofApp::melanger() 
{
    for (int i = numbers.size() - 1; i > 0; i--) 
    {
        int j = ofRandom(0, i + 1);
        swap(numbers[i], numbers[j]);
    }
}
