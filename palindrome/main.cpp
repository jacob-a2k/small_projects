#include <iostream>

using namespace std;

char *palindrome(char *text){
    int i = 0;
    char *word = new char[100];
    while(text[i] != '\0'){
        i++;
    }
    int k = i;
    for(int j = 0; j < i; j++){
        word[j] = text[k-1];
        k--;
    }
    return word;
}

int main()
{
    char *text = new char[100];
    cin >> text;
    text = palindrome(text);
    cout << text;

    return 0;
}
