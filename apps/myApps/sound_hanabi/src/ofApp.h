#pragma once

#include "ofMain.h"
#include "Hanabi.h"
#include <vector>

class ofApp : public ofBaseApp{
private:
    ofImage image;
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioIn(float * input, int bufferSize, int nChannels);
    ofSoundStream soundStream;
    float curVol;
    float smoothedVol;
    float scaledVol,scaledVol2;

    vector<Hanabi> hanabi;
    vector<float> radius;
    bool button_pushed;         // ボタンが押されたかどうかのフラグ
    float x,y;                  // 花火の中心座標
    int generate_count = 0;       // 花火生成回数
    bool generate_flag = true;      // 花火を生成できるかどうかのフラグ
    clock_t start_time, now_time;   // 花火生成時間と現在の時間
    ofSoundPlayer mySound; //ofSoundクラスをインスタンス化(会場の音再現。いらなかったら消して)
};
