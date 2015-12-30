#include "ofApp.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false); //フレーム更新時に塗り潰しを無効化
    ofBackground(0,0,0,255);
    image.loadImage("image.png");    //背景画像

    ofSetFrameRate(60);         // 更新フレーム頻度秒間60コマ
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    button_pushed = false;
    soundStream.listDevices();
    soundStream.setup(this, 0, 1, 44100, 256, 4);
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    //mySound.loadSound("town_summer_fes1.mp3"); //サウンドファイルの読込み(会場音)
    //mySound.setVolume(0.5);
    //mySound.setLoop(true); //ループ再生をONに
    //mySound.play(); //サウンド再生開始
}

//--------------------------------------------------------------
void ofApp::update(){
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
    //scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    now_time = clock();
    if(((double)(now_time - start_time) / CLOCKS_PER_SEC) > 0.03){
        generate_flag = true;
    }
    if(generate_flag && scaledVol/1000 > 0.001){
        start_time = clock();
        generate_count++;
        hanabi.push_back(Hanabi());
        ofSeedRandom();
        x = ofRandom(1*ofGetWidth()/4, 3*ofGetWidth()/4);
        y = ofRandom(1*ofGetHeight()/5, 4*ofGetHeight()/5);
        hanabi[generate_count-1].setup(x, y,scaledVol2);
        radius.push_back(scaledVol*50000.f);
        generate_flag = false;
    }

    ofSetColor(0, 0, 0,5);//消える速度調整
    image.draw(0, 0, ofGetWidth(), ofGetHeight());

    //ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i = 0; i < hanabi.size(); i++){
        hanabi[i].update(radius[i]);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0,0);
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 150, 255);
    ofDrawBitmapString("please input sound to create fire flower", 32, 32);
    for(int i = 0; i < hanabi.size(); i++){
        hanabi[i].draw(i * ofRandom(100000));
    }

}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    curVol = 0.0;
    
    for(int i = 0; i < bufferSize; i++){
        curVol += input[i]*input[i];
    }
    
    curVol /= bufferSize;
    smoothedVol *= 0.93;
    smoothedVol += 0.7 * curVol;
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    scaledVol2 = ofMap(smoothedVol, 0.0, 1.0, 0.0, 5.0, true);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
