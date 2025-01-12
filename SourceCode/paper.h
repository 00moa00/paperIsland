#pragma once

class Paper
{
public :

    SpriteManager* sprPaper = nullptr;

    int num = 0;
    bool paperFlag = false;

    void init();
    void update();
    void draw();
    Paper();
    ~Paper();

    bool getPaperFlag() { return paperFlag; }
    void setPaperFlag(bool b) { paperFlag = b; }

};