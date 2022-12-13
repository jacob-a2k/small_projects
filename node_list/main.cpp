#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};
struct List{
    Node* first;
};
void display(List first_pointer);
void add_front(List* list, Node *new_node);

int main()
{
    Node one;
    List first_pointer;
    first_pointer.first = &one;
    Node* ptr = &one;
    cout << "Podaj pierwsze dane: ";
    cin >> one.value;
    one.next = nullptr;

    for(;;){
        int number;
        cin >> number;
        switch(number){
        case 1:{
            Node* new_node = new Node;
            add_front(&first_pointer,new_node);
        }
            break;
        case 2:
            display(first_pointer);
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
void display(List first_pointer){
    Node* current = first_pointer.first;
    cout << endl;
    while(current != nullptr){
        cout << current->value << endl;
        current = current->next;
    }
}
void add_front(List* list, Node* new_node){
    cout << "Podaj nowa wartosc: ";
    cin >> new_node->value;
    new_node->next = list->first;
    list->first = new_node;
}
