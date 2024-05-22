#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stdexcept>
using namespace std;
class Statistic
{
    public:
    float min;
    float max;
    float avg;
    float med;
    float domi;


    float calcMin(vector<float>&liczby){
        if(!liczby.empty()){
            min = *min_element(liczby.begin(),liczby.end());
            return min;
        }
    };

    float calcMax(vector<float>&liczby){
        if(!liczby.empty()){
            max = *max_element(liczby.begin(),liczby.end());
            return max;
        }
    };
    float calcAvg(vector<float>&liczby){
        if(!liczby.empty()){
            avg = accumulate(liczby.begin(),liczby.end(),0);
            avg = avg/liczby.size();
            return avg;
        }
    };

    float calcMed(vector<float>&liczby){
          if(!liczby.empty()){
           int size = liczby.size();
           
           sort(liczby.begin(),liczby.end());
            if(size%2 ==1){
                 size = (size/2);
                med = liczby[size];

            return med;
            }else{
                float I = (liczby.size()/2);
                float J = (liczby.size()/2)+1;
                med = (I+J)/2.0;
                return med;

            }
          
        }
    };
    float calcDomi(vector<float>&liczby){
       
          if(!liczby.empty()){
             domi=0;
            return domi;
        }
        
    };


    float getMin() const {
        return min;
    }

    float getMax() const {
        return max;
    }

    float getAvg() const {
        return avg;
    }

    float getMed() const {
        return med;
    }

    float getDom() const {
        return domi;
    }
};


class Pole
{
    public:
    bool hotel;
    int domki;
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

class DarmowyParking:public Pole
{

    public:
    DarmowyParking(string N, int K, string G, int O, bool W, string T): Pole(N,K,G,O,W,T){};
};

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

class Wiezienie:public Pole
{
public: 
bool odsiadka;

    //void changeState(Gracz* gracz){
    //    gracz->odsiadka = true;

   // };
   
    Wiezienie(string N, int K, string G, int O, bool W, string T,bool Odsiadka): Pole(N,K,G,O,W,T), odsiadka(Odsiadka){};
};

class ObiektInfrastruktury:public Pole
{
 public:
    
    ObiektInfrastruktury(string N, int K, string G, int O, bool W, string T): Pole(N,K,G,O,W,T){};

};
class Bankier;
class Gracz{
    private:
        int stanKonta;   
    public:
        
        string imie;
        int pozycja;
        bool odsiadka;
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

        void buildHotel(auto *nieruchomosci){
            nieruchomosci->wykupione = true;
            nieruchomosci->gracz = imie;
        }
        void  setPosition(int kostka){
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
        int sellPosition(auto& nieruchomosci){
            if(imie == nieruchomosci.gracz){
                Gracz* kupujacy;
                nieruchomosci.gracz = kupujacy->imie;
                 int oplata = CalcStandFee(nieruchomosci);
                return oplata;
            }

            return 0;
        };
        
 class Bankier{
   

    public:
    string gracz;
 
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
    
    void sellFinished(Gracz sprzedajacy, Gracz kupujacy,Pole&nieruchumosci){
        int prize = sprzedajacy.sellPosition(nieruchumosci);
        sprzedajacy.setKapital(prize);
        kupujacy.setKapital(-prize);
    };

    void premiaZaStart(Gracz* osoba){
        
              int kapital =200;
                if(osoba->pozycja  >= 40){
           //s int pozycja = osoba->pozycja;
             osoba->afterStartPosition();
             osoba->setKapital(kapital);
            cout << " Kapitał : " << osoba->getKapital()<<endl;
        };
      
    };

};
        void wyswietl() const{
       cout << "imie: " << imie << " kapital : " << stanKonta<<endl;
        };
        void checkArea(Pole& nieruchomosci,Gracz& osoba, vector<Gracz>&listaGraczy){
            
        if(nieruchomosci.wykupione == true){
            int oplata = CalcStandFee(nieruchomosci);
            osoba.setKapital(-oplata);
           for( Gracz& inwestor : listaGraczy){
                if(nieruchomosci.gracz == inwestor.imie) osoba = inwestor;
    } 
        osoba.setKapital(oplata);
        }else{
            string decision;
            cout << "Czy chcesz kupić daną posiadłość? Jeśli tak wciśnij T";
            cin >> decision;
            if(decision == "T"){
                nieruchomosci.gracz = osoba.imie;
                nieruchomosci.wykupione = true;
            };
        }

    };
      
};

int main(){


   

    return 0;
}