#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

struct FamilyMember{
    FamilyMember * mother;
    FamilyMember * father;
    char * name;
};
struct Tree {
    FamilyMember * me;
};
void tree_options(Tree* tree_ptr);
void menu();
int put_number();
void add_person(Tree* tree_ptr, FamilyMember* person);
FamilyMember* find_leaf(Tree* tree_ptr,char* wanted);
FamilyMember* delete_person();
void change_name();
void display(FamilyMember* current);
FamilyMember* new_member(char* c_name);
FamilyMember* check_parents(FamilyMember* current, char* wanted);

int main()
{

    FamilyMember* kuba = new_member("kuba");
    FamilyMember* mama = new_member("mama");
    FamilyMember* tata = new_member("tata");
    FamilyMember* babciaM = new_member("babciaM");
    FamilyMember* dziadekM = new_member("dziadekM");
    FamilyMember* babciaT = new_member("babciaT");
    FamilyMember* dziadekT = new_member("dziadekT");
    kuba->mother = mama;
    kuba->father = tata;
    mama->mother = babciaM;
    mama->father = dziadekM;
    tata->mother = babciaT;
    tata->father = dziadekT;

    Tree tree_ptr;
    tree_ptr.me = kuba;
    tree_options(&tree_ptr);

    return 0;
}
void tree_options(Tree* tree_ptr){
    for(;;){
        menu();
        int number = put_number();
        switch(number){
        case 1:{
            char* full_name = new char[25];
            cout << "Podaj imie i nazwisko dodawanej osoby!" << endl;
            cin.get();
            cin.getline(full_name,25);
            FamilyMember* person = new_member(full_name);
            add_person(tree_ptr,person);
        }
            break;
        case 2:
            delete_person();
            break;
        case 3:
            change_name();
            break;
        case 4:{
            FamilyMember* current =  tree_ptr->me;
            display(current);
        }
            break;
        case 5:
            exit(0);
        default:
            cout << "Nie badz oslem! Wprowadz poprawny numer!" << endl;
        }
    }
}
void add_person(Tree* tree_ptr, FamilyMember* person){
    if(tree_ptr->me == nullptr){
        tree_ptr->me = person;
    }
    else{
        FamilyMember* current = tree_ptr->me;;
        do{
            //current = tree_ptr->me;
            char* full_name = new char[25];
            cout << "Podaj Imie i Nazwisko osoby do ktorej chcesz dodac rodzica!" << endl;
            cin.getline(full_name,25);
            current = find_leaf(tree_ptr,full_name);
            if(current == 0){
                cout << "--------------------------------------------------------------" << endl;
                cout << "Podana osoba nie znajduje sie w spisie drzewa genealogicznego!" << endl;
                cout << "--------------------------------------------------------------" << endl;
            }
        }while(current == 0);
        cout << "Aby dodac mame wpisz 'm',aby dodac ojca wpisz 'f' " << endl;
        char sign;
        cin >> sign;
        if(sign == 'm'){
            current->mother = person;
        }
        else if(sign == 'f'){
            current->father = person;
        }
        else{

        }
    }
}
FamilyMember* delete_person(){

}
void change_name(){

}
void display(FamilyMember* current){
    if(current == nullptr){
        return;
    }
    else{
        cout << current->name << endl;
        display(current->mother);
        display(current->father);
    }
}
void menu(){
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "Choose available options!" << endl;
    cout << "-------------------------" << endl;
    cout << "1.Add person" << endl;
    cout << "2.Delete person" << endl;
    cout << "3.Change name" << endl;
    cout << "4.Display" << endl;
    cout << "5.Exit" << endl;
    cout << endl;
}
int put_number(){
    int value;
    cin >> value;
    while(!cin.good()){
        cout << "Blad!Sprobuj ponownie! "<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wprowadz ponownie!" << endl;
        cin >> value;
    }
    return value;
}
FamilyMember* find_leaf(Tree* tree_ptr,char* wanted){
     if(tree_ptr->me == nullptr){
        return nullptr;
     }
     FamilyMember* current = tree_ptr->me;
     if(strcmp(current->name,wanted) == 0 ){
        return current;
     }
     FamilyMember* found = check_parents(current,wanted);
     if(found != nullptr){
        return found;
     }//TODO

}
FamilyMember* new_member(char* c_name){
    FamilyMember* person = new FamilyMember;
    person->name = c_name;
    person->father = nullptr;
    person->mother = nullptr;
    return person;
}
FamilyMember* check_parents(FamilyMember* current, char* wanted){
    if(current->mother == nullptr){
        if(current->father == nullptr){
            return nullptr;
        }
        if(strcmp(current->father->name,wanted) == 0 ){
            return current->father;
        }
        return check_parents(current->father,wanted);
     }
     if(strcmp(current->mother->name,wanted) == 0 ){
         return current->mother;
     }
     FamilyMember* found = check_parents(current->mother,wanted);
     if(found != nullptr){
         return found;
     }
     if(current->father == nullptr){
         return nullptr;
     }
     if(strcmp(current->father->name,wanted) == 0){
         return current->father;

     }
     return check_parents(current->father,wanted);
}
