#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

void show_menu();
void add(Node *ptr);
void delete_node();
void display();

int main()
{
    Node* ptr = nullptr;
    int i = 0;

    for(;;){
        show_menu();

        int number;
        cin >> number;
        switch(number){
        case 1:
            add(ptr);
            break;
        case 2:
            delete_node();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }

}
void show_menu(){
    cout << "----------------LIST----------------" << endl;
    cout << "Choose one of the available options!" << endl;
    cout << "1. Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
}
void display(){

}
void add(Node *ptr){
     ptr = new Node;
     cout << "Podaj wartosc: ";
     cin >> ptr->value;
     ptr->next = nullptr;
}
void delete_node(){

}
