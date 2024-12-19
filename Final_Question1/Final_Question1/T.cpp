#include "T.h"
#include <iostream>

using namespace std;

void T:: CLK(bool clk){
    //s_clock = clk;
    // / if T is on, The output toggles its state on the triggering clock edge.
    // if T is off, The output (Q) remains the same, regardless of the clock signal.
    if ( _preset || _clear){
        
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
        
        return; // preset already
    }
    
    
    if (_T && clk ){ // on, q toggles
        if (_Q){
            _Q = _Qn;
        }
        else {
            _Q = true;
        }
        _Qn = !_Q;
    }
    else { // t is off/ zero, outpu stays the same
        return;
    }
    
}

bool T :: getT() {
    return _T;
}

void T :: setT(bool T){
    _T = T; 
}

void T :: print(){
    
    cout << _Q << '\t' << _Qn << endl;
    //cout << endl;
}
