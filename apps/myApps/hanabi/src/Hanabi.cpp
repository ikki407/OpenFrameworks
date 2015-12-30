//
//  Hanabi.cpp
//  hanabi
//
//  Created by fujinohiroki on 2015/08/19.
//
//

#include "Hanabi.h"
#include "math.h"

#define VEC_LENGTH 50
#define VEC_SPEED 5
#define SPEED_RATE 0.25
int scale;
int a;

void Hanabi::setup(int x, int y){
    
    // 花火の初期位置とスピードの初期化
    for(int i = 0; i < NUM; i++){
        pos[i].pos = ofPoint(x,y);
        pos[i].init = ofPoint(x,y);
        ofSeedRandom(x);
        //scale = ofRandomf()*10;
        balance = i % 5+1;
        pos[i].vel = ofPoint((balance + VEC_SPEED) * SPEED_RATE * cos((i/(1.0*NUM))*2.0*M_PI), (balance + VEC_SPEED) * SPEED_RATE * sin((i/(1.0*NUM))*2.0*M_PI));
        iter = 100;
        
    }
    // 重力の設定
    gravity = 0.0000001;
    balance = 0;
}

void Hanabi::update(){

    // 長さ1のベクトルを360°を100分割して、動かす
    for(int i = 0; i < NUM; i++){
        //gravity
        pos[i].vel.y = pos[i].vel.y + gravity;
        
        //friction
        pos[i].vel *= .9999;
        
        
        if( sqrt((pos[i].pos.x - pos[i].init.x)*(pos[i].pos.x - pos[i].init.x) + (pos[i].pos.y - pos[i].init.y)*(pos[i].pos.y - pos[i].init.y) )<130){//半径
            if ((abs(pos[i].vel.y)<0.02) and (abs(pos[i].vel.x) < 0.02)){//半径超えたら
                pos[i].pos.x = -99;
                pos[i].pos.y = -99;
            }
            pos[i].pos.x += pos[i].vel.x;
            pos[i].pos.y += pos[i].vel.y;
            pos[i].vel.x *= 0.99;
            pos[i].vel.y *= 0.99;
            //pos[i].pos.y *= gravity;
            a =sqrt((pos[i].pos.x - pos[i].init.x)*(pos[i].pos.x - pos[i].init.x) + (pos[i].pos.y - pos[i].init.y)*(pos[i].pos.y - pos[i].init.y) );

            //pos[i].brihgt *= 0.9999;
        }
        
        else{
            pos[i].pos.x = -999;
            pos[i].pos.y = -999;
            ofBackground(255, 255, 255);//花火が大きくなった時に背景を光らせる
            ofBackground(0, 0, 0);//花火が大きくなった時に背景を光らせる
        }
        
        //update pos
        //pos[i].pos.y += pos[i].vel.y;
    }
    
}

void Hanabi::draw(int iter){
    for(int i = 0; i < NUM; i++){
        if((i%5)==4){
            ofSetColor(ofRandom(255,255), ofRandom(50, 50), ofRandom(0,0));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==3){
            ofSetColor(ofRandom(200,200), ofRandom(0, 0), ofRandom(100,100));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==2){
            ofSetColor(ofRandom(150,150), ofRandom(0, 0), ofRandom(150,150));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==1){
            ofSetColor(ofRandom(100,100), ofRandom(0, 0), ofRandom(200,200));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else{
            ofSetColor(ofRandom(50, 50), ofRandom(0, 0), ofRandom(170, 170));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        //ofCircle(pos[i].x, pos[i].y, pos[i].x + VEC_LENGTH * cos((i/(1.0*NUM))*2.0*M_PI), pos[i].y + VEC_LENGTH * sin((i/(1.0*NUM))*2.0*M_PI));
    }
    
}

