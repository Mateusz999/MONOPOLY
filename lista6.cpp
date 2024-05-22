#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stdexcept>
using namespace std;
class Statistic
{
    private:
    float min=0;
    float max=0;
    float avg=0;
    float med=0;
    float domi=0;
    public:
    Statistic() : min(0), max(0), avg(0.0), med(0.0), domi(0) {}

    int calcMin(vector<float>&liczby){
        if(!liczby.empty()){
            min = *min_element(liczby.begin(),liczby.end());
            return min;
        }
    };

    int calcMax(vector<float>&liczby){
        if(!liczby.empty()){
            max = *max_element(liczby.begin(),liczby.end());
            return max;
        }
    };
    int calcAvg(vector<float>&liczby){
        if(!liczby.empty()){
            avg = accumulate(liczby.begin(),liczby.end(),0);
            return avg;
        }
    };

    int calcMed(vector<float>&liczby){
          if(!liczby.empty()){
           int size = (liczby.size()+1)/2;
           sort(liczby.begin(),liczby.end());
           med = liczby[size];

            return med;
        }
    };
    int calcDomi(vector<float>&liczby){
       
          if(!liczby.empty()){
             domi=0;
            return domi;
        }
        
    };


    int getMin() const {
        return min;
    }

    int getMax() const {
        return max;
    }

    double getAvg() const {
        return avg;
    }

    double getMed() const {
        return med;
    }

    int getDom() const {
        return domi;
    }
};



class Pole
{
    public:
 
    string nazwaPola;
    int kosztZakupu;
    string gracz;
    int oplataPostoj;
    bool wykupione;
    string typPola;
    Pole(string N, int K, string G, int O, bool W,string T): nazwaPola(N), kosztZakupu(K), gracz(G),oplataPostoj(O),wykupione(W),  typPola(T){};

    
   


};
//KLASA NIERUCHOMOSC
class Nieruchomosc: public Pole
{
public:
    string kraj;
    int domki=0;
    bool hotel= false;

Nieruchomosc(string N, int K, string KR, int D, bool H, string G, int O, bool W,string T)
        : Pole(N, K, G, O, W,T), kraj(KR), domki(D), hotel(H) {}

 
};
// KLASA KOLEJ
class Kolej:public Pole
{
    public:
    Kolej(string N, int K, string G, int O, bool W,string T): Pole(N,K,G,O,W,T){};
};

class Szansa:public Pole
{
    public:
    Szansa(string N, int K, string G, int O, bool W, string T): Pole(N,K,G,O,W,T){};

    int chance(){
        kosztZakupu = rand()%200-100;
        return kosztZakupu;
    }

};

class DarmowyParking:public Pole
{

    public:
    DarmowyParking(string N, int K, string G, int O, bool W, string T): Pole(N,K,G,O,W,T){};

};
   // KLASA BANKIER
    class Bankier{
   

    public:
    string gracz;
    int CalcStandFee(auto& nieruchomosci){
        switch(nieruchomosci.domki){
            case 0:
                return 0+nieruchomosci.oplataPostoj;
                break;
            case 1:
                return 100+nieruchomosci.oplataPostoj;
                break;
            case 2:
                return 150+nieruchomosci.oplataPostoj;
                break;
            case 3:
                return 250+nieruchomosci.oplataPostoj;
                break;
            case 4:
                if(nieruchomosci.hotel) return 450+nieruchomosci.oplataPostoj;
                else return 350+nieruchomosci.oplataPostoj;
                break;
        }
    };
    void checkArea(auto& nieruchomosci, vector<Gracz>& listaGraczy, Gracz* osoba, Bankier* Bank ){
        
        if(nieruchomosci.wykupione == true){
            int oplata = CalcStandFee(nieruchomosci);
            osoba->setKapital(-oplata);
           for( auto& inwestor : listaGraczy){
                if(nieruchomosci.gracz == inwestor.imie) osoba = &inwestor;
    } 
        osoba->setKapital(oplata);
        }else{
            string decision;
            cout << "Czy chcesz kupić daną posiadłość? Jeśli tak wciśnij T";
            cin >> decision;
            if(decision == "T"){
                nieruchomosci.gracz = osoba->imie;
                nieruchomosci.wykupione = true;
            };
        }

    };
    
    void sellFinished(Gracz* sprzedajacy, Gracz*kupujacy,auto&nieruchumosci){
        int prize = sprzedajacy->sellPostion(auto&nieruchumosci,Gracz*kupujacy);
        sprzedajacy->getKapital(prize);
        kupujacy->getKapital(-prize);
    };

    void premiaZaStart(Gracz* osoba,Bankier Bank){
        
              int kapital =200;
                if(osoba->pozycja  >= 40){
           //s int pozycja = osoba->pozycja;
             osoba->afterStartPosition();
             osoba->setKapital(kapital);
            cout << " Kapitał : " << osoba->getKapital()<<endl;
        };
      
    };

};

// KLASA GRACZ
class Gracz{
    private:
        int stanKonta;   
    public:
        bool odsiadka;
        string imie;
        int pozycja = 0;

