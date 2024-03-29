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
void menu();
int put_number();
FamilyMember** find(Tree* tree_ptr,char* wanted);
void display(FamilyMember* current);
void fill_member(FamilyMember* person, char* c_name);
FamilyMember** look_up_any_node(FamilyMember** current, char* wanted);
bool can_delete(FamilyMember* found);
char put_character();
bool is_person_in_tree(FamilyMember* current, char* search_person);
void clear_member(FamilyMember* member);
void fill_sample_data(Tree* tree_ptr);

void add_person(Tree* tree_ptr);
void remove_person(Tree* tree_ptr);
void change_name(Tree* tree_ptr);
void display(Tree* tree_ptr);
void tree_options(Tree* tree_ptr);

int main()
{
    Tree tree_ptr;
    tree_ptr.me = nullptr;
    fill_sample_data(&tree_ptr);
    tree_options(&tree_ptr);

    return 0;
}
void tree_options(Tree* tree_ptr){
    for(;;){
        menu();
        int number = put_number();
        switch(number){
        case 1:
            add_person(tree_ptr);
            break;
        case 2:
            remove_person(tree_ptr);
            break;
        case 3:
            change_name(tree_ptr);
            break;
        case 4:
            display(tree_ptr);
            break;
        case 5:
            exit(0);
        default:
            cout << "Nie badz oslem! Wprowadz poprawny numer!" << endl;
        }
    }
}
void display(FamilyMember* current){
    if(current == nullptr){
        return;
    }
    cout << current->name << endl;
    display(current->mother);
    display(current->father);
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
FamilyMember** find(Tree* tree_ptr,char* wanted){
	return look_up_any_node(&(tree_ptr->me), wanted);
}
FamilyMember** look_up_any_node(FamilyMember** current_adr, char* wanted){
	if(current_adr == nullptr){
		return nullptr;
	}
    FamilyMember* current = *current_adr;
    if(current == nullptr){
        return nullptr;
    }
	if(strcmp(current->name, wanted) == 0){
		return current_adr;
	}
	FamilyMember** found = look_up_any_node(&(current->mother), wanted);
	if(found != nullptr){
		return found;
	}
    return look_up_any_node(&(current->father), wanted);
}
void fill_member(FamilyMember* person,char* c_name){
    person->name = new char[strlen(c_name)+1];
    strcpy(person->name,c_name);
    person->father = nullptr;
    person->mother = nullptr;
    //person->child = nullptr;
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
void clear_member(FamilyMember* member){
    if(member != nullptr){
        delete member->name;
        member->name = nullptr;
    }
}
void add_person(Tree* tree_ptr){
    char full_name[25];
    cout << "Podaj imie i nazwisko dodawanej osoby!" << endl;
    cin.get();
    cin.getline(full_name,25);
    if(tree_ptr->me == nullptr){
        FamilyMember* person = new FamilyMember;
        fill_member(person,full_name);
        tree_ptr->me = person;
        return;
    }
    bool is_in_tree = is_person_in_tree(tree_ptr->me,full_name);
    if(is_in_tree){
        cout << "Podana osoba znajduje sie juz w spisie drzewa genealogicznego!" << endl;
        return;
    }
    char child_name[25];
    cout << "Podaj Imie i Nazwisko dziecka, do ktorego chcesz dodac rodzica!" << endl;
    cin.getline(child_name,25);

    FamilyMember** child_adr = find(tree_ptr,child_name);
    if(child_adr == nullptr){
        cout << "--------------------------------------------------------------" << endl;
        cout << "Podana osoba nie znajduje sie w spisie drzewa genealogicznego!" << endl;
        cout << "--------------------------------------------------------------" << endl;
        return;
    }
    FamilyMember* child = *child_adr;
    FamilyMember* person = new FamilyMember;
    fill_member(person,full_name);

    cout << "Aby dodac mame wpisz 'm',aby dodac ojca wpisz 'f' " << endl;
    char sign = put_character();
    if(sign == 'm'){
        child->mother = person;
    }
    else if(sign == 'f'){
        child->father = person;
    }
    //person->child = child;
}
void remove_person(Tree* tree_ptr){
    if(tree_ptr->me == nullptr){
        cout << "Drzewo jest puste! Nie mozna usunac zadnego wezla!" << endl;
        return;
    }
    char search_name[25];
    cout << "Podaj imie, ktore chcesz usunac: ";
    cin.get();
    cin.getline(search_name,25);

    FamilyMember** found = find(tree_ptr,search_name);
    if(found == nullptr){
        cout << "Nie znaleziono podanej osoby! " << endl;
        return;
    }
    bool can_remove = can_delete(*found);
    if(!can_remove){
        cout << "Nie mozna usunac obiektu, poniewaz posiada rodzicow! " << endl;
        cout << "Usun najpierw rodzicow! " << endl;
        return;
    }
    clear_member(*found);
    delete *found;
    *found = nullptr;
}
void change_name(Tree* tree_ptr){
    if(tree_ptr->me == nullptr){
        cout << "Drzewo jest puste!" << endl;
        return;
    }
    char name[25];
    cout << "Podaj imie i nazwisko ktore chcesz zmienic!" << endl;
    cin.get();
    cin.getline(name,25);
    FamilyMember** current_adr = find(tree_ptr,name);
    if(current_adr == nullptr){
        cout << "Czlonek rodziny o godnosci " << name << " nie zostal znaleziony!" << endl;
        return;
    }
    FamilyMember* current = *current_adr;
    char new_name[25];
    cout << "Podaj nowe dane!" << endl;
    cin.getline(new_name,25);
    strcpy(current->name,new_name);
}
void display(Tree* tree_ptr){
    display(tree_ptr->me);
}

void fill_sample_data(Tree* tree_ptr){
    FamilyMember* kuba = new FamilyMember;
    fill_member(kuba,"kuba");
    tree_ptr->me = kuba;
    FamilyMember* mama = new FamilyMember;
    fill_member(mama,"mama");
    kuba->mother = mama;
    FamilyMember* tata = new FamilyMember;
    fill_member(tata,"tata");
    kuba->father = tata;
    FamilyMember* dziadek = new FamilyMember;
    fill_member(dziadek,"franek");
    mama->father = dziadek;

}
