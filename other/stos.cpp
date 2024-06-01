#include <iostream>
#include<fstream>
using namespace std;
struct osoba{
    string imie;
    osoba* next;
};
osoba* pocz = NULL;


void menu(){
    cout << "1. dodaj rekord"<<endl;
    cout << "2. wyswietl rekord"<<endl;
    cout << "0. wyjdz"<<endl;
    cout << "twoj wybor: ";
}
void add(osoba** pocz){
    osoba* nowy = new osoba;
    cout << "Wprowdz imie: ";cin >> nowy->imie;
    if(nowy == NULL){
        cout << "Nie przydzielono pamięci";
    }else{
        if(*pocz == NULL){
            *pocz = nowy;
            nowy->next = NULL;
        }else{
            nowy->next  = *pocz;
            *pocz = nowy;
            
        }
    }
}

void display(osoba* pocz){
    osoba* temp = pocz;
    while(temp !=NULL){
        cout << " imie: " <<temp->imie<<endl;
        temp = temp->next;
    }
}

void del(osoba ** pocz){
    if(*pocz == NULL) cout << "There is no elements there"<<endl;
    else{
            osoba* temp = *pocz;
    *pocz = (*pocz)->next;
    delete temp;
    }
    
}
int main (){


int choice;
do{
menu();
cin >> choice;
switch(choice){
    case 1:
        add(&pocz);
        break;
    case 2:
        display(pocz);
        break;
    case 3:
        del(&pocz);
        break;
}
}while(choice!=0);
    return 0;
}