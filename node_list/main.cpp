#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

int main()
{
    Node *first = nullptr;
    Node *ptr = nullptr;
    Node one,two,three,four,fifth,six;
    first = &one;
    ptr = first;
    ptr->value = 1;
    ptr->next = nullptr;

    ptr->next = &two;
    ptr = &two;
    ptr->value = 2;
    ptr->next = nullptr;

    ptr->next = &three;
    ptr = &three;
    ptr->value = 3;
    ptr->next = nullptr;

    ptr->next = &four;
    ptr = &four;
    ptr->value = 4;
    ptr->next = nullptr;

    ptr->next = &fifth;
    ptr = &fifth;
    ptr->value = 5;
    ptr->next = nullptr;

    ptr->next = &six;
    ptr = &six;
    ptr->value = 6;
    ptr->next = nullptr;

    return 0;
}

