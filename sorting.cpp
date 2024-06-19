#include<iostream>

using namespace std;
int tab[20];
void fill(){
    for(int i = 0; i < 20; i++){
        tab[i] = rand()%100;
    }
}

void drawS(int tab[]){
    for(int i = 0; i < 20; i++){
        cout << " " << tab[i] << " "<<endl;
    }
}
void draw(){
    for(int i = 0; i < 20; i++){
        cout << " " << tab[i] << " "<<endl;
    }
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortS(int tab[20]) {
    for (int i = 0; i < 20 - 1; i++) {
        int min = i;
        for (int j = i + 1; j < 20; j++) {
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        swap(&tab[min], &tab[i]);
    }
}
void swapp(int*a, int*b){
int  temp=*a;
*a=*b;
*b=temp;
}
void test(int tab[20]){
    for(int i =0;i<20-1;i++){
        int min =i;
        for(int j =i+1;j<20;j++){
            if(tab[j] < tab[min]) min=j;
        }
        swapp(&tab[min],&tab[i]);
    }
}
int main(){
  
fill();

test(tab);
drawS(tab);

    return 0;
}