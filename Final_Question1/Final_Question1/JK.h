#pragma once
#include "Flip_Flop.h"

class JK : public Flip_Flop {
    
public:
   
    JK(bool preset, bool clear) : Flip_Flop(preset, clear) {} 
    void CLK(bool clk); // virtual function
    void print();
   
    void setJ(bool J);
    void setK(bool K);
   
    bool getJ();
    bool getK();
private:
    bool _J;
    bool _K;
};
