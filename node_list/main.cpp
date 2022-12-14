#include <iostream>

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

int main()
{
    Node one;
    List list_ptr;
    list_ptr.first = &one;
    cout << "Podaj pierwsze dane: ";
    cin >> one.value;
    one.next = nullptr;

    list_methods(&list_ptr);

    return 0;
}
void list_methods(List* const list_ptr){
    for(;;){
        int number;
        cin >> number;
        switch(number){
        case 1:{
            Node* new_node = new Node;
            cout << "Podaj nowa wartosc: ";
            cin >> new_node->value;
            add_front(list_ptr,new_node);
        }
            break;
        case 2:
            display(list_ptr);
            break;
        case 3:
            exit(0);
        }
    }
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
