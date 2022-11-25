#include <iostream>

using namespace std;

char *merge_chars(char *S1,char *S2){
    char *word = new char[100];
    int i = 0;
    while(S1[i] != '\0'){
        word[i] = S1[i];
        i++;
    }
    int k = i;
    i = 0;
    while(S2[i] != '\0'){
        word[k] = S2[i];
        i++;
        k++;
    }
    word[k] = '\0';
    return word;
}

int main()
{
    char *S1 = new char[50];
    char *S2 = new char[50];
    cin >> S1;
    cin >> S2;
    cout << merge_chars(S1,S2);

    return 0;
}
