#include <iostream>

using namespace std;
int sum=0;
int fib(int num){

    if(num>2){
     
        sum= fib(num-2)+fib(num-1);  
           return sum;
    }else return 1;
    
}
int result=0;
int summ(int num){
    if(num> 1){
    result +=  fib(num);
    summ(num-1);
     return result+1;
    }else return 1;
 
}
int main(){

cout <<  fib(1)<<endl;
cout <<  fib(2)<<endl;
cout <<  fib(3)<<endl;
cout <<  fib(4)<<endl;
cout <<  fib(5)<<endl;
cout <<  fib(6)<<endl;
cout <<  fib(7)<<endl;
cout <<  fib(8)<<endl;
cout <<  summ(7)<<endl;



    return 0;
}