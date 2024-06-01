#include <iostream>
#include <vector>
#include <cstdlib> // dla funkcji srand
#include <ctime>   // dla funkcji time
using namespace std;
class Gracz;
class Pole;
class Nieruchomosc;
class Bankier;
class Gracz
{
    
    private:
        int stan;
        string imie;
        int pozycja;
    public:
    Gracz(string imie){
        this->imie = imie;
        this->pozycja =0;
        this->stan = 1000;
        };
        int rzutKostka(){
            int kostka_1 = rand()%6+1;
            int kostka_2 = rand()%6+1;
            int result =  kostka_1 + kostka_2;
            return result;
        };

    // gettery
        int getStan(){
            return stan;
        };
        string getImie(){
            return imie;
        };

        int getPozycja(){
            return pozycja;
        };


    // settery
        void setPozycja(int num){
            if(pozycja+num <=10){
                pozycja +=num;
            }else{
                pozycja +=num-10;
            }
            
        }
        void setImie(string im){
            imie = im;
        }
        void setStanUp(int up){
            stan +=up;
        };

        void setStanDown(int up){
            stan -=up;
        };

        void getPozycja(int wartosc){
            pozycja += wartosc;
        };
};

class Pole
{
    protected:
        string nazwaPola;
        
    public: 

        string getNazwaPola(){
            return nazwaPola;
        };
        void setNazwa(string nazwa){
            nazwaPola = nazwa;
        }
        void virtual obslugaGracza(Gracz& gracz){
            cout << gracz.getImie()<<endl;
        };
     
};

class Nieruchomosci:public Pole
{   
    private:
        int domki;
        bool hotel;
        string wlasciciel;
        int oplata;
        bool wykupione=false;
        int cena=100;
    public:
        Nieruchomosci(string nazwaPola, int oplata, int cena ){
            this->nazwaPola = nazwaPola;
            this->domki = 0;
            this->hotel = false;
            this->wlasciciel ="";
            this->oplata = oplata;
            this->wykupione = false;
            this->cena = cena;

        };
        bool getWykupione(){
            return wykupione;
        };
        string getWlasciciel(){
            return wlasciciel;
        };
        int getCena(){
            return cena;
        }
        void setWykupione(bool wartosc){
            wykupione =wartosc;
        }
        void setNazwaPola(string nazwa){
            nazwaPola = nazwa;
        };
        void setWlasciciel(string imie){
            wlasciciel = imie;
        };
        int getOplata(){
            return oplata;
        }

        void menuNieruchomosc(){    
            cout << "==================================================="<<endl;
            cout << "              Okno Wyboru "<<endl;
            cout << "==================================================="<<endl;
            cout << "Nr     Opis"<<endl;
            cout << "1.     Zakup Domek"<<endl;
            cout << "2.     Zakup Hotel"<<endl;
            cout << "0.     Wyjdz"<<endl;
            cout << "==================================================="<<endl;
        };
        int getDomki(){
            return domki;
        };
        bool getHotel(){
            return hotel;
        };
        
        void setHotel(bool wartosc){
            hotel = wartosc;
        }
        void setDomki(){
            domki+=1;
        }
        void budujDomek(Gracz* gracz){
            if(getDomki() <=3){
                setDomki();
                (*gracz).setStanDown(100);
            };
        };
        void budujHotel(Gracz* gracz){
            if(!getHotel()){
                if(getDomki() == 4){
                    setHotel("true");
                    (*gracz).setStanDown(300);
                }else{
                    cout << "Nie masz wystarczajaco duzo domkow by postawic hotel";
                } 
            };
        }
              void kupPole(Gracz *gracz)
    {
        setWlasciciel((*gracz).getImie());
        setWykupione(true);
        (*gracz).setStanDown(getCena());
    }
        vector<Gracz>listaGraczy;
        void virtual obslugaGracza(Gracz& gracz,Bankier Bank)  {
            Gracz* posiadacz;
            if(getWykupione()){
                if(getWlasciciel() == gracz.getImie()){
                    menuNieruchomosc();
                    int choice;
                    cin >> choice;
                    switch(choice){
                        case 1:
                            budujDomek(&gracz);
                            Bank.dajDomek(&gracz,this);
                            break;
                        case 2:
                            budujHotel(&gracz);
                            Bank.dajDomek(&gracz,this);
                            break;
                    };
                }else{
                    for( auto& el : listaGraczy){
                        if(el.getImie() == getWlasciciel() ) posiadacz = &el;
                    }
                    (*posiadacz).setStanUp(getOplata());
                    gracz.setStanDown(getOplata());
                }
            }else{
                cout << "Czy chcesz kupic dane pole? : 1-TAK 2-NIE ";
                int choice;
                cin >> choice;
                switch(choice){
                    case 1:
                        kupPole(&gracz);
                    break;
                    case 2:
                    cout << "Nie zakupiono pola";
                    break;
                }
            }
        };       
};

class Bankier
{
    public:
 
    void zabierzPieniadze(Gracz*gracz, int kwota){
        gracz->setStanDown(kwota);
    }; 

    void dajDomek(Gracz*gracz,Nieruchomosci*nieruchomosci){
            
            nieruchomosci->setDomki();
            (*gracz).setStanDown(nieruchomosci->getCena());     
    }
};


class Szansa:public Pole
{
    protected:
    int wartosc;
    public:
    Szansa(string x){
        this->nazwaPola = x;
    }
    int getWartosc(){
        int result = rand()%100+10;
        return result;
    };
      void virtual obslugaGracza(Gracz& gracz){
            cout <<  "szansa"<<endl;
            gracz.getImie();
        };
};

class Ryzyko:public Pole
{
    protected:
    int wartosc;
    public:
    Ryzyko(string NazwaPola){
        this->nazwaPola = nazwaPola;
    }
    int getWartosc()  {
        int result = rand()%100-100;
        return result;
    }
        void virtual obslugaGracza(Gracz& gracz) {
            cout <<  "Ryzyko"<<endl;
            gracz.getImie();

        };
};

class Kolej:public Pole{
    protected:
    int oplata;
    string wlasciciel;
    public:
    void obsluzGracz(Gracz&gracz){
        
    }
};
int main(){
 srand(time(NULL));
int choice;
do{
cout << "==================================================="<<endl;
cout << "       Menadzer Planszy "<<endl;
cout << "==================================================="<<endl;
cout << "Nr     Opis"<<endl;
cout << "1.     Dodaj Nieruchomosc"<<endl;
cout << "2.     Dodaj Pole Szansa"<<endl;
cout << "3.     Dodaj Pole Ryzyko"<<endl;
cout << "4.     Dodaj Pole Kolej"<<endl;
cout << "5.     Dodaj Pole Element infrastruktury"<<endl;
cout << "0.     Wyjdz"<<endl;
cout << "==================================================="<<endl;
cout << "Podemij decyzji: ";cin >> choice;
switch(choice){
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
}
}while(choice!=0);
Nieruchomosci pole1("Nieruchomosc",100,100);
pole1.setNazwa("Nieruchomosc");
Szansa pole2("Karta");
Ryzyko pole3("Ryzyko");


Gracz Roman("Rome123k");
vector<Pole> plansza;
plansza.push_back(pole1);
plansza.push_back(pole2);
plansza.push_back(pole3);

for(Pole& el:plansza){
    cout << el.getNazwaPola()<<endl;
}
 return 0;
};