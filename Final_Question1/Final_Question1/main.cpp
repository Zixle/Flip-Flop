#include "Flip_Flop.h"
#include "D.h"
#include "JK.h"
#include "T.h"
#include <vector>
#include <iostream>

using namespace std;
bool _clock = false; // global variable

void toggleClock (){
    // toggle clock
    _clock = !_clock; 
    
}

void test(vector<Flip_Flop*> array){
    auto it = array.begin();
    for (int i =0; i < 3; i++ ){ // going through all flip flops
        _clock = false; // reset
        
     
        
        switch (i) { // D
                
            case 0: {
                cout << "Type: D" << endl;
                cout << "PR = " << (*it)->getPre() << " CLR = " << (*it)->getCLR() << endl;
                cout << "D" << '\t' <<  "clk" << '\t' << "Q" << '\t' << "Qn" << endl;
                
                for (int j = 0; j < 4; j++ ){ //  2 bits
                    if ( j == 0 || j == 1 ){
                        static_cast<D*>(*it)->setD(0);
                    }
                    else {
                        static_cast<D*>(*it)->setD(1);
                    }
                    cout << static_cast<D*>(*it)->getD() << '\t' << _clock << '\t';
                    
                    (*it)->CLK(_clock); // generates output
                    (*it)->print();
                    
                    toggleClock();
                    
                }
                break;
        }
            case 1: { // JK
                cout << "Type: JK" << endl;
                cout << "PR = " << (*it)->getPre() << " CLR = " << (*it)->getCLR() << endl;
                cout << "J" << '\t' << "K" << '\t' <<  "clk" << '\t' << "Q" << '\t' << "Qn" << endl;
              
                static_cast<JK*>(*it)->setK(1);
                
                for (int j = 0; j < 8; j++ ){ // 3 bits
                    if ( j > 3 ){
                        static_cast<JK*>(*it)->setJ(1);
                    }
                    else {
                        static_cast<JK*>(*it)->setJ(0);
                    }
                    
                    if (j % 2 == 0 ){ // time to toggle, k
                        
                        if (static_cast<JK*>(*it)->getK() == 0){ // 0 / 2 = undefined
                            static_cast<JK*>(*it)->setK(1);
                        }
                        else {
                            static_cast<JK*>(*it)->setK(0);
                        }
                    }
                    
                    (*it)->CLK(_clock); // generates output
                    cout << static_cast<JK*>(*it)->getJ() << '\t' << static_cast<JK*>(*it)->getK() << '\t' << _clock << '\t';
                    (*it)->print();
                    
                    toggleClock();
                   
                }
                break;
            }
            case 2: { // T
                cout << "Type: T" << endl;
                cout << "PR = " << (*it)->getPre() << " CLR = " << (*it)->getCLR() << endl;
                cout << "T" << '\t' << "clk" << '\t'<<  "Q" << '\t' << "Qn" << endl;
                for (int j = 0; j < 4; j++ ){ // 1 bits
                   
                    static_cast<T*>(*it)->setT(_clock);
                   
                    (*it)->CLK(_clock); // generates output
                    cout << static_cast<T*>(*it)->getT() << '\t' << _clock << '\t';
                    (*it)->print();
                    
                    toggleClock();
                }
                break;
            }
                
                
        }
       
        it++;
    }
    cout << endl;
    
}

int main (){
    
    vector<Flip_Flop*> array;
    D *d = new D(false, false); //   D(bool D, bool preset, bool clear);
    array.push_back(d);
    
    JK *jk = new JK(false, false);  //(bool J, bool K, bool preset, bool clear)
    array.push_back(jk);
    
    T *t = new T( false, false); // (bool T, bool preset, bool clear)
    array.push_back(t);
    
    // PRE = 0 CLR = 0
    test(array);
  
   
    auto it = array.begin(); //reset
    // PRE = 1 CLR = 0
    for (int i = 0; i < array.size(); i++){
        (*it)->togglePre(); // preset is now on
        it++;
    }
    test(array);
    it = array.begin(); // reset
 
    // PRE = 0 CLR = 1
    for (int i = 0; i < array.size(); i++){
        (*it)->togglePre(); // preset is now off
        (*it)->toggleCLR(); // clear is now on
        it++;
    }
    test(array);
    it = array.begin(); // reset
    
    // PRE = 1 CLR = 1
    for (int i = 0; i < array.size(); i++){
        (*it)->togglePre(); // preset is now on
        it++;
    }
    test(array);
    it = array.begin();
    
   
    
    
}

