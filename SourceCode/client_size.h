#pragma once
#define CLIENYSIZE ClientSize::instance()

class ClientSize
{
public:
    static ClientSize instance_;

    //int CLIENT_W = 1920;                   
    //int CLIENT_H = 1088;                   


    //int LOOP_X ;
    //int LOOP_Y ;

    //static const int CHIP_SIZE = 32;                   
    //static const int CHIP_NUM_X = 200;                   
    //static const int CHIP_NUM_Y = 94;                  

    //float WIDTH ;  
    //float HEIGHT ;

public:
    static ClientSize* instance() { return &instance_; }

    void initailize();

private:
    ClientSize();
    ClientSize(const ClientSize&) = delete;
};