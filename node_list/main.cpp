
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

int main()
{
    Node one;
    List first_pointer;
    first_pointer.first = &one;

    Node* ptr = &one;
    ptr->value = 1;
    ptr->next = nullptr;
    //display(first_pointer);

    Node two;
    ptr->next = &two;
    ptr = &two;
    ptr->value = 2;
    ptr->next = nullptr;
    //display(first_pointer);cout << endl;

    Node three;
    ptr->next = &three;
    ptr = &three;
    ptr->value = 3;
    ptr->next = nullptr;
    display(first_pointer);


    return 0;
}
void display(List first_pointer){
    List temp = first_pointer;
    while(temp.first != 0){
        cout << temp.first->value << endl;
        temp.first = temp.first->next;
    }
}
