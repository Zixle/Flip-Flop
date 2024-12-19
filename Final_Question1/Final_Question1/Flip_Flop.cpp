#include "Flip_Flop.h"
#include <iostream>

using namespace std;

Flip_Flop :: Flip_Flop (bool preset, bool clear){
    _preset = preset;
    _clear = clear;
   // _clock = false;
    
    
    _Q = false;
    _Qn = !_Q; 
    
   
    if (_preset){ // true
        _Q = true;
        _Qn = false;
    }
    else {
        _Q = false;
        _Qn = true;
    }
    
    if (_clear){ // true
        _Q = false;
        _Qn = true;
    }
    else {
        _Q = true;
        _Qn = false;
    }
    
    
     
}

void Flip_Flop :: togglePre(){
    _preset =  !_preset; 
}

void Flip_Flop :: toggleCLR() {
    _clear = !_clear; 
}
    


bool Flip_Flop:: getPre() {
    return _preset;
}
bool Flip_Flop:: getCLR() {
    return _clear;
}


bool Flip_Flop :: getQ(){
    return _Q;
}

bool Flip_Flop :: getQn(){
    return _Qn; 
}



