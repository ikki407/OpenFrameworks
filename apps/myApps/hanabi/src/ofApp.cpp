#include "ofApp.h"
#include <math.h>

#define HANABI_NUMBER 5
bool button_pushed;         // ボタンが押されたかどうかのフラグ
int x,y;
int iter=0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false); //フレーム更新時に塗り潰しを無効化
    ofBackground(0);
    ofSetFrameRate(60);         // 更新フレーム頻度秒間60コマ
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    button_pushed = false;
    for(int i = 0; i < HANABI_NUMBER; i++){
        x = ofRandom(1*ofGetWidth()/4, 3*ofGetWidth()/4);
        y = ofRandom(1*ofGetHeight()/4, 3*ofGetHeight()/4);
        hanabi[i].setup(x, y);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
 
    if(button_pushed){
        ofSetColor(0, 0, 0,4);//消える速度調整
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        for(int i = 0; i < HANABI_NUMBER; i++){
            //ofSetColor(0, 0, 0, hanabi[i].iter); //半透明の黒（背景色）
//画面と同じ大きさの四角形を描画
            hanabi[i].update();
            hanabi[i].iter += 1;

        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofSetColor(0, 150, 255);
    ofDrawBitmapString("press 's' to start hanabi", 32, 32);
    ofDrawBitmapString("press 'r' to stop hanabi", 32, 64);
    if(button_pushed){
        for(int i = 0; i < HANABI_NUMBER; i++){
            ofSetColor(ofRandom(150, i%30), ofRandom(i%30, 200), ofRandom(i%30, 200));//花火の色
            hanabi[i].draw(hanabi[i].iter);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 's'){
        button_pushed = true;
    }
    if(key == 'r'){
        button_pushed = false;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
