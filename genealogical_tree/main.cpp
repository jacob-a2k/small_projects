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
FamilyMember* find_leaf(FamilyMember* current,char* wanted);
FamilyMember* delete_person();
void change_name();
void display(FamilyMember* current);
FamilyMember* new_member(char* c_name);

int main()
{
    Tree tree_ptr;
    tree_ptr.me = nullptr;
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
        FamilyMember* current = nullptr;
        do{
            current = tree_ptr->me;
            char* full_name = new char[25];
            cout << "Podaj Imie i Nazwisko osoby do ktorej chcesz dodac rodzica!" << endl;
            cin.getline(full_name,25);
            current = find_leaf(current,full_name);
            if(current == 0){
                cout << "--------------------------------------------------------------" << endl;
                cout << "Podana osoba nie znajduje sie w spisie drzewa genealogicznego!" << endl;
                cout << "--------------------------------------------------------------" << endl;
            }
        }while(current == 0);
        cout << "===============" << current << endl;   // sprawdzam czy current zwrocil jakis adress

        cout << "Aby dodac mame wpisz 'm',aby dodac ojca wpisz 'f' " << endl;
        char sign;
        cin >> sign;
        if(sign == 'm'){
            current->mother = new_member(person->name);
        }
        else if(sign == 'f'){
            current->father = new_member(person->name);
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
FamilyMember* find_leaf(FamilyMember* current,char* wanted){
    if(current == nullptr){
		return 0;
	}
	cout << "//////////" << current->name << endl; // sprawdzam co aktualnie znajduje sie w current
	cout << "------------" << wanted <<  endl;     // sprawdzam co aktualnie znajduje sie w wanted

    if(strcmp(current->name, wanted) == 0){
		return current;
	}
	find_leaf(current->mother, wanted);
	find_leaf(current->father, wanted);
}
FamilyMember* new_member(char* c_name){
    FamilyMember* person = new FamilyMember;
    person->name = c_name;
    person->father = nullptr;
    person->mother = nullptr;
    return person;
}
