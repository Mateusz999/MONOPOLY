#include <iostream>
#include <vector>
using namespace std;

//KLASA NIERUCHOMOSC
class Nieruchomosc
{
public:
    string nazwaPola;
    int kosztZakupu;
    string kraj;
    int domki=0;
    bool hotel= false;
    string gracz;
    int oplataPostoj;
    bool wykupione;
Nieruchomosc(string N, int K, string KR, int D, bool H, string G, int P,bool W): 
nazwaPola(N), kosztZakupu(K), kraj(KR), domki(D),hotel(H),gracz(G),oplataPostoj(P), wykupione(W){};
};

// KLASA KOLEJ
class Kolej
{
    public:
    string nazwa;
    int kosztZakupy;
    bool wykupione;
    string gracz;
    int oplataPostoj;
    Kolej(string N, int K, bool W, string G): nazwa(N),kosztZakupy(K),wykupione(W),gracz(G){};
};

class Szansa
{
    public:
    string nazwa;
    int prize;

    int chance(){
        prize = rand()%200-100;
        return prize;
    }

    Szansa(int P,string N): prize(P), nazwa(N){};
};

class DarmowyParking
{
    public:
    string nazwa;
};

class Wiezienie
{
    public:
    string nazwa;

    string osadzony;

    void changeState(Gracz*gracz){
        gracz->odsiadka = true;

    };
    Wiezienie(string N, string osadzony): nazwa(N),osadzony(osadzony){};
};
// KLASA OBIEKT INFRASTRUKTURY
class ObiektInfrastruktury
{
 public:
    string nazwa;
    int kosztZakupy;
    bool wykupione;
    string gracz;
    int oplataPostoj;
    
    ObiektInfrastruktury(string N, int K, bool W, string G): nazwa(N),kosztZakupy(K),wykupione(W),gracz(G){};
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
        void buildHouse(auto *nieruchomosci){
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
        void setPosition(int kostka){
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
        int sellPosition(auto*Nieruchomosci, Gracz*kupujacy){
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
        void checkArea(auto& nieruchomosci, vector<Gracz>&listaGraczy ){
        
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
    void checkArea(auto& nieruchomosci, Gracz* osoba, vector<Gracz>&listaGraczy ){
        
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
    
    void sellFinished(Gracz*sprzedajacy, Gracz*kupujący,auto&nieruchumosci){
        int prize = sprzedajacy.sellPostion(auto&nieruchumosci,Gracz*kupujący);
        sprzedajacy->getKapital(prize);
        kupujący->getKapital(-prize);
    };

    void premiaZaStart(Gracz* osoba){
        
              int kapital =200;
                if(osoba->pozycja  >= 40){
            
             osoba->afterStartPosition();
             osoba->setKapital(kapital);
            cout << " Kapitał : " << osoba->getKapital()<<endl;
        };
      
    };

};


// FUNKCJA GŁOWNA PROGRAMU
int main(){
    vector<Gracz> listaGraczy;
    Bankier Bank;
    int choice;
    do{
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
   cout << "Liczy graczy wynosi: " << listaGraczy.size() << " zatem mozna przejsc do rozgrywki"<<endl;


    
    do{
            for( auto& osoba : listaGraczy){
    

    int rzut = osoba.rzutKostka();
    cout << "Aktualna pozycja: " <<osoba.pozycja << " ---> ";
    cout << "Wyrzucono oczek:  "<< rzut<< endl;
        osoba.setPosition(rzut);
        Bank.premiaZaStart(&osoba);
          
        };
    }while(true);

    return 0;
};
