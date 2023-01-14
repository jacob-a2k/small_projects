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
void tree_options(Tree* const tree_ptr);
void menu();
int put_number();
void add_person(Tree* tree_ptr, FamilyMember* person);
FamilyMember* delete_person();
void change_name();
void display();

int main()
{
    Tree tree_ptr;
    tree_ptr.me = nullptr;
    tree_options(&tree_ptr);

    return 0;
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
void tree_options(Tree* const tree_ptr){
    for(;;){
        menu();
        int number = put_number();
        switch(number){
        case 1:{
            FamilyMember* person = new FamilyMember;
            person->name = new char[25];
            cout << "Podaj imie i nazwisko" << endl;
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
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Don't be dunky! Choose correct number!" << endl;
        }
    }
}
void add_person(Tree* tree_ptr, FamilyMember* person){
    if(tree_ptr->me == nullptr){
        tree_ptr->me = person;
    }
    else{
        FamilyMember* current = tree_ptr->me;
        while(current != nullptr){

        }
    }


    person->father = nullptr;
    person->mother = nullptr;
}
FamilyMember* delete_person(){

}
void change_name(){

}
void display(){

}


