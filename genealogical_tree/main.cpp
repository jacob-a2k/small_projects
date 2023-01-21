#include <iostream>
#include <limits>

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
FamilyMember* find_leaf(FamilyMember* current,FamilyMember* wanted);
FamilyMember* delete_person();
void change_name();
void display(FamilyMember* current);

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
            FamilyMember* person = new FamilyMember;
            person->name = new char[25];
            person->father = nullptr;
            person->mother = nullptr;
            cout << "Podaj imie i nazwisko dodawanej osoby" << endl;
            cin.get();
            cin.getline(person->name,25);
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
        FamilyMember* tmp = new FamilyMember;
        tmp->name = new char[25];
        tmp->father = nullptr;
        tmp->mother = nullptr;
        cout << "Podaj Imie i Nazwisko osoby do ktorej chcesz dodac rodzica!" << endl;
        cin.getline(tmp->name,25);
        FamilyMember* current = tree_ptr->me;
        tmp = find_leaf(current,tmp);

        cout << "Aby dodac mame wpisz 'm',aby dodac ojca wpisz 'f' " << endl;
        char sign;
        cin >> sign;
        if(sign == 'm'){
            tmp->mother = person;
        }
        else if(sign == 'f'){
            tmp->father = person;
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
FamilyMember* find_leaf(FamilyMember* current,FamilyMember* wanted){
    if(*current->name == *wanted->name){
		return current;
	}
	if(current == nullptr){
		return 0;
	}
	find_leaf(current->mother, wanted);
	find_leaf(current->father, wanted);
}
