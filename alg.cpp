#include <iostream>
#include<fstream>
using namespace std;

struct osoba{
    string imie;
    osoba* next;
    osoba *prev;
};

/*osoba *pocz = NULL;
STOS
void menu(){
cout << "1. dodaj"<<endl;
cout << "2. usun"<<endl;
cout << "3. wyswietl"<<endl;
}
void addNew(osoba **pocz){
    osoba* nowy = new osoba;
    if(nowy == NULL) cout << "Nie przydzielono pamieci";
    else{
        cout <<"Wprowadz imie: ";cin >> nowy->imie;
        if(*pocz == NULL){
            *pocz = nowy;
            (*pocz)->next = NULL;
        } else{
            nowy->next = *pocz;
            *pocz = nowy;

          
        }


    }
};
void deleteNew(osoba **pocz){
    if(*pocz == NULL) cout<<"brak elementow do usuniecia";
    else{
       osoba*temp = *pocz;
    *pocz = (*pocz)->next;
    delete temp; 
    }
    
};

void displayNew(osoba *pocz){

        if(pocz == NULL) cout<<"brak elementow do wyswietlenia";
    else{
      while(pocz !=NULL){
        cout << pocz->imie<<endl;
        pocz = pocz->next;
    };
    }
   
}*/
/* KOLEJKA
osoba *pocz = NULL;
osoba *kon = NULL;
void menu(){
cout << "1. dodaj"<<endl;
cout << "2. usun"<<endl;
cout << "3. wyswietl"<<endl;
}
void addNew(osoba **pocz, osoba**kon){
    osoba* nowy = new osoba;
    if(nowy == NULL) cout << "Nie przydzielono pamieci";
    else{
        cout <<"Wprowadz imie: ";cin >> nowy->imie;
        if(*pocz == NULL){
            *pocz = nowy;
            (*pocz)->next = NULL;
            *kon = nowy;
        } else{
            (*kon)->next = nowy;
            *kon = nowy;
            (*kon)->next = NULL;

          
        }


    }
};
void deleteNew(osoba **pocz,osoba **kon){
    if(*pocz == NULL) cout<<"brak elementow do usuniecia";
    else{
       osoba*temp = *kon;
    *pocz = (*pocz)->next;
    delete temp; 
    }
    
};

void displayNew(osoba *pocz){

        if(pocz->next == NULL) cout<<"brak elementow do wyswietlenia";
    else{
      while(pocz !=NULL){
        cout << pocz->imie<<endl;
        pocz = pocz->next;
    };
    }}
   */

  osoba *pocz = NULL;
osoba *kon = NULL;
void menu(){
cout << "1. dodaj"<<endl;
cout << "2. usun"<<endl;
cout << "3. wyswietl"<<endl;
cout << "4. usun wybrane"<<endl;
cout << "5. usun calosc"<<endl;
}
void deleteOne(osoba **pocz, osoba**kon){
    string name;
    cout << "Wprowadz imie : ";cin >>name;
    osoba*temp = *pocz;
    while(temp != NULL){
        if(name ==temp->imie ){
           
        if(*pocz == temp){
            osoba*temp = *pocz;
            *pocz = (*pocz)->next;
            delete temp;
        }
        else if(*kon == temp){
            osoba*temp = *kon;
            *kon = (*kon)->prev;
            (*kon)->next = NULL;
            delete temp;
        }else{
            osoba* tem = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete tem;
        }
        
        }
        temp = temp->next;
    };
};
l
void deleteAll(osoba**pocz, osoba**kon){
        osoba*temp = *pocz;
    while((temp)!=NULL){

        *pocz = (*pocz)->next;
        
        
        delete temp;
        temp = (*pocz);
    }
};

void addNew(osoba **pocz, osoba**kon){
    osoba* nowy = new osoba;
    if(nowy == NULL) cout << "Nie przydzielono pamieci";
    else{
        cout <<"Wprowadz imie: ";cin >> nowy->imie;
        if(*pocz == NULL){
            *pocz = nowy;
            (*pocz)->next = NULL;
            (*pocz)->prev = *pocz;
            *kon = nowy;
        } else{
            (*kon)->next = nowy;
            nowy->prev = *kon;
            *kon = nowy;
            (*kon)->next = NULL;

          
        }


    }
};
void deleteNew(osoba **pocz,osoba **kon){
    if(*pocz == NULL) cout<<"brak elementow do usuniecia"<<endl;
    else{
        if(*pocz == *kon) {
           osoba*temp = *pocz;
           osoba*temp2 = *kon;
           *pocz =NULL;
           *kon = NULL;
           delete temp;
           delete temp2;
        }
        else {
        osoba*temp = *kon;
        *kon = temp->prev;
        (*kon)->next = NULL;
        

        delete temp;  
        }
    
    }
    
};

void displayNew(osoba *pocz){

        if(pocz == NULL) cout<<"brak elementow do wyswietlenia"<<endl;
    else{
      while(pocz !=NULL){
        cout << pocz->imie<<endl;
        pocz = pocz->next;
    };
    }}

void saveFile(osoba* pocz){
    ofstream plik;
    plik.open("DANE.txt");
    if(pocz == NULL) cout<<"brak listy";
    else{
        if(plik.is_open()){
            while(pocz!=NULL){
                plik << "IMiE" << pocz->imie<<endl;
                pocz = pocz->next;
            }
            plik.close();
        }else cout << "nie udalo sie otworzyc pliku";
    }
};
void wyswietl(){
    ifstream plik("DANE.txt");
    string line;
    while(getline(plik,line)){
        cout << line << endl;
    }
}
int main(){
int choice;
do{
menu();
cout << "wprowadz wartosc: ";cin >> choice;

switch(choice){
    case  1:
    addNew(&pocz,&kon);
    break;
    case 2:
    deleteNew(&pocz, &kon);
    break;
    case 3:
    displayNew(pocz);
    break;
    case 4:
    deleteOne(&pocz,&kon);
    break;
    case 5:
    deleteAll(&pocz,&kon);
    break;
    case 6:
    saveFile(pocz);
    break;
    case 7:
    wyswietl();
    break;
}
}while(choice!=0);

return 0;
};