#include <iostream>
#include <vector>
#include <cstdlib> // dla funkcji srand
#include <ctime>   // dla funkcji time
using namespace std;

class Gracz
{
    
    private:
        int stan;
        string imie;
        int pozycja;
    public:
    Gracz(string I):  stan(1000),imie(I),pozycja(0){};
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
        int domki = 3;
        bool hotel=false;
        string wlasciciel="dziala";
        int oplata=100;
        bool wykupione=false;
        int cena=100;
    public:

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
        void virtual obslugaGracza(Gracz& gracz) override {
            Gracz* posiadacz;
            if(getWykupione()){
                if(getWlasciciel() == gracz.getImie()){
                    menuNieruchomosc();
                    int choice;
                    cin >> choice;
                    switch(choice){
                        case 1:
                            budujDomek(&gracz);
                            break;
                        case 2:
                            budujHotel(&gracz);
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
    int getWartosc()  {
        int result = rand()%100-100;
        return result;
    }
        void virtual obslugaGracza(Gracz& gracz) override{
            cout <<  "Ryzyko"<<endl;
            gracz.getImie();

        };
};
int main(){
 srand(time(NULL));

Nieruchomosci pole1;
pole1.setNazwa("Nieruchomosc");
Szansa pole2;
pole2.setNazwa("szansa");
Ryzyko pole3;
pole3.setNazwa("Ryzyko");

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