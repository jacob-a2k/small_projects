#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};
struct List{
    Node* first;
    Node* last;
};
void display(const List* const list_ptr);
void add_front(List* list, Node *new_node);
void list_methods(List* const list_ptr);
int put_value();
void menu();
Node* remove_front(List* list);
bool is_list_empty(const List* const list_ptr);
void add_back(List* list, Node* new_node);
Node* remove_back(List* list);
void add_to_choosen_position(List* list, Node* new_node, int position);
Node* remove_from_choosen_position(List*  list, int position);
