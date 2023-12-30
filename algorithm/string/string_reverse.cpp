#include <bits/stdc++.h>

void reverse(char *input, char* output){
    int j = 0;
    for(int i = strlen(input) - 1; i >=0; i--){
        output[j++] = input[i];
    }
}

int main(){
    char input[] = "This is a String";
    char* output = new char[strlen(input)]; //char* output = (char *)malloc(strlen(input)*sizeof(char));

    std::fill(output, output + strlen(output), '\0'); // alternative to memset(output, sizeof(output), '\0');
    std::copy(input, (input + strlen(input) + 1), output); //alternative to strcpy(output, input); but unlike memcpy the destination in std::copy is the last arg

    std::cout << "output: " << output << " - sizeof -> " << sizeof(output) << " - strlen ->" << strlen(output) << std::endl;
    reverse(input, output);

    std::cout << "output: " << output << " - sizeof -> " << sizeof(output) << " - strlen ->" << strlen(output) << std::endl;

    
    return 0;
}