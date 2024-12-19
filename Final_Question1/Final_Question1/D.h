#pragma once
#include "Flip_Flop.h"


 class D : public Flip_Flop {
    
public:
     
     D(bool preset, bool clear) : Flip_Flop(preset, clear) {} // constructor
     void CLK(bool clk); // virutal function
     void print();
     void getInputs();
     void setD(bool D);
     bool getD();
     
private:
     bool _D; // input 
    
};
