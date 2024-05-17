#include <iostream>
#include <cstdlib>
using namespace std;

struct tree{
    int number;
    tree* left=NULL;
    tree* right=NULL;
};
void menu(){
//system("cls");
cout << "==================================================="<<endl;
cout << "              Tree Struct Management"<<endl;
cout << "==================================================="<<endl;
cout << "No.    Desctiption"<<endl;
cout << "1.     Add element to tree struct"<<endl;
cout << "2.     Delete element from tree struct"<<endl;
cout << "3.     Display elemens of tree struct"<<endl;
cout << "==================================================="<<endl;
};
void displayMenu(){
system("cls");
cout << "==================================================="<<endl;
cout << "             Display  Management"<<endl;
cout << "==================================================="<<endl;
cout << "No.    Desctiption"<<endl;
cout << "1.     Display inorder"<<endl;
cout << "2.     Display postorder"<<endl;
cout << "3.     Display preorder"<<endl;
cout << "==================================================="<<endl;
}
int input(int &choice){

    cout << "Enter you choice: ";
    cin >> choice;
};

int displayMenuInput(int &choiceDisplay){
    cout << "Enter you choice: ";
    cin >> choiceDisplay;
}
void searchToDel(tree** start, int value);
void preOrder( tree* start){

    if(start!=NULL){
        cout << " value :  " << start->number<<endl;
        preOrder(start->left);
        preOrder(start->right);
    } 
};

void inOrder( tree* start){

    if(start!=NULL){
        inOrder(start->left);
        cout << " value :  " << start->number<<endl;
        inOrder(start->right);
    } 
};

void postOrder( tree* start){

    if(start!=NULL){
        postOrder(start->left);
        postOrder(start->right);
        cout << " value :  " << start->number<<endl;
    } 
};


void displayCase(int &choiceDisplay, tree* start){
    switch(choiceDisplay){
        case 1:
            preOrder(start);
            break;
        case 2:
            inOrder(start);
            break;
        case 3:
            postOrder(start);
            break;
    }
};

tree* addToTree(tree*&start, int value){
            if(start == NULL){
                start = new tree;
                if(start==NULL) cout << "Error";
                start->number = value;
                return start;
            }else{
                if(value < start->number){  
                    addToTree(start->left,value);
               }
               else {
                if(value > (start)->number) {
                    addToTree(start->right,value);
                }
               }
            }
};
tree* findMin(tree* start) {
    if (start == nullptr) return nullptr;
    while (start->left != nullptr) {
        start = start->left;
    }
    return start;
}


void searchToDel(tree** start, int value) {
    if (*start == nullptr) return;

    if (value < (*start)->number) {
        searchToDel(&(*start)->left, value);
    } else if (value > (*start)->number) {
        searchToDel(&(*start)->right, value);
    } else {
           if (*start == nullptr) return;
    
    tree* nodeToDelete = *start;

    if ((*start)->left == nullptr && (*start)->right == nullptr) {
        // 
        delete nodeToDelete;
        *start = nullptr;
    } else if ((*start)->left == nullptr) {
        //
        *start = (*start)->right;
        delete nodeToDelete;
    } else if ((*start)->right == nullptr) {
        // 
        *start = (*start)->left;
        delete nodeToDelete;
    } else {
        // 
        tree* minNode = findMin((*start)->right);
        (*start)->number = minNode->number;
        searchToDel(&(*start)->right, minNode->number); 
    }
    }
}

  
tree* start = NULL;
int main(){
int choice;
int choiceDisplay;
int value;
int delNum;
tree Elements;
do{
menu();
input(choice);

cout << choice<<endl;
switch(choice){
    case 1:
        cout << "Enter number : ";
        cin >> value;
        addToTree(start,value);
        break;
    case 2:
        cout << "Enter number to delete: "; cin >> delNum;
        searchToDel(&start,delNum);
        break;
    case 3:
        displayMenu();
        displayMenuInput(choiceDisplay);
        displayCase(choiceDisplay, start);
        break;
    case 0:
        cout << "Application is stopped";
};
}while(choice !=0);


    return 0;
}