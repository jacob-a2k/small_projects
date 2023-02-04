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
FamilyMember* delete_person(Tree* tree_ptr, char* wanted);
void change_name(Tree* tree_ptr, char* name);
void display(FamilyMember* current);
FamilyMember* new_member(char* c_name);
FamilyMember* check_parents(FamilyMember* current, char* wanted);
FamilyMember* find_parent(FamilyMember* current, char* wanted);

int main()
{
/*
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
*/

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
        case 2:{
            char* search_name = new char[25];
            cout << "Podaj imie, ktore chcesz usunac: ";
            cin.get();
            cin.getline(search_name,25);
            FamilyMember* deleted = delete_person(tree_ptr,search_name);
                delete deleted;
        }
            break;
        case 3:{
            char* name = new char[25];
            cout << "Podaj imie i nazwisko ktore chcesz zmienic!" << endl;
            cin.get();
            cin.getline(name,25);
            change_name(tree_ptr,name);
            delete name;
        }
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
    }
}
FamilyMember* delete_person(Tree* tree_ptr, char* wanted){
    if(tree_ptr->me == nullptr){
        cout << "Drzewo jest puste! Nie mozna usunac zadnego wezla!" << endl;
        return nullptr;
    }
    else{
        FamilyMember* current = tree_ptr->me;
        if(current->father == nullptr && current->mother == nullptr){
            if(strcmp(current->name,wanted) == 0){
            tree_ptr->me = nullptr;
            return current;
            }
        }
        else if(strcmp(current->name,wanted) == 0){
            cout << "Nie mozna usunac osoby, poniewaz sa juz do niej przypisani rodzice!" << endl;
            cout << "Usun najpierw rodzica!" << endl;
            return nullptr;
        }

        FamilyMember* penultimate = nullptr;
        penultimate = find_parent(current,wanted);
        if(penultimate != nullptr){
            if(strcmp(penultimate->father->name,wanted) == 0){
                if(penultimate->father->father == nullptr && penultimate->father->mother == nullptr){
                    penultimate->father = nullptr;
                    return penultimate->father;
                }
                else{
                    cout << "Nie mozna usunac osoby, poniewaz sa juz do niej przypisani rodzice!" << endl;
                    cout << "Usun najpierw rodzica!" << endl;
                    return nullptr;
                }
            }
            else if(strcmp(penultimate->mother->name,wanted) == 0){
                if(penultimate->mother->father == nullptr && penultimate->mother->mother == nullptr){
                    penultimate->mother = nullptr;
                    return penultimate->mother;
                }
                else{
                    cout << "Nie mozna usunac osoby, poniewaz sa juz do niej przypisani rodzice!" << endl;
                    cout << "Usun najpierw rodzica!" << endl;
                    return nullptr;
                }
            }
        }
        else{
            cout << "Nie znaleziono podanej osoby!" << endl;
            return nullptr;
        }
    }
}
FamilyMember* find_parent(FamilyMember* current, char* wanted){
    if(current->mother == nullptr){
        if(current->father == nullptr){
            return nullptr;
        }
        if(strcmp(current->father->name,wanted) == 0){
            return current;
        }
        return find_parent(current->father,wanted);
    }
    if(strcmp(current->mother->name,wanted) == 0){
        return current;
    }
    FamilyMember* found = find_parent(current->mother,wanted);
    if(found != nullptr){
        return found;
    }
    if(current->father == nullptr){
        return nullptr;
    }
    if(strcmp(current->father->name,wanted) == 0){
        return current;
    }
    return find_parent(current->father,wanted);
}
void change_name(Tree* tree_ptr, char* name){
    if(tree_ptr->me == nullptr){
        cout << "Drzewo jest puste! Uzyj funkcji - Add person! " << endl;
        return;
    }
    else{
        FamilyMember* current = nullptr;
        current = find_leaf(tree_ptr,name);
        if(current != nullptr){
            char* new_name = new char[25];
            cout << "Podaj nowe dane!" << endl;
            cin.getline(new_name,25);
            current->name = new_name;
        }
        else{
            cout << "Nie znaleziono w drzewie genealogicznym!" << endl;
        }
    }
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
