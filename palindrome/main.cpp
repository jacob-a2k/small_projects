#include <iostream>

using namespace std;

void palindrome(const char * const input, char *const output){
    int i = 0;
    while(input[i] != '\0'){
        i++;
    }
    int k = i;
    for(int j = 0; j < i; j++){
        output[j] = input[k-1];
        k--;
    }
}

int main()
{
    char *text = new char[100];
    char *word = new char[100];
    cin >> text;
    palindrome(text,word);
    cout << word;

    delete [] text;
    delete [] word;

    return 0;
}
