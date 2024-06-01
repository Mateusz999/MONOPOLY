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

void poziomI(int num){
    if(num>0){
        gwiazdki(num);
        cout << endl;
        poziom(num-1);
    }
}
int silnia(int num){


    if(num>1){
        return num*silnia(num-1);
    }else return 1;
}

int tab[50];
void filltab(int index){
    if(index>=0){
    tab[index] = index;
    filltab(index-1);
    }
}
void selectionSort(int tab[], int num){
    for(int i =0;i<num-1;i++){
        int min=i;
        for(int j = i;j<num;j++){
            if(tab[j] < tab[min]) min = j;
        }
         if (min != i) {
            int temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
    }       
        }
    }
void draw_horizontal_border(int width) {
    if (width == 0)
        return;
    cout << '*';
    draw_horizontal_border(width - 1);
}

void draw_vertical_border(int width, int height) {
    if (height == 0)
        return;
    if (height == 1 || height == 10) {
        draw_horizontal_border(width);
        cout << endl;
    } else {
        cout << '*';
        for (int i = 0; i < width - 2; ++i)
            cout << ' ';
        cout << '*' << endl;
    }
    draw_vertical_border(width, height - 1);
}

void draw_border(int width, int height) {
    draw_vertical_border(width, height);
}

int main(){
    
draw_border(10, 5);

    return 1;
}