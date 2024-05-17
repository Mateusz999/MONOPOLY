#include<iostream>
#include<vector>
#include <chrono>
using namespace std;
void fillTab(int *tab,int num){

    for(int i=0;i<num;i++){
        tab[i] = rand()%10000;
    }

}

void display(int *tab,int num){

    for(int i=0;i<num;i++){
        cout <<tab[i] << endl;
    }

}
void bubbleSort(int *tab,int num){
    auto czasA = chrono::system_clock::now();
    for(int i =0;i<num-1;i++){
        for(int j =0;j<num-i-1;j++){
            if(tab[j] > tab[j+1]){
                int temp = tab[j+1];
                 tab[j+1] = tab[j];
                 tab[j] = temp;
            };
        }
    }
    auto czasB = chrono::system_clock::now();
    auto czasRezultat = czasA - czasB;
     czasRezultat;
};

void selectionSort(int *tab,int num){
        for(int i =0;i<num-1;i++){
            for(int j =i;j<num-1;j++){
                int min,index;
                int temp = tab[i];
                (tab[j] < tab[j+1])? index = j:index=j+1;
                tab[i]=min;
                tab[index] = temp;
        }
    }
};
void insertionSort(int *tab,int num){
   vector<int> tabelka;
   for(int i = 0; i<num;i++){
    tabelka.push_back(tab[i]);
   }

  
  for(int i = 1; i<num; i++){
    int currentValue = tabelka[i];
    int j = i-1;
       while(j>=0 && tabelka[j] > currentValue){
        
        tabelka[j+1] = tabelka[j];
        j--;
       }
       tabelka[j+1] = currentValue;
  }
   for(int i = 0; i<num;i++){
    tab[i] = tabelka[i]; 
      }

   

};

void mergeSort(int tab,int num){};
void countingSort(int tab,int num){};

void heapSort(int tab,int num){};

void bucketSort(int tab,int num){};

void quickSort(int tab,int num){};


int main(){
int choice;
int sort;
int num;
    do{
        cout << "Wybierz rozmiar tablicy"<<endl;
        cout << "1.     30.000"<<endl;
        cout << "2.     50.000"<<endl;
        cout << "3.     100.000"<<endl;
        cout << "4.     150.000"<<endl;
        cout << "5.     200.000"<<endl;
        cout << "6.     500.000"<<endl;
        cout << "7.     1.000.000"<<endl;
        cout << "8.     2.000.000"<<endl;
        cout << "9.     5.000.000"<<endl;
        cout << "10.    10.000.000 > ";  cin >> choice;
        switch(choice){
            case 1:
                num = 30000;
                break;
            case 2:
                num = 50000;
                break;
            case 3:
                num = 100000;
                break;
            case 4:
                num = 150000;
                break;
            case 5:
                num = 200000;
                break;
            case 6:
                num = 500000;
                break;
            case 7:
                num = 1000000;
                break;
            case 8:
                num = 2000000;
                break;
            case 9:
                num = 5000000;
                break;
            case 10:
                num = 10000000;
                break;
        }
    int tab[num];

            cout << "Wybierz rodzaj sortowania"<<endl;
        cout << "1.     Bubble"<<endl;
        cout << "2.     selection"<<endl;
        cout << "3.     insertion"<<endl;
        cout << "4.     merge"<<endl;
        cout << "5.     couting"<<endl;
        cout << "6.     heap"<<endl;
        cout << "7.     bucket"<<endl;
        cout << "8.     quick > "<<endl;
        cin >> sort;

             switch(sort){
            case 1:
                fillTab(tab,num);
                bubbleSort(tab, num);
                break;
            case 2:
                fillTab(tab,num);
                selectionSort(tab,num); 
                break;
            case 3:
                fillTab(tab,num);
                insertionSort(tab,num);
                display(tab,num);
                break;
            case 4:
                fillTab(tab,num);
                mergeSort(*tab,num);
                break;
            case 5:
                fillTab(tab,num);
                countingSort(*tab,num);
                break;
            case 6:
                fillTab(tab,num);
                heapSort(*tab,num);
                break;
            case 7:
                fillTab(tab,num);
                bucketSort(*tab,num);
                break;
            case 8:
                fillTab(tab,num);
                quickSort(*tab,num);
                break;
        }

    }while(choice !=0);

    return 0;
}