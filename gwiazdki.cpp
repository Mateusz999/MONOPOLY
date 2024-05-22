#include <iostream>
using namespace std;
void gwiazdki(int num){
    if(num>0){
        cout << "*";
        gwiazdki(num-1);
        
    }
};
void poziom(int num){
    if(num>0){
        gwiazdki(num);
        cout << endl;
        poziom(num-1);
    }
}
void gwiazdkiInvert(int start,int stop){
    if(start<stop){
        cout << "*";
        gwiazdkiInvert(stop-start+1,stop);
        
    }
};
void poziomInvert(int start,int stop){
    if(stop>0){
        gwiazdkiInvert(start,stop);
        cout << endl;
        poziom(stop-1);
    }
}


int main(){

poziom(5);
gwiazdkiInvert(1,5);
poziomInvert(1,5);
    return 1;
}