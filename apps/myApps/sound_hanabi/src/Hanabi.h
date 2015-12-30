//
//  Hanabi.h
//  hanabi
//
//  Created by fujinohiroki on 2015/08/25.
//
//

#ifndef __hanabi__Hanabi__
#define __hanabi__Hanabi__

#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__hanabi__Hanabi__) */

#define NUM 150

class Hanabi{
    
public:
    void setup(float x, float y, int scaledVol);
    void update(float scaleVol);
    void draw(int i);
    void ofFadeColor(int r, int g, int b, int a);
    int iter;
    struct ofVec2f{
        ofPoint pos, vel, init;
        int brihgt;
    }pos[NUM];
    
    float gravity; // 重力
    int balance;
    float hanabi_speed;

    float color_decision;//花火の色の決定変数
    bool flash_flag;//花火が大きくなった時に光ったかのフラグ(１回だけ光る)
    ofSoundPlayer hanabiSound; //ofSoundクラスをインスタンス化(花火の音)
};