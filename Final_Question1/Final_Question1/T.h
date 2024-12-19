#pragma once
#include "Flip_Flop.h"

class T : public Flip_Flop {
    
public:
    
    T(bool preset, bool clear) : Flip_Flop(preset, clear) {}
    void CLK(bool clk);
    void print();
    
    
    void setT(bool T);
    bool getT(); 
    
private:
    bool _T;
    
    
};
