#include "D.h"
#include <iostream>

using namespace std;


void D :: CLK(bool clk){ // D's version
   // _clock = clk;
    if (_preset || _clear) { // pre-defined in base class
        
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
        
        
        
        return;
    }
    if (clk){ // true / on
       
        _Q = _D;
        _Qn = !_Q; // opposite
    }
    else { // clock is off/ false
        _Q = clk;
        _Qn = !_Q;
    }
}
bool D :: getD(){
    return _D;
}

void D :: setD(bool D){
    _D = D;
}

void D :: print(){

    cout << _Q << '\t' << _Qn << endl;
    //cout << endl;
}
