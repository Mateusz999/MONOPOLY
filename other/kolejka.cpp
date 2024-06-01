#include <iostream>
#include<fstream>
using namespace std;
struct osoba{
    string imie;
    osoba* next;
};
osoba* pocz = NULL;
osoba* kon = NULL;

void menu(){
    cout << "1. dodaj rekord"<<endl;
    cout << "2. wyswietl rekord"<<endl;
    cout << "0. wyjdz"<<endl;
    cout << "twoj wybor: ";
}
void add(osoba** pocz, osoba **kon){
    osoba* nowy = new osoba;
    cout << "Wprowdz imie: ";cin >> nowy->imie;
    nowy->next = NULL;
    if(nowy == NULL){
        cout << "Nie przydzielono pamięci";
    }else{
        if(*pocz == NULL){
            *pocz = nowy;
            nowy->next = NULL;
            *kon = nowy;
        }else{
            (*kon)->next  = nowy;
            *kon = nowy;
            
            
        }
    }
}

void display(osoba* pocz, osoba*kon){
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
        add(&pocz,&kon);
        break;
    case 2:
        display(pocz,kon);
        break;
    case 3:
        del(&pocz);
        break;
}
}while(choice!=0);
    return 0;
}