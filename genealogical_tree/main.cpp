#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

struct FamilyMember{
    FamilyMember * mother;
    FamilyMember * father;
    char * name;
    FamilyMember* child;
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
FamilyMember* look_up_any_node(FamilyMember* current, char* wanted);
bool can_delete(FamilyMember* found);
FamilyMember* delete_node(FamilyMember* to_delete);
char put_character();
bool is_person_in_tree(FamilyMember* current, char* search_person);

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
            bool is_in_tree = is_person_in_tree(tree_ptr->me,full_name);
            if(is_in_tree){
                cout << "Podana osoba znajduje sie juz w spisie drzewa genealogicznego!" << endl;
                continue;
            }
			FamilyMember* person = new FamilyMember;
            FamilyMember* person = fillMember(person, full_name);
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
            deleted = nullptr;
            delete search_name;
            search_name = nullptr;
        }
            break;
        case 3:{
            char* name = new char[25];
            cout << "Podaj imie i nazwisko ktore chcesz zmienic!" << endl;
            cin.get();
            cin.getline(name,25);
            change_name(tree_ptr,name);
            delete name;
            name = nullptr;
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
            char* child_name = new char[25];
            cout << "Podaj Imie i Nazwisko dziecka, do ktorego chcesz dodac rodzica!" << endl;
            cin.getline(child_name,25);
            current = find_leaf(tree_ptr,child_name);
            if(current == 0){
                cout << "--------------------------------------------------------------" << endl;
                cout << "Podana osoba nie znajduje sie w spisie drzewa genealogicznego!" << endl;
                cout << "--------------------------------------------------------------" << endl;
            }
            delete child_name;
            child_name = nullptr;
        }while(current == 0);
        cout << "Aby dodac mame wpisz 'm',aby dodac ojca wpisz 'f' " << endl;
        char sign = put_character();
        if(sign == 'm'){
            current->mother = person;
        }
        else if(sign == 'f'){
            current->father = person;
        }
        person->child = current;
    }
}
FamilyMember* delete_person(Tree* tree_ptr, char* wanted){
    FamilyMember* current = tree_ptr->me;
    if(current == nullptr){
        cout << "Drzewo jest puste! Nie mozna usunac zadnego wezla!" << endl;
        return nullptr;
    }
    FamilyMember* found = look_up_any_node(current,wanted);
    if(found != nullptr){
        bool can_remove = can_delete(found);
        if(can_remove){
            if(current == found){
                tree_ptr->me = nullptr;
            }
            else{
                delete_node(found);
            }
            return found;
        }
        cout << "Nie mozna usunac obiektu, poniewaz posiada rodzicow! " << endl;
        cout << "Usun najpierw rodzicow! " << endl;
        return nullptr;
    }
    cout << "Nie znaleziono podanej osoby! " << endl;
    return nullptr;
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
	return look_up_any_node(tree_ptr->me, wanted);
}
FamilyMember* look_up_any_node(FamilyMember* current, char* wanted){
	if(current == nullptr){
		return nullptr;
	}

	if(strcmp(current->name, wanted) == 0){
		return current;
	}
	FamilyMember* found = look_up_any_node(current->mother, wanted);
	if(found != nullptr){
		return found;
	}
    return look_up_any_node(current->father, wanted);
}
FamilyMember* new_member(char* c_name){
    FamilyMember* person = new FamilyMember;
    person->name = c_name;
    person->father = nullptr;
    person->mother = nullptr;
    person->child = nullptr;
    return person;
}
bool can_delete(FamilyMember* found){
	if(found->mother != nullptr){
		return false;
	}
	else if(found->father != nullptr){
		return false;
	}
	return true;
}
void delete_node(FamilyMember* to_delete){
	if(to_delete->child->mother == to_delete){
		to_delete->child->mother = nullptr;
	}
	else{
		to_delete->child->father = nullptr;
	}
}
char put_character(){
	char mark;
	cin >> mark;
	while(mark != 'm' && mark != 'f'){
		cout << "Blad! Oczekuje literki m - mother lub f - father!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wprowadz ponownie!" << endl;
		cin >> mark;
	}
	return mark;
}
bool is_person_in_tree(FamilyMember* current, char* search_person){
	if(current == nullptr){
		return false;
	}
	if(strcmp(current->name,search_person) == 0){
		return true;
	}
	bool found = is_person_in_tree(current->mother,search_person);
	if(found != false){
		return true;
	}
	return is_person_in_tree(current->father,search_person);
}
