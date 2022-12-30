#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List list_ptr;
    list_ptr.last = nullptr;
    list_ptr.first = list_ptr.last;

    list_methods(&list_ptr);

    return 0;
}
