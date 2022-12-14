#include <iostream>
#include <limits>
#include "List.h"

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
        case 2:{
            if(!is_list_empty(list_ptr))
                delete remove_front(list_ptr);
        }
            break;
        case 3:{
            Node* new_node = new Node;
            cout << "Podaj nowa wartosc: ";
            new_node->value = put_value();
            add_back(list_ptr,new_node);
        }
            break;
        case 4:
            if(!is_list_empty(list_ptr))
                delete remove_back(list_ptr);
            break;
        case 5:
            display(list_ptr);
            break;
        case 6:
            exit(0);
        case 7:{
            Node* new_node = new Node;
            cout << "Podaj nowa warosc, a nastepnie na ktorym miejscu od gory ma sie znajdowac: ";
            new_node->value = put_value();
            int position = put_value();
            add_to_choosen_position(list_ptr,new_node,position-1);
        }
            break;
        case 8:
            if(!is_list_empty(list_ptr)){
                cout << "Podaj ktory element od gory, ma  zostac usuniety: " << endl;
                int position = put_value();
                delete remove_from_choosen_position(list_ptr,position-1);
            }
            break;
        }
    }
}
void menu(){
    cout << "\n----------------LISTA----------------" << endl;
    cout << "Wybiez jedna z dostepnych opcji" << endl << endl;
    cout << "1. Add_front" << endl;
    cout << "2. Remove_front" << endl;
    cout << "3. Add_back" << endl;
    cout << "4. Remove_back" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "7. Add_in_choosen_location" << endl;
    cout << "8. Remove from choosen location" << endl;
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
    if(list->first == nullptr){
        list->last = new_node;
    }
    new_node->next = list->first;
    list->first = new_node;
}
void add_back(List* list, Node* new_node){
    Node* tmp = list->last;
    if(list->last == nullptr && list->first == nullptr){
       list->first = new_node;
        tmp = new_node;
    }
    else{
        tmp->next = new_node;
    }
    list->last = new_node;
    new_node->next = nullptr;
}
bool is_list_empty(const List* const list_ptr){
    if(list_ptr->first == nullptr){
        cout << "Lista jest pusta!Dodaj nowy element!" << endl;
        return true;
    }
    return false;
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
    if(list->first == nullptr){
        list->last = nullptr;
    }
    return tmp;
}
Node* remove_back(List* list){
    Node* tmp = list->first;
    Node* penultimate = nullptr;
    while(tmp->next != nullptr){
        penultimate = tmp;
        tmp = tmp->next;
    }
    if(penultimate == nullptr){
        list->last = nullptr;
        list->first = nullptr;
    }
    else{
        list->last = penultimate;
        list->last->next = nullptr;
    }
    return tmp;
}
void add_to_choosen_position(List* list, Node* new_node, int position){
    if(position == 0){
        Node* tmp = list->first;
        list->first = new_node;
        new_node->next = tmp;
    }
    else{
        Node* current = list->first;
        for(int i = 1; i < position; i++){
            current = current->next;
        }
        Node* tmp = current->next;
        current->next = new_node;

        if(tmp == nullptr){
            new_node->next = nullptr;
        }
        else{
            new_node->next = tmp;
        }
    }
}
Node* remove_from_choosen_position(List* list, int position){
    if(position == 0){
        Node* tmp = list->first;
        list->first = tmp->next;
        return tmp;
    }
    else{
        Node* current = list->first;
        Node* previous = nullptr;
        for(int i = 0; i < position; i++){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        return current;
    }
}