        Gracz(int S, string I, int P, bool OD): stanKonta(S), imie(I), pozycja(P), odsiadka(OD) {};

        int rzutKostka(){
            int kostka_1 = rand()%6+1;
            int kostka_2 = rand()%6+1;
        
            return kostka_1 + kostka_2;
        };
        void buildHouse(auto& nieruchomosci){
            if(imie == nieruchomosci->gracz ){
                if(nieruchomosci->domki < 4){
                    nieruchomosci->domki++;
                }else{
                    cout << "Posiadasz maksymalna ilosc domkow. Mozesz kupic hotem" << endl;
                    cout << "Nacisnij T jesli chcesz kupic hotel";
                    string hotelVerify;
                    cin >> hotelVerify;
                    if(hotelVerify == "T"){
                        buildHotel(nieruchomosci);
                    }else{
                        cout << "Nie wybudowano Hotelu" << endl;
                    }
                };
            }
        };

        void buildHotel(auto *nieruchomosci){
            nieruchomosci->wykupione = true;
            nieruchomosci->gracz = imie;
        }
        void setPosition(int kostka,Gracz * gracz){
           pozycja+=kostka;
        }

        void setKapital(int kapital){
            stanKonta += kapital;
        };

        int getKapital(){
            return stanKonta;
        };

        void afterStartPosition(){
            pozycja-=40;
        };
        int sellPosition(auto& nieruchomosci, auto& listaGraczy, auto& osoba){
            if(imie == Nieruchomosci->gracz){
                Nieruchomosci->gracz = kupujacy->imie;
                 int oplata = Bank.CalcStandFee(nieruchomosci);
                return oplata;
            }

            return 0;
        };

        void wyswietl() const{
       cout << "imie: " << imie << " kapital : " << stanKonta<<endl;
        };
        int checkArea(auto& nieruchomosci, vector<Gracz>&listaGraczy, Gracz* osoba, Bankier *Bank){
        
        if(nieruchomosci.wykupione == true){
            int oplata = Bank.CalcStandFee(nieruchomosci);
            osoba->setKapital(-oplata);
           for( auto& inwestor : listaGraczy){
                if(nieruchomosci.gracz == inwestor.imie) osoba = &inwestor;
    } 
        osoba->setKapital(oplata);
        }else{
            string decision;
            cout << "Czy chcesz kupić daną posiadłość? Jeśli tak wciśnij T";
            cin >> decision;
            if(decision == "T"){
                nieruchomosci.gracz = osoba->imie;
                nieruchomosci.wykupione = true;
            };
        }

    };
      
};


class Wiezienie:public Pole
{
public: 
bool odsiadka;

    void changeState(Gracz* gracz){
        gracz->odsiadka = true;

    };
   
    Wiezienie(string N, int K, string G, int O, bool W, string T,bool Odsiadka): Pole(N,K,G,O,W,T), odsiadka(Odsiadka){};
};
// KLASA OBIEKT INFRASTRUKTURY
class ObiektInfrastruktury:public Pole
{
 public:
    
    ObiektInfrastruktury(string N, int K, string G, int O, bool W, string T): Pole(N,K,G,O,W,T){};

};
void dodajGracza(vector<Gracz>&listaGraczy){
    string imie;
    int kapital = 200;
    int pozycja=0;
    bool odsiadka = false;
    cout << "Imie: ";cin >> imie;
    listaGraczy.push_back(Gracz(kapital,imie,pozycja, odsiadka));
};

void wyswietl(const vector<Gracz>&listaGraczy){
    for(const auto& osoba : listaGraczy){
        osoba.wyswietl();
    }
    };

 
 Bankier Bank;

// FUNKCJA GŁOWNA PROGRAMU
int main(){
    vector<float> liczby={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Statistic nowy;
  vector<Gracz> listaGraczy;
   // Bankier Bank;
    
    int choice;
    do{
           cout <<"Min: " <<nowy.getMin()<<endl;
    cout <<"Max: "<<nowy.getMax()<<endl;
    cout <<"Avg: " <<nowy.getAvg()<<endl;
    cout <<"Med: " <<nowy.getMed()<<endl;
    cout <<"Domi: " <<nowy.getDom()<<endl;
   
        cout << "1. Dodaj gracza"<<endl;
        cout << "2. Wyswietl graczy"<<endl;
        cout << "0. Zamknij"<<endl;
        cout << "Wybierz opcje ";
        cin >> choice;
        switch(choice){
            case 1:
                dodajGracza(listaGraczy);
                break;
            case 2:
                wyswietl(listaGraczy);
                break;
        }
    }while(choice !=0);



    
    do{
            for( auto& osoba : listaGraczy){
   

    int rzut = osoba.rzutKostka();
    cout << "Aktualna pozycja: " <<osoba.pozycja << " ---> ";
    cout << "Wyrzucono oczek:  "<< rzut<< endl;
        osoba.setPosition(rzut,&osoba);
        Bank.premiaZaStart(&osoba,Bank);
          
        };
    }while(true);

    return 0;
};
