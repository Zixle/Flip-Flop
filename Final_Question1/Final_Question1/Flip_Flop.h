#pragma once


class Flip_Flop {
    
public:
    
    Flip_Flop(bool preset, bool clear); // constructor
    
    bool getQ();
    bool getQn();
    bool getOutput();
    bool getCLR();
    bool getPre();
    
    void togglePre();
    void toggleCLR();
    
    virtual void CLK(bool clk) = 0;
    virtual void print() = 0;
  
    
protected:
  
    bool _preset;
    bool _clear;
  
    // outputs
    bool _Q;
    bool _Qn;
};
