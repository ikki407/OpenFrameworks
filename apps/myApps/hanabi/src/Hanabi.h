//
//  Hanabi.h
//  hanabi
//
//  Created by fujinohiroki on 2015/08/19.
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
    void setup(int x, int y);
    void update();
    void draw(int iter);
    void ofFadeColor(int r, int g, int b, int a);
    int iter;
    struct ofVec2f{
        ofPoint pos, vel, init;
        int brihgt;
        
    }pos[NUM];
    
    float gravity; // 重力
    
    int now_time;
    int balance;
};