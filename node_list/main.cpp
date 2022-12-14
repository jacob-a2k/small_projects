#include <iostream>
#include <limits>

using namespace std;

struct Node{
    int value;
    Node* next;
};
struct List{
    Node* first;
};
void display(const List* const list_ptr);
void add_front(List* list, Node *new_node);
void list_methods(List* const list_ptr);
int put_value();
void menu();
Node* remove_front(List* list);

int main()
{
	//po co pierwszy węzeł strat powninie być list_ptr.first = nullptr
    Node one;
    List list_ptr;
    list_ptr.first = &one;
    cout << "Podaj wartosc wezla pierwszego: ";
    one.value = put_value();
    one.next = nullptr;

    list_methods(&list_ptr);

    return 0;
}
void list_methods(List* const list_ptr){
    for(;;){
        menu();
        cout << "Wybierz dostepna opcje z menu Listy!" << endl;
        int number = put_value();
        switch(number){
        case 1:{
            Node* new_node = new Node;
            cout << "Podaj nowa wartosc: ";
            new_node->value = put_value();
            add_front(list_ptr,new_node);
        }
            break;
        case 2:
		//Po co ten cout i tak usuwasz pierwszy
            cout << "Podaj wartosc usuwanego elementu: ";
            delete remove_front(list_ptr);
            break;
        case 3:
            display(list_ptr);
            break;
        case 4:
            exit(0);
        }
    }
}
void menu(){
    cout << "\n----------------LISTA----------------" << endl;
    cout << "Wybiez jedna z dostepnych opcji" << endl << endl;
    cout << "1. Add_front" << endl;
    cout << "2. Remove_front" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
}
void display(const List * const list_ptr){
    Node* current = list_ptr->first;
    cout << endl;
    while(current != nullptr){
        cout << current->value << endl;
        current = current->next;
    }
}
void add_front(List* list, Node* new_node){
    new_node->next = list->first;
    list->first = new_node;
}
int put_value(){
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
Node* remove_front(List* list){
    Node* tmp = list->first;
    list->first = list->first->next;
    return tmp;
}
