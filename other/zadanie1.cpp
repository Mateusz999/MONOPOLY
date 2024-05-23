#include <iostream>
#include <vector>
#include <cstdlib> // do funkcji rand() i srand()
#include <ctime>   // do funkcji time()
using namespace std;

class Pole
{
protected:
    
    int kosztZakupu;
    bool aktWlasnosci;

public:
string nazwaPola;
    string zwrocNazwe(){
        return nazwaPola;
    }

    int zwrocCene(){
        return kosztZakupu;
    }

};
class Infrastruktura
{
    string gracz=" ";
    int oplataPostoj;
    bool wykupione;
};
class Nieruchomosc : public Pole
{
public:
    string nazwaPola;
    int kosztZakupu;
    string kraj;
    int domki=0;
    bool hotel= false;
    string gracz=" ";
    int oplataPostoj;
    bool wykupione;
Nieruchomosc(string N, int K, string KR, int D, bool H, string G, int P,bool W): 
nazwaPola(N), kosztZakupu(K), kraj(KR), domki(D),hotel(H),gracz(G),oplataPostoj(P), wykupione(W){};

void wyswietl(){
    cout << "Cena wynosi: " << this->kosztZakupu<<endl;
    cout << "Nazwa: " << this->nazwaPola<<endl;
    cout << "kraj: " << this->kraj<<endl;
    cout << "Akt wlasnosci: " << this->hotel<<endl;
    cout << "domki: " << this->domki<<endl;
    cout << "gracz: " << this->gracz<<endl;
    cout << "Oplata: " << this->oplataPostoj<<endl;
}

void dodajDom(){
    int choice;
    cout << "jesli chcesz dodac dom wcisnij 2";
    cin >> choice;
    if(choice == 2){
        if(domki<4) domki++;
        else cout << "Masz juz maksymalna ilosc domkow";
    }
    
}
void usunDom(){
    if(domki>0) domki--;
}

void dodajHotel(){
    if(domki>1) hotel = true;
}


};

class kolej : public Pole
{
public:
    string kierunek;
    string gracz=" ";
    int oplata;

void wyswietl(){
    cout << "Kolej: " << this->kierunek<<endl;
    cout << "gracz: " << this->gracz<<endl;
    cout << "Oplata: " << this->oplata<<endl;
}
void nazwaPol(string nazwa){
    nazwaPola = nazwa;
};

void cenaKupna(int cena){
    kosztZakupu = cena;
};
void oplataPostoj(){

}

};
class szansa 
{
public:
    bool nagroda;
    int prize;
    string nazwa;
    szansa(bool n, int p, string na): nagroda(n), prize(p),nazwa(na){};
void wyswietl(){

    cout << "Nagroda: " << this->nagroda<<endl;
    cout << "Nazwa: " << this->nazwa<<endl;

}


void prizeOrLost(){
    int chance = rand()%2+1;
    if(chance%2) prize = rand()%100;
    else prize = rand()%100-100;
}


};
class gracz
{
    public:
        string imie;
        int kapital;
        int pozycjaPlansza=0;
        vector<Nieruchomosc> aktyWlasnosc;
   
   gracz(string i, int k, int p): imie(i), kapital(k), pozycjaPlansza(p) {};

        void kupnoNieruchomosci(vector<Nieruchomosc>& aktyWlasnosc,vector<Nieruchomosc>& nieruchomosci){
            
            Nieruchomosc pozycja = nieruchomosci[pozycjaPlansza];
            if(pozycja.wykupione == false){
                  pozycja.gracz = imie;
            aktyWlasnosc.push_back(pozycja);
            pozycja.wykupione=true;
            kapital -= pozycja.kosztZakupu;
            }else cout << "Nieruchomosc wykupiona";
          
        };
    int rzutKostka(){
        int kostka_1 = rand()%6+1;
        int kostka_2 = rand()%6+1;
        pozycjaPlansza += kostka_1 + kostka_2;
        
        return kostka_1 + kostka_2;
    }
    void wyswietl() const{
       cout << "imie: " << imie << " kapital : " << kapital<<endl;
       for (size_t i = 0; i < aktyWlasnosc.size(); ++i) {
        cout << "AKTY: " << aktyWlasnosc[i].gracz << ", Koszt: " << aktyWlasnosc[i].nazwaPola<< endl;
    }
    }
    int planszaPozycja(vector<Nieruchomosc>& nieruchomosci,vector<gracz>& listaGraczy){
        if(pozycjaPlansza >= 40){
            sprawdzOplate(nieruchomosci,listaGraczy);
            pozycjaPlansza = pozycjaPlansza-40;
            premiaStart();
            return pozycjaPlansza;
        } 
        else{
             
             sprawdzOplate(nieruchomosci,listaGraczy);
            return pozycjaPlansza;  
        } 

       
    }
        void premiaStart(){
         kapital += 200;
        
    }
    void checkKapital(){
        if(kapital <=0){
                cerr << "Gracz o imieniu " << imie<< " zbankrutowal "  <<endl;
                cerr << "GAME OVER!";
        exit(EXIT_FAILURE); // Zakończenie programu z kodem błędu

        }
    
    };

