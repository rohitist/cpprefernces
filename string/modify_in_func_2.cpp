#include <bits/stdc++.h>

using namespace std;
//Use case: What happens when we try to modify a constant string
void foo(char *c){
	*c = 'a';//modify first char
}

int main(){
	char s[] = "rohit"; //constant string
	foo(s);
	printf("%s", s); //Predict the Output
	return 0;
}
