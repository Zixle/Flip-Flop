#include "Jk.h"

#include <iostream>

using namespace std;



void JK :: CLK(bool clk){ // JK's version
   // _clock = clk;
    // for Q
    if (_preset || _clear){
        
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
        
        
        
        return; // already preset
        
    }
    
    if (clk){ // true/ on
        _Q = ((_Q && !_K) || (!_Qn && _J));
        _Qn = !_Q; 
    }
   
}

bool JK ::  getJ(){
    return _J;
}

bool JK :: getK(){
    return _K; 
}

void JK :: setJ(bool J) {
    _J = J; 
}

void JK :: setK(bool K) {
    _K = K; 
}

void JK :: print(){

    
    cout << _Q << '\t' << _Qn << endl;
    //cout << endl;
}