    int sprawdzOplate( vector<Nieruchomosc>& nieruchomosci,vector<gracz> listaGraczy){
        Nieruchomosc element = nieruchomosci[pozycjaPlansza];
        if(element.wykupione == true){
            kapital -=element.oplataPostoj+(element.domki*element.oplataPostoj);
            if(kapital <=0) return 0;
           for(const auto& osoba : listaGraczy){
            if(osoba.imie == element.gracz) kapital += element.oplataPostoj+(element.domki*element.oplataPostoj);

        }
        
      
    } 
        return element.oplataPostoj;
    }

    void aktualnePole(vector<Nieruchomosc>& nieruchomosci){
        Nieruchomosc aktualnieStoje = nieruchomosci[pozycjaPlansza];
        cout << "Pole: " << aktualnieStoje.nazwaPola<<endl;
    };
};
class Bankier
{
    public:
    
    void Sprzedaz(){};
    void Kupno(){};
    private:


};
void dodajGracza(vector<gracz>&listaGraczy){
    string imie;
    int kapital = 200;
    int pozycjaPlansza=0;
    cout << "Imie: ";cin >> imie;
    listaGraczy.push_back(gracz(imie,kapital,pozycjaPlansza));
}

void wyswietl(const vector<gracz>&listaGraczy){
    for(const auto& osoba : listaGraczy){
        osoba.wyswietl();
    }
};





vector<Nieruchomosc> stworzNieruchomosci(int liczbaNieruchomosci)
{
    vector<Nieruchomosc> nieruchomosci;
string stolice[6]  = {"Berlin","Warszawa","Madryt","Praga","Waszyngton","Rzym"};
string kraje[6]  = {"Niemcy","Polska","Hiszpania","Czechy","USA","Włochy"};
    for (int i = 1; i <= liczbaNieruchomosci; ++i)
    {
        int index = rand()%6;
        string nazwaPola = stolice[index];
        int kosztZakupu = rand() % 50+50;
        string kraj = kraje[index];
        int domki =0;
        bool hotel = false;
        string gracz = "";
        int oplataPostoj = 10;
        bool wykupione=false;

        nieruchomosci.push_back(Nieruchomosc(nazwaPola,kosztZakupu,kraj, domki,hotel,gracz,oplataPostoj,wykupione));
    }

    return nieruchomosci;
}
void test( vector<gracz>& listaGraczy,vector<Nieruchomosc>& nieruchomosci ){
    
    for( auto& osoba : listaGraczy){
    int choice;
    cout << "___________________________";
    cout << "Wyrzucono oczek: "<<osoba.rzutKostka();
    cout << "  Pozycja :"<< osoba.planszaPozycja(nieruchomosci,listaGraczy)<<endl;
    osoba.aktualnePole(nieruchomosci);
    cout << "Jesli chcesz kupic nieruchomosc naciśnij 1";
    cin >> choice;
    if(choice == 1) osoba.kupnoNieruchomosci( osoba.aktyWlasnosc, nieruchomosci);
    
        if(osoba.imie == nieruchomosci[osoba.pozycjaPlansza].gracz && nieruchomosci[osoba.pozycjaPlansza].wykupione == true){

            nieruchomosci[osoba.pozycjaPlansza].dodajDom();
        };
    
 
    osoba.wyswietl();


    osoba.checkKapital();

  }

}
int main(){
     srand(time(NULL));
     
    vector<Nieruchomosc> nieruchomosci = stworzNieruchomosci(40);

    // Wyświetlenie nieruchomości
    for ( auto& element : nieruchomosci)
    {
        element.wyswietl();
        cout << endl;
    }
    vector<gracz> listaGraczy;
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
        test(listaGraczy,nieruchomosci);
    }while(true);

    return 0;
}