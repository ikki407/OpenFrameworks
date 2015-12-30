//
//  Hanabi.cpp
//  hanabi
//
//  Created by fujinohiroki on 2015/08/25.
//
//

#include "Hanabi.h"
#include "math.h"

#define VEC_LENGTH 50
#define VEC_SPEED 1//花火の速度変化
#define SPEED_RATE 0.25

void Hanabi::setup(float x, float y, int scaledVol){
    ofSeedRandom();
    hanabi_speed = VEC_SPEED * scaledVol;//ofRandom(5*scaledVol);
    // 花火の初期位置とスピードの初期化
    for(int i = 0; i < NUM; i++){

        pos[i].pos = ofPoint(x,y);
        pos[i].init = ofPoint(x,y);

        balance = i % 5+1;

        
        pos[i].vel = ofPoint((balance + hanabi_speed) * SPEED_RATE * cos((i/(1.0*NUM))*2.0*M_PI), (balance + hanabi_speed) * SPEED_RATE * sin((i/(1.0*NUM))*2.0*M_PI));
        iter = 100;
        
    }
    // 重力の設定
    gravity = 0.00001;
    balance = 0;
    //光ったかのフラグ
    flash_flag = true;
    
}

void Hanabi::update(float scaleVol){
    // 長さ1のベクトルを360°を100分割して、動かす
    for(int i = 0; i < NUM; i++){
        //gravity
        pos[i].vel.y = pos[i].vel.y + gravity;
        
        //friction
        pos[i].vel *= .9999;
        
        
        if( sqrt((pos[i].pos.x - pos[i].init.x)*(pos[i].pos.x - pos[i].init.x) + (pos[i].pos.y - pos[i].init.y)*(pos[i].pos.y - pos[i].init.y) )<scaleVol){
            if ((abs(pos[i].vel.y)<0.03) and (abs(pos[i].vel.x) < 0.03)){//速度がある定数以下になったら消えていく
                pos[i].pos.x = -99;
                pos[i].pos.y = -99;
            }
            if ((abs(pos[i].vel.y)<0.08) and (abs(pos[i].vel.x) < 0.08)){//速度がある定数以下になった時に周囲が光る
                if (flash_flag) {//
                        for(int k = 0;k < 50; k++){
                            ofSetColor(255, 255, 255, 0.05*k);
                            ofEllipse(pos[i].init.x, pos[i].init.y, 1520 - 20 * k, 1520 - 20 * k);//光の調整
                        }

                    flash_flag = false;
                    hanabiSound.loadSound("fireworks_ver3.mp3"); //サウンドファイルの読込み
                    hanabiSound.setLoop(false); //ループ再生をONに
                    hanabiSound.setVolume(sqrt(hanabi_speed*0.2));//音量を花火の大きさで変更
                    hanabiSound.play(); //サウンド再生開始
                }
            }
            pos[i].pos.x += pos[i].vel.x;
            pos[i].pos.y += pos[i].vel.y;
            pos[i].vel.x *= 0.99;
            pos[i].vel.y *= 0.99;
        }else{
            pos[i].pos.x = -999;
            pos[i].pos.y = -999;

        }
        
    }
    
}

void Hanabi::draw(int i){
    //ofSetColor(0, 0, 0,5);//消える速度調整
    //ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSeedRandom(i);//花火の色を１つの花火では固定する乱数のシード
    color_decision = ofRandomf();//花火の色を決定する決定変数
    if(color_decision<-0.6){//花火の色をランダムに変化させる
    for(int i = 0; i < NUM; i++){//赤と青のグラデーション
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
    }
    }
    
    else if(color_decision>=-0.6 && color_decision<-0.2){//青のみ
    for(int i = 0; i < NUM; i++){
        if((i%5)==4){
            ofSetColor(ofRandom(0,0), ofRandom(0, 0), ofRandom(250,250));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==3){
            ofSetColor(ofRandom(0,0), ofRandom(0, 0), ofRandom(100,100));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==2){
            ofSetColor(ofRandom(0,0), ofRandom(0, 0), ofRandom(150,150));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else if((i%5)==1){
            ofSetColor(ofRandom(0,0), ofRandom(0, 0), ofRandom(200,200));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
        else{
            ofSetColor(ofRandom(0, 0), ofRandom(0, 0), ofRandom(170, 170));//花火の色
            ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
        }
    }
    }
    
    else if(color_decision>=-0.2 && color_decision<0.2){
        for(int i = 0; i < NUM; i++){//
            if((i%5)==4){
                ofSetColor(ofRandom(0,0), ofRandom(250, 250), ofRandom(50,50));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==3){
                ofSetColor(ofRandom(0,0), ofRandom(220, 220), ofRandom(100,100));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==2){
                ofSetColor(ofRandom(0,0), ofRandom(150, 150), ofRandom(100,100));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==1){
                ofSetColor(ofRandom(0,0), ofRandom(100, 100), ofRandom(60,60));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else{
                ofSetColor(ofRandom(0, 0), ofRandom(50, 50), ofRandom(50, 50));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
        }
    }
    
    else if(color_decision>=0.2 && color_decision<0.6){
        for(int i = 0; i < NUM; i++){//
            if((i%5)==4){
                ofSetColor(ofRandom(50,50), ofRandom(0, 0), ofRandom(50,50));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==3){
                ofSetColor(ofRandom(100,100), ofRandom(50, 50), ofRandom(50,50));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==2){
                ofSetColor(ofRandom(100,100), ofRandom(100, 100), ofRandom(50,50));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==1){
                ofSetColor(ofRandom(150,150), ofRandom(150, 150), ofRandom(0,0));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else{
                ofSetColor(ofRandom(150, 0), ofRandom(200, 200), ofRandom(0, 0));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
        }
    }
    
    else if(color_decision>=0.6){
        for(int i = 0; i < NUM; i++){//
            if((i%5)==4){
                ofSetColor(ofRandom(30,30), ofRandom(60, 60), ofRandom(250,250));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==3){
                ofSetColor(ofRandom(0,0), ofRandom(100, 100), ofRandom(100,100));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==2){
                ofSetColor(ofRandom(100,100), ofRandom(0, 0), ofRandom(150,150));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else if((i%5)==1){
                ofSetColor(ofRandom(0,0), ofRandom(150, 150), ofRandom(200,200));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
            else{
                ofSetColor(ofRandom(200, 200), ofRandom(0, 0), ofRandom(170, 170));//花火の色
                ofCircle(pos[i].pos.x, pos[i].pos.y, 3);
            }
        }
    }

}

