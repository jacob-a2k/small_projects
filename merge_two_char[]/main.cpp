#include <iostream>
#include <cstring>

using namespace std;

int string_length(const char * const input);
void string_copy(char *destination, char *source);
void merge_chars(const char * const input, const char * const input2, char * const output){
    int i = 0;
    while(input[i] != '\0'){
        output[i] = input[i];
        i++;
    }
    int k = i;
    i = 0;
    while(input2[i] != '\0'){
        output[k] = input2[i];
        i++;
        k++;
    }
    output[k] = '\0';
}

int main()
{
    char *S1 = new char[50];
    char *S2 = new char[50];
    cin >> S1;
    cin >> S2;
    int total = strlen(S1) + strlen(S2);
    char *word = new char[total+1];
    //string_copy(word,S1);
    strcat(strcpy(word,S1),S2);
    //merge_chars(S1,S2,word);
    cout << word;

    delete [] word;
    delete [] S1;
    delete [] S2;

    return 0;
}
int string_length(const char * const input){
    int i = 0;
    while(!input[i++]);
    return i;
}
void string_copy(char * const destination, const char * const source){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
